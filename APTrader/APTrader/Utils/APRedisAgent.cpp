#include "APRedisAgent.h"
#include "APJsonReader.h"
#include <windows.h>
#include <thread>

std::string redisCfgFile = "Data/System/Redis.cfg";

APRedisAgent::APRedisAgent()
{
	m_context = NULL;
	m_over = false;
}

APRedisAgent::~APRedisAgent()
{
	if (m_context != NULL)
	{
		redisFree(m_context);
		m_context = NULL;
	}
}

void APRedisAgent::init()
{
	APJsonReader jr;
	jr.initWithFile(redisCfgFile);
	std::string ip = jr.getStrValue("IP");
	int port = jr.getIntValue("Port");
	std::string password = jr.getStrValue("Pass");
	std::string authCmd = "AUTH " + password;

	bool redisReady = false;

	m_context = redisConnect(ip.c_str(), port);
	if (m_context != NULL && m_context->err == 0) {
		redisReply* r = (redisReply*)redisCommand(m_context, authCmd.c_str());
		if (r != NULL) {
			redisReady = true;
			freeReplyObject(r);
		}
	}

	m_threadInterval = jr.getIntValue("ThreadTick");
	if (redisReady) {
		std::thread redisWriteThread(APRedisAgent::redisThreadFunc);
		redisWriteThread.detach();
	}
}

void APRedisAgent::write(std::string key, std::string value) 
{
	if (m_context == NULL) {
		return;
	}

	std::string cmd = "SET " + key + " " + value;
	redisReply* r = (redisReply*)redisCommand(m_context, cmd.c_str());
	freeReplyObject(r);
}

void APRedisAgent::writeAsync(std::string key, std::string value) 
{
	std::string cmd = "SET " + key + " " + value;
	m_commandBuffer.push(cmd.c_str());
}

std::string APRedisAgent::read(std::string key) {
	if (m_context == NULL) {
		return "";
	}

	std::string cmd = "GET " + key;
	redisReply* r = (redisReply*)redisCommand(m_context, cmd.c_str());
	std::string ret = "";
	if (r->type == REDIS_REPLY_STRING) {
		ret = r->str;
	}

	freeReplyObject(r);
	return ret;
}

void APRedisAgent::exit()
{
}

void APRedisAgent::redisThreadFunc()
{
	APRedisAgent::getInstance()->processWriteCmd();
}

void APRedisAgent::processWriteCmd()
{
	while (!m_over) {
		long beginTime = GetTickCount();
		while (m_commandBuffer.size() > 0) {
			std::string cmd = "";
			bool ret = m_commandBuffer.try_pop(cmd);
			if (!ret) {
				continue;
			}
			redisReply* r = (redisReply*)redisCommand(m_context, cmd.c_str());
			freeReplyObject(r);
		}
		
		long deltaTime = GetTickCount() - beginTime;
		if (m_threadInterval > deltaTime) {
			Sleep(m_threadInterval - deltaTime);
		}
		else
		{
			Sleep(300);
		}
	}
}

bool APRedisAgent::isOver()
{
	return m_over;
}
#include "APMonitorFramework.h"
#include "../APMacro.h"
#include "../Utils/APLog.h"

#ifdef USE_CTP
#include "../Impl/CTP/APFuturesCTPMDAgent.h"
#endif

#include "../APMarketDataManager.h"
#include "APQuotationMonitorManager.h"
#include "../APGlobalConfig.h"

void onRemoteSystemInited() {
	APMonitorFramework::getInstance()->onRemoteInited();
}

APMonitorFramework::APMonitorFramework()
{
	//m_inited = false;
}


APMonitorFramework::~APMonitorFramework()
{
}

void APMonitorFramework::init()
{
	m_inited = false;

	initRemoteSystem();
}

void APMonitorFramework::update()
{
	APMarketDataMgr->update();
	APQuotationMonitorManager::getInstance()->update();
}

void APMonitorFramework::exit()
{
#ifdef USE_CTP
	//APFuturesCTPMDAgent::getInstance()->
#endif // USE_CTP

	APQuotationMonitorManager::getInstance()->destroy();

	m_exited = true;
}

void APMonitorFramework::initRemoteSystem()
{
#ifdef USE_CTP
	APFuturesCTPMDAgent::getInstance()->registerInitCallback(onRemoteSystemInited);
	APFuturesCTPMDAgent::getInstance()->init();
#endif // USE_CTP

}

void APMonitorFramework::onRemoteInited()
{
#ifdef USE_CTP
	APLogger->log("---- CTP inited ----");
#endif
	initLocalSystem();
}

void APMonitorFramework::initLocalSystem()
{
	APGlobalConfig::getInstance()->init();
	APMarketDataMgr->init();
	APQuotationMonitorManager::getInstance()->init();
	onLocalInited();
}

void APMonitorFramework::onLocalInited()
{
	APLogger->log("---- Local system inited ----");
	setInited();
}

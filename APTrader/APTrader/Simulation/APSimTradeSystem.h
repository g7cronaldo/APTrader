#pragma once
#include "../Common/Singleton.h"
#include <string>
#include <list>
#include "../APDef.h"
#include <map>
#include "APSimFuturesTrade.h"
#include <deque>

class APIntAccumulator;
class APSimFuturesQuotation;

struct APSimTradeStub {
	UINT tradeID;
	APASSETID instrumentID;
	APTradeDirection direction;
	double costPrice;
	long volume;
	APORDERID orderID;
};

class APSimTradeSystem : public Singleton<APSimTradeSystem>
{
public:
	APSimTradeSystem();
	~APSimTradeSystem();

	APSYSTEMID requestOpen(APORDERID orderID, APASSETID instrumentID, APTradeDirection direction, double price, long volume);
	APSYSTEMID requestClose(APORDERID orderID, APASSETID instrumentID, APTradeDirection direction, double price, long volume);
	void requestCancel(APSYSTEMID sysID);

	void init();
	void update();

	double calcFloatingProfit();

protected:
	void onTradeDealt(APORDERID orderID, APASSETID instrumentID, APTradeType type, double price, long volume, APSYSTEMID sysID, APTradeDirection direction);
	void onTradeCanceled(APORDERID orderID, APSYSTEMID sysID);
	bool arrangeTrade(APTradeOrderInfo& order);
	void closeTheDeal(APORDERID orderID, APASSETID instrumentID, APTradeType type, double price, long volume, APSYSTEMID sysID, APTradeDirection direction);
	double calcProfitAndLoss(double costPrice, double currentPrice, long volume, APTradeDirection direction);

private:
	void validQuotation(APASSETID instrumentID);
	double calcFloatingProfit(APSimTradeStub& tradeStub);

protected:
	APIntAccumulator* m_orderIDAccumulator;
	APIntAccumulator* m_tradeIDAccumulator;
	std::list<APTradeOrderInfo> m_orderList;
	std::map<APASSETID, APSimFuturesQuotation*> m_quotations;
	APSimFuturesTrade* m_trade;
	//std::queue<APSimTradeStub> m_tradeStubs;
	std::map<APASSETID, std::deque<APSimTradeStub>> m_tradeLongStubs;
	std::map<APASSETID, std::deque<APSimTradeStub>> m_tradeShortStubs;
};


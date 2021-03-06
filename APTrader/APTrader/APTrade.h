#pragma once
#include "APDef.h"
//#include "APPositionCtrl.h"
#include <string>
#include <map>
#include <vector>
#include <list>
#include "APTypes.h"
#include <set>
//#include "Utils/APRedisSerializedObject.h"
#include "APStructs.h"
#include "Common/InitializableObject.h"

//#define INVALID_ORDER_ID 0
//#define MATCH_ANY_ORDER_ID 0xFEEEFEEE

//class APPositionCtrl;
class APTradeObserver;
class APIntAccumulator;

class APTrade : public InitializableObject //: public APRedisSerializedObject
{
public:
	APTrade();
	~APTrade();

public:
	virtual APORDERID open(APASSETID instrumentID, APTradeDirection direction, double price, long volume, 
							APTradeObserver* ob, APOrderTimeCondition ot = OTC_GoodForDay);
	virtual APORDERID close(APASSETID instrumentID, APTradeDirection direction, double price, long volume, 
							APTradeObserver* ob, APOrderTimeCondition ot = OTC_GoodForDay);

	virtual APORDERID open(APASSETID instrumentID, APTradeDirection direction,
							APOrderPriceType orderPriceType, double price, APTradeObserver* ob,
							APOrderTimeCondition orderTimeCondition = OTC_GoodForDay, std::string date = "",
							APOrderVolumeCondition orderVolumeCondition = OVC_Any, long volume = 0, long minVolume = 0,
							APOrderContingentCondition orderContingentCondition = OCC_Immediately, double stopPrice = 0.0);
	virtual APORDERID close(APASSETID instrumentID, APTradeDirection direction,
							APOrderPriceType orderPriceType, double price, APTradeObserver* ob,
							APOrderTimeCondition orderTimeCondition = OTC_GoodForDay, std::string date = "",
							APOrderVolumeCondition orderVolumeCondition = OVC_Any, long volume = 0, long minVolume = 0,
							APOrderContingentCondition orderContingentCondition = OCC_Immediately, double stopPrice = 0.0);

	virtual void cancel(APASSETID instrumentID, APTradeType type, APTradeDirection direction, double price, APTradeObserver* ob);
	virtual void cancel(APASSETID instrumentID, APTradeType type, APTradeObserver* ob);
	virtual void cancelAll(APASSETID instrumentID, APTradeObserver* ob);
	virtual void cancel(APORDERID orderID, APTradeObserver* ob);
	
	virtual void onTraded(APASSETID instrumentID, APTradeType type, double price, long volume, APORDERID orderID, APTradeDirection direction = TD_Buy);
	virtual void onOrderStatusChanged(APASSETID instrumentID, APTradeType type, APORDERID orderID, long volumeSurplus, long volumeTraded,
								APOrderState state, APSYSTEMID sysID, APSYSTEMID orderRef = "", APSYSTEMID exchangeID = "",
								int sessionID = 0, int frontID = 0, APTradeDirection direction = TD_Buy);
	virtual void onCanceled(APORDERID orderID);
	virtual void onFailed(APORDERID orderID);

	virtual void onFundChanged(APASSETID instrumentID, APTradeType type, double variableFund, APORDERID orderID, APTradeDirection direction = TD_Buy);

	bool getOrderInfo(APORDERID orderID, APTradeOrderInfo& orderInfo);

	void setOrderIDBase(UINT base);

	// sync orders
	void queryAllOrders();
	void bindOrder(APORDERID localOrderID, APTradeObserver* ob);
	void queryOrder(APORDERID localOrderID);
	void onQueryOrder(APORDERID localOrderID);
	void onQueryOrderFailed(APORDERID localOrderID);

	void onSyncOrders();

	void removeLocalOrders();
	//bool isOrderDataComplete();
	virtual void init();

protected:
	virtual void open(APORDERID orderID, APASSETID instrumentID, APTradeDirection direction, double price, long volume, 
						APOrderTimeCondition ot = OTC_GoodForDay) = 0;
	virtual long close(APORDERID orderID, APASSETID instrumentID, APTradeDirection direction, double price, long volume,
						APOrderTimeCondition ot = OTC_GoodForDay) = 0;
	virtual void cancel(APORDERID orderID) = 0;

	virtual void open(APASSETID instrumentID, APORDERID localOrderID, APTradeDirection direction,
						APOrderPriceType orderPriceType, double price,
						APOrderTimeCondition orderTimeCondition = OTC_GoodForDay, std::string date = "",
						APOrderVolumeCondition orderVolumeCondition = OVC_Any, long volume = 0, long minVolume = 0,
						APOrderContingentCondition orderContingentCondition = OCC_Immediately, double stopPrice = 0.0) = 0;
	virtual void close(APASSETID instrumentID, APORDERID localOrderID, APTradeDirection direction,
						APOrderPriceType orderPriceType, double price,
						APOrderTimeCondition orderTimeCondition = OTC_GoodForDay, std::string date = "",
						APOrderVolumeCondition orderVolumeCondition = OVC_Any, long volume = 0, long minVolume = 0,
						APOrderContingentCondition orderContingentCondition = OCC_Immediately, double stopPrice = 0.0) = 0;
	

	APORDERID generateOrderID();
	void removeLocalOrder(APORDERID orderID);


	bool isOrderExists(APORDERID orderID);
	APASSETID getInstrumentIDByOrderID(APORDERID orderID);
	APSYSTEMID getSysIDByOrderID(APORDERID orderID);	
	APSYSTEMID getOrderRefByOrderID(APORDERID orderID);
	int getSessionIDByOrderID(APORDERID orderID);
	int getFrontIDByOrderID(APORDERID orderID);
	APSYSTEMID getExchangeIDByOrderID(APORDERID orderID);

	APORDERID initializeLocalOrder(APASSETID instrumentID, APTradeType type, APTradeDirection direction, double price, long volume, APTradeObserver* ob);

	//// serialize
	//virtual std::string serialize();
	//virtual void deserialize(std::string str);
	//virtual std::string generateRedisKey();
	//APOrderRecordInfo convertOrderInfo(APTradeOrderInfo& info);

private:
	std::vector<APORDERID> getRelatedOrders(APTradeObserver* ob);
	APTradeObserver* getObserverByOrder(APORDERID orderID);

	void saveOrderAccumID(UINT accumID);

protected:
	std::map<APORDERID, APTradeOrderInfo> m_localOrders;

	APIntAccumulator* m_idAccumulator;
	APORDERID m_baseID;
	
	std::map<UINT, APTradeObserver*> m_tradeObservers;
//private:
//	std::map<APORDERID, APOrderRecordInfo> m_orderRecordInfo;
};


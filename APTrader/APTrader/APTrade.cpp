#include "APTrade.h"
#include "APPositionCtrl.h"
#include "APPositionManager.h"

APTrade::APTrade()
{
}

APTrade::~APTrade()
{
}

void APTrade::open(APASSETID commodityID, APTrendType trend, double price, long amount, APPositionCtrl* pc, APTradeOrderType ot) {
	if (pc == NULL) {
		return;
	}

	if (ot == TOT_ValidTheDay) {
		APTradeOrderPositionInfo info = { UNDISTURBED_ORDER_ID, TDT_Open, commodityID, price, amount, trend, pc->getID()};
		m_ordersApplied.push_back(info);
	}
	else {
		APTradeOrderPositionInfo info = { MATCH_ANY_ORDER_ID, TDT_Open, commodityID, price, amount, trend, pc->getID() };
		m_quickDealOrders.push_back(info);
	}
	

	open(commodityID, trend, price, amount, ot);
}

void APTrade::close(APASSETID commodityID, APTrendType trend, double price, long amount, APPositionCtrl* pc, APTradeOrderType ot) {
	if (pc == NULL) {
		return;
	}

	if (ot == TOT_ValidTheDay) {
		APTradeOrderPositionInfo info = { UNDISTURBED_ORDER_ID, TDT_Close, commodityID, price, amount, trend, pc->getID() };
		m_ordersApplied.push_back(info);
	}
	else {
		APTradeOrderPositionInfo info = { MATCH_ANY_ORDER_ID, TDT_Close, commodityID, price, amount, trend, pc->getID() };
		m_quickDealOrders.push_back(info);
	}
	

	close(commodityID, trend, price, amount, ot);
}

void APTrade::cancel(APASSETID commodityID, APTradeType type, APTrendType trend, double price, long amount, APPositionCtrl* pc) {
	if (pc == NULL) {
		return;
	}

	APORDERID orderID = UNDISTURBED_ORDER_ID;
	std::list<APTradeOrderPositionInfo>::iterator it;
	for (it = m_ordersApplied.begin(); it != m_ordersApplied.end(); it++) {
		APTradeOrderPositionInfo& info = *it;
		if (info.orderInfo.commodityID == commodityID &&
			info.orderInfo.type == type &&
			fabs(info.orderInfo.price - price) < DBL_EPSILON &&
			info.orderInfo.amount == amount &&
			info.orderInfo.trend == trend) {
			orderID = info.orderInfo.orderID;
			break;
		}
	}

	if (orderID != UNDISTURBED_ORDER_ID){
		cancel(orderID);
	}
}


void APTrade::onTradeFinished(APASSETID commodityID, APTradeType type, double price, long amount, APORDERID orderID, APTrendType trend)
{
	//if (m_positionData.find(commodityID) != m_positionData.end()) {
	//	//std::vector<APTradePositionData>& data = m_positionData[commodityID];
	//	//int i = 0;
	//	//for (; i < data.size(); i++) {
	//	//	data[i].positionCtrl->onTradeFinished(commodityID, type, price, amount, trend);
	//	//}
	//}
	if (m_orderPosCtrlRelation.find(orderID) != m_orderPosCtrlRelation.end() &&
		m_ordersSubmitted.find(orderID) != m_ordersSubmitted.end()) {
		UINT posCtrlID = m_orderPosCtrlRelation[orderID];
		APPositionCtrl* posCtrl = APPositionManager::getInstance()->getPositionCtrl(posCtrlID);
		if (posCtrl != NULL) {
			posCtrl->onTradeFinished(commodityID, type, price, amount, trend);
		}

		// 
		APTradeOrderInfo& orderInfo = m_ordersSubmitted[orderID];
		if (orderInfo.amount >= amount) {
			orderInfo.amount -= amount;
		}
		else {
			// error
			return;
		}

		if (orderInfo.amount == 0) {
			//trade fully finished
			m_orderPosCtrlRelation.erase(orderID);
			m_ordersSubmitted.erase(orderID);
		}
		else {
			return;
		}
	}
	else {
		std::list<APTradeOrderPositionInfo>::iterator it;
		for (it = m_quickDealOrders.begin(); it != m_quickDealOrders.end(); it++) {
			APTradeOrderPositionInfo& info = *it;
			if (info.orderInfo.commodityID == commodityID &&
				fabs(info.orderInfo.price - price) < DBL_EPSILON &&
				info.orderInfo.trend == trend &&
				info.orderInfo.type == type) {				
				UINT posCtrlID = info.positionCtrlID;
				APPositionCtrl* posCtrl = APPositionManager::getInstance()->getPositionCtrl(posCtrlID);
				if (posCtrl != NULL) {
					posCtrl->onTradeFinished(commodityID, type, price, amount, trend);
				}
			}
		}
	}
}

void APTrade::onTradeOrdered(APASSETID commodityID, APTradeType type, double price, long amount, APORDERID orderID, APTrendType trend) {
	std::list<APTradeOrderPositionInfo>::iterator it;
	for (it = m_ordersApplied.begin(); it != m_ordersApplied.end(); it++) {
		APTradeOrderPositionInfo& info = *it;
		if (info.orderInfo.commodityID == commodityID && 
			info.orderInfo.type == type &&
			fabs(info.orderInfo.price - price) < DBL_EPSILON && 
			info.orderInfo.amount == amount &&
			info.orderInfo.trend == trend &&
			info.orderInfo.orderID == UNDISTURBED_ORDER_ID) {
			info.orderInfo.orderID = orderID;
			m_ordersSubmitted[orderID] = info.orderInfo;
			m_orderPosCtrlRelation[orderID] = info.positionCtrlID;
			m_ordersApplied.erase(it);
			break;
		}
	}
}

void APTrade::onFundChanged(APASSETID commodityID, APTradeType type, double variableFund, APORDERID orderID, APTrendType trend) {
	//
}

//void APTrade::setPositionCtrl(APPositionCtrl * positionCtrl)
//{
//	m_positionCtrl = positionCtrl;
//}

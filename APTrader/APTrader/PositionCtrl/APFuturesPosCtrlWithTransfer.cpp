#include "APFuturesPosCtrlWithTransfer.h"
#include <algorithm>


APFuturesPosCtrlWithTransfer::APFuturesPosCtrlWithTransfer()
{
}


APFuturesPosCtrlWithTransfer::~APFuturesPosCtrlWithTransfer()
{
}

void APFuturesPosCtrlWithTransfer::init(std::string positionInfo)
{
	APFuturesPositionCtrl::init(positionInfo);
}

void APFuturesPosCtrlWithTransfer::setTargetContractID(APASSETID contractID)
{
	m_targetContractID = contractID;
}

void APFuturesPosCtrlWithTransfer::onTradeDealt(APASSETID instrumentID, APTradeType type,  double price, long deltaVolume, APORDERID orderID, APTrendType trend)
{
	if (instrumentID != m_instrumentID || instrumentID != m_targetContractID || type != m_trendType) {
		return;
	}	

	if (m_isTransferring && !m_finishTransferring && type == TDT_Open) {
		if (instrumentID == m_instrumentID) {
			m_holdPosition += deltaVolume;
		}
		else {
			m_targetContractHoldPosition += deltaVolume;
		}
		m_openOrdersPosition -= deltaVolume;
	}
	else {
		APFuturesPositionCtrl::onTradeDealt(instrumentID, type, price, deltaVolume, orderID, trend);
	}

	if (!m_finishTransferring) {
		checkTransferStatus();
	}
}

void APFuturesPosCtrlWithTransfer::open(APTrendType type, double price, long volume)
{
	if (m_isTransferring) {
		APFuturesPositionCtrl::open(m_targetContractID, type, price, volume);
		return;
	}

	APFuturesPositionCtrl::open(type, price, volume);
}

void APFuturesPosCtrlWithTransfer::close(APTrendType type, double price, long volume)
{
	if (m_isTransferring) {
		long srcContractVolume = std::min(volume, m_holdPosition - m_closeOrdersPosition);
		APFuturesPositionCtrl::close(type, price, srcContractVolume);
		if (volume > m_holdPosition - m_closeOrdersPosition) {
			long volumeSurplus = volume - (m_holdPosition - m_closeOrdersPosition);
			APFuturesPositionCtrl::close(m_targetContractID, type, price, volumeSurplus);
		}
		return;
	}

	APFuturesPositionCtrl::close(type, price, volume);
}

void APFuturesPosCtrlWithTransfer::beginTransfer()
{
	m_isTransferring = true;
	m_positonNeedTransfer = m_holdPosition;
}

bool APFuturesPosCtrlWithTransfer::isTransferring()
{
	return m_isTransferring;
}

bool APFuturesPosCtrlWithTransfer::isTransferFinished()
{
	return m_finishTransferring;
}

void APFuturesPosCtrlWithTransfer::transferContracts(double droppedContractPrice, double targetContractPrice, long volume)
{
	long realVolume = std::min(volume, m_holdPosition - m_closeOrdersPosition);
	//fak may has mistakes
	APFuturesPositionCtrl::close(m_instrumentID, m_trendType, droppedContractPrice, realVolume);
	realVolume = std::min(realVolume, m_positonNeedTransfer - m_targetContractHoldPosition);
	if (realVolume > 0) {
		APFuturesPositionCtrl::open(m_targetContractID, m_trendType, targetContractPrice, realVolume);
	}
}

void APFuturesPosCtrlWithTransfer::checkTransferStatus()
{
	if (m_isTransferring) {
		if (m_holdPosition == 0 && m_targetContractHoldPosition >= m_positonNeedTransfer) {
			m_finishTransferring = true;
		}
	}
}

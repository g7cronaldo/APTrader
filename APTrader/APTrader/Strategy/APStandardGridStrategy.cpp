#include "APStandardGridStrategy.h"
#include "../Utils/APJsonReader.h"


APStandardGridStrategy::APStandardGridStrategy()
{
}


APStandardGridStrategy::~APStandardGridStrategy()
{
}

APStrategy * APStandardGridStrategy::create()
{
	return new APStandardGridStrategy();
}

void APStandardGridStrategy::buildGrids(std::string gridsInfo)
{
	APJsonReader jr;
	jr.initWithString(gridsInfo);
	std::string strTrend = jr.getStrValue("Trend");
	if (strTrend == "Long") {
		m_trend = TT_Long;
	}
	else if (strTrend == "Short") {
		m_trend = TT_Short;
	}

	m_waitCeil = jr.getDoubleValue("Ceil");
	m_waitFloor = jr.getDoubleValue("Floor");
	m_gridPercent = jr.getDoubleValue("GridPercent");
	m_pricePercent = jr.getDoubleValue("PricePercent");
	m_gridPosition = jr.getIntValue("GridPosition");
	m_basePosition = jr.getIntValue("BasePosition");
	m_gridsCount = jr.getIntValue("GridsCount");
	m_longPrice = jr.getDoubleValue("LongPrice");
	m_shortPrice = jr.getDoubleValue("ShortPrice");

	resetGrids();
}

void APStandardGridStrategy::resetGrids()
{
	m_openGrids.clear();
	m_closeGrids.clear();

	if (m_trend == TT_Long) {
		buildLongGrids();
	}
	else if (m_trend == TT_Short) {
		buildShortGrids();
	}
}

void APStandardGridStrategy::buildLongGrids()
{
	APGridData data = {m_waitFloor, m_shortPrice, m_basePosition};
	m_openGrids.push_back(data);
	for (int i = 1; i < m_gridsCount; i++) {
		APGridData gd = { m_openGrids[i - 1].valueRef * (1 - m_gridPercent),
							m_openGrids[i - 1].price * (1 - m_pricePercent),
							m_openGrids[i - 1].position + m_gridPosition };
		m_openGrids.push_back(gd);
	}

	data = { m_waitCeil, m_longPrice, m_gridPosition };
	m_closeGrids.push_back(data);
	for (int i = 1; i < m_gridsCount; i++) {
		APGridData gd = { m_closeGrids[i - 1].valueRef * (1 + m_gridPercent),
							m_closeGrids[i - 1].price * (1 + m_pricePercent),
							m_gridPosition };
		m_closeGrids.push_back(gd);
	}
}

void APStandardGridStrategy::buildShortGrids()
{
	APGridData data = { m_waitFloor, m_shortPrice, m_gridPosition };
	m_closeGrids.push_back(data);
	for (int i = 1; i < m_gridsCount; i++) {
		APGridData gd = { m_closeGrids[i - 1].valueRef * (1 - m_gridPercent),
							m_closeGrids[i - 1].price * (1 - m_pricePercent),
							m_gridPosition };
		m_closeGrids.push_back(gd);
	}

	data = { m_waitCeil, m_longPrice, m_basePosition };
	m_openGrids.push_back(data);
	for (int i = 1; i < m_gridsCount; i++) {
		APGridData gd = { m_openGrids[i - 1].valueRef * (1 + m_gridPercent),
							m_openGrids[i - 1].price * (1 + m_pricePercent),
							m_openGrids[i - 1].position + m_gridPosition };
		m_openGrids.push_back(gd);
	}
}


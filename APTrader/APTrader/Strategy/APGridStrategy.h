#pragma once
#include "../APStrategy.h"
#include "../APDef.h"
#include <vector>

class APPositionCtrl;
class APCommodityQuotation;

struct APGridData {
	double valueRef;
	double price;
	long position;

	//APGridData(double theValueRef, double thePrice, long thePosition) {
	//	valueRef = theValueRef;
	//	price = thePrice;
	//	position = thePosition;
	//}
};

class APGridStrategy : public APStrategy 
{
public:
	APGridStrategy();
	~APGridStrategy();

	virtual void init(std::string strategyInfo);
	virtual void update();
	virtual void alert();

	//test function
	void printGrids();

protected:
	virtual void buildGrids(std::string gridsInfo) = 0;
	virtual void resetGrids() = 0;

	int getGridIndex(std::vector<APGridData>& grids, double value, bool reverse = false);

	int getCurTrendGridIndex(std::vector<APGridData>& grids, double value, bool open);

	void goTrendGrid(double curPrice);// , std::vector<APGridData>& openGrids, std::vector<APGridData>& closeGrids);

	bool inOpenSection(double value);
	bool inCloseSection(double value);

	void goThroughGrids();

protected:
	APTrendType m_trend;
	
	//APASSETID m_commodityID;

	std::vector<APGridData> m_openGrids;
	std::vector<APGridData> m_closeGrids;

	double m_waitFloor;
	double m_waitCeil;

	int m_curIndex;
	int m_lastIndex;
};
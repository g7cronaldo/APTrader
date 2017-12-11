#pragma once
enum APTrendType {
	TT_Long,
	TT_Short,
	TT_Sideway,
	//TT_Suspend,
	TT_Num
};

enum APFinancialInstrumentType {
	FCT_Shares,
	FCT_Futrues,
	FCT_Options,
	FCT_Num
};

enum APTradeType {
	TDT_Open,
	TDT_Close,
	TDT_CancelOpen,
	TDT_CancelClose,
	TDT_Lock, // lock position, only for futures
	TDT_Num
};

enum APRecycleFundLevel {
	RFL_FreeFund,
	RFL_UnsealedOrder,
	RFL_ProfitPosition,
	RFL_UndeficitPosition,
	RFL_All,
	RFL_Num
};

enum APQuotationDecisionType {
	QDT_Single = 1,
	QDT_PriceMargin,
	QDT_PriceRatio,
	//Sim
	QDT_SimSingle = 101,
	QDT_Num
};

enum APRunMode {
	RM_Trade,
	RM_Backtest,
	RM_Num
};

enum APOpenPositionLimit {
	OPL_Fund,
	OPL_Position,
	OPL_Num
};

enum APTradeOrderType {
	TOT_ValidTheDay,
	TOT_FAK,
	TOT_FOK,
	TOT_Num,
};

enum APTradeState {
	TS_Apply,
	TS_Ordered,
	TS_New,
	TS_PartiallyFilled,
	TS_Filled,
	TS_None,
	TS_Num
};

const unsigned int INVALID_TRADE_ORDER_ID = 0;
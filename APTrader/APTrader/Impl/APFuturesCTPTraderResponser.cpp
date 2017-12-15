#include "APFuturesCTPTraderResponser.h"
#include "APFuturesCTPMDAgent.h"

APFuturesCTPTraderResponser::APFuturesCTPTraderResponser()
{

}

APFuturesCTPTraderResponser::~APFuturesCTPTraderResponser()
{
}

void APFuturesCTPTraderResponser::OnFrontConnected()
{
	// todo: trader system inited
	// login
	APFuturesCTPMDAgent::getInstance()->login();
}

void APFuturesCTPTraderResponser::OnFrontDisconnected(int nReason)
{
	// todo: retry
}

void APFuturesCTPTraderResponser::OnHeartBeatWarning(int nTimeLapse)
{
	// invalid now
}

void APFuturesCTPTraderResponser::OnRspAuthenticate(CThostFtdcRspAuthenticateField * pRspAuthenticateField, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	// on login
	APFuturesCTPMDAgent::getInstance()->onLogin();
}

void APFuturesCTPTraderResponser::OnRspUserLogout(CThostFtdcUserLogoutField * pUserLogout, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField * pUserPasswordUpdate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField * pTradingAccountPasswordUpdate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspOrderInsert(CThostFtdcInputOrderField * pInputOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	//
}

void APFuturesCTPTraderResponser::OnRspParkedOrderInsert(CThostFtdcParkedOrderField * pParkedOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField * pParkedOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspOrderAction(CThostFtdcInputOrderActionField * pInputOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField * pQueryMaxOrderVolume, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField * pRemoveParkedOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField * pRemoveParkedOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspExecOrderInsert(CThostFtdcInputExecOrderField * pInputExecOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField * pInputExecOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspForQuoteInsert(CThostFtdcInputForQuoteField * pInputForQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQuoteInsert(CThostFtdcInputQuoteField * pInputQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQuoteAction(CThostFtdcInputQuoteActionField * pInputQuoteAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField * pInputBatchOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField * pInputOptionSelfCloseAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspCombActionInsert(CThostFtdcInputCombActionField * pInputCombAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryOrder(CThostFtdcOrderField * pOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryTrade(CThostFtdcTradeField * pTrade, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField * pInvestorPosition, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryTradingAccount(CThostFtdcTradingAccountField * pTradingAccount, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInvestor(CThostFtdcInvestorField * pInvestor, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryTradingCode(CThostFtdcTradingCodeField * pTradingCode, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField * pInstrumentMarginRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField * pInstrumentCommissionRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryExchange(CThostFtdcExchangeField * pExchange, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryProduct(CThostFtdcProductField * pProduct, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInstrument(CThostFtdcInstrumentField * pInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	//
}

void APFuturesCTPTraderResponser::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketData, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	//
}

void APFuturesCTPTraderResponser::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField * pSettlementInfo, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryTransferBank(CThostFtdcTransferBankField * pTransferBank, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField * pInvestorPositionDetail, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryNotice(CThostFtdcNoticeField * pNotice, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField * pSettlementInfoConfirm, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField * pInvestorPositionCombineDetail, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField * pCFMMCTradingAccountKey, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField * pEWarrantOffset, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField * pInvestorProductGroupMargin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField * pExchangeMarginRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField * pExchangeMarginRateAdjust, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryExchangeRate(CThostFtdcExchangeRateField * pExchangeRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField * pSecAgentACIDMap, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryProductExchRate(CThostFtdcProductExchRateField * pProductExchRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryProductGroup(CThostFtdcProductGroupField * pProductGroup, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField * pMMInstrumentCommissionRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField * pMMOptionInstrCommRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField * pInstrumentOrderCommRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQrySecAgentTradingAccount(CThostFtdcTradingAccountField * pTradingAccount, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQrySecAgentCheckMode(CThostFtdcSecAgentCheckModeField * pSecAgentCheckMode, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField * pOptionInstrTradeCost, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField * pOptionInstrCommRate, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryExecOrder(CThostFtdcExecOrderField * pExecOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryForQuote(CThostFtdcForQuoteField * pForQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryQuote(CThostFtdcQuoteField * pQuote, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField * pOptionSelfClose, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryInvestUnit(CThostFtdcInvestUnitField * pInvestUnit, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField * pCombInstrumentGuard, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryCombAction(CThostFtdcCombActionField * pCombAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryTransferSerial(CThostFtdcTransferSerialField * pTransferSerial, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryAccountregister(CThostFtdcAccountregisterField * pAccountregister, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspError(CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	// todo: req error
}

void APFuturesCTPTraderResponser::OnRtnOrder(CThostFtdcOrderField * pOrder)
{
}

void APFuturesCTPTraderResponser::OnRtnTrade(CThostFtdcTradeField * pTrade)
{
}

void APFuturesCTPTraderResponser::OnErrRtnOrderInsert(CThostFtdcInputOrderField * pInputOrder, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnOrderAction(CThostFtdcOrderActionField * pOrderAction, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField * pInstrumentStatus)
{
}

void APFuturesCTPTraderResponser::OnRtnBulletin(CThostFtdcBulletinField * pBulletin)
{
}

void APFuturesCTPTraderResponser::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField * pTradingNoticeInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField * pErrorConditionalOrder)
{
}

void APFuturesCTPTraderResponser::OnRtnExecOrder(CThostFtdcExecOrderField * pExecOrder)
{
}

void APFuturesCTPTraderResponser::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField * pInputExecOrder, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField * pExecOrderAction, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField * pInputForQuote, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnQuote(CThostFtdcQuoteField * pQuote)
{
}

void APFuturesCTPTraderResponser::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField * pInputQuote, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnQuoteAction(CThostFtdcQuoteActionField * pQuoteAction, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField * pForQuoteRsp)
{
}

void APFuturesCTPTraderResponser::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField * pCFMMCTradingAccountToken)
{
}

void APFuturesCTPTraderResponser::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField * pBatchOrderAction, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField * pOptionSelfClose)
{
}

void APFuturesCTPTraderResponser::OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField * pInputOptionSelfClose, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField * pOptionSelfCloseAction, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnCombAction(CThostFtdcCombActionField * pCombAction)
{
}

void APFuturesCTPTraderResponser::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField * pInputCombAction, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRspQryContractBank(CThostFtdcContractBankField * pContractBank, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryParkedOrder(CThostFtdcParkedOrderField * pParkedOrder, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField * pParkedOrderAction, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryTradingNotice(CThostFtdcTradingNoticeField * pTradingNotice, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField * pBrokerTradingParams, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField * pBrokerTradingAlgos, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField * pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField * pRspTransfer)
{
}

void APFuturesCTPTraderResponser::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField * pRspTransfer)
{
}

void APFuturesCTPTraderResponser::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField * pRspRepeal)
{
}

void APFuturesCTPTraderResponser::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField * pRspRepeal)
{
}

void APFuturesCTPTraderResponser::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField * pRspTransfer)
{
}

void APFuturesCTPTraderResponser::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField * pRspTransfer)
{
}

void APFuturesCTPTraderResponser::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField * pRspRepeal)
{
}

void APFuturesCTPTraderResponser::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField * pRspRepeal)
{
}

void APFuturesCTPTraderResponser::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField * pNotifyQueryAccount)
{
}

void APFuturesCTPTraderResponser::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField * pReqRepeal, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField * pReqRepeal, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField * pReqQueryAccount, CThostFtdcRspInfoField * pRspInfo)
{
}

void APFuturesCTPTraderResponser::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField * pRspRepeal)
{
}

void APFuturesCTPTraderResponser::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField * pRspRepeal)
{
}

void APFuturesCTPTraderResponser::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField * pReqTransfer, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField * pReqQueryAccount, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
}

void APFuturesCTPTraderResponser::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField * pOpenAccount)
{
}

void APFuturesCTPTraderResponser::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField * pCancelAccount)
{
}

void APFuturesCTPTraderResponser::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField * pChangeAccount)
{
}
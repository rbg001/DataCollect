
#include "QCTPMdSpi.h"
#include <string>
#include<iostream>
#include "ctp_api/ThostFtdcUserApiDataType.h"
#include "ctp_api/ThostFtdcUserApiStruct.h"
#include "ctp_api/ThostFtdcMdApi.h"
#include "ctp_api/ThostFtdcTraderApi.h"
using namespace std;
QCTPMdSpi::QCTPMdSpi(CThostFtdcMdApi* api): pUserApi(api)
{
}
QCTPMdSpi::QCTPMdSpi()
{
}
int requestId = 0;
void QCTPMdSpi::OnFrontConnected()
{
	

	cout << "OnFrontConnected success"<<endl;
	CThostFtdcReqUserLoginField loginReq;
	memset(&loginReq, 0, sizeof(loginReq));
	strcpy_s(loginReq.BrokerID, BrokerID);
	strcpy_s(loginReq.UserID, UserID);
	strcpy_s(loginReq.Password, Password);

	int ret = pUserApi->ReqUserLogin(&loginReq, ++requestId);
	cout << "longin result :" << ret << endl;

}



void QCTPMdSpi::OnFrontDisconnected(int nReason)
{
	cout << "OnFrontDisconnected";
}

void QCTPMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cout << "OnHeartBeatWarning";
}


void QCTPMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField * pRspUserLogin, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	
	
	
	int ret = pUserApi->SubscribeMarketData(codeList, code_size);
}

void QCTPMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField * pUserLogout, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspUserLogout";
}

void QCTPMdSpi::OnRspError(CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspError";
}

void QCTPMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspSubMarketData";
}

void QCTPMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspUnSubMarketData";
}

void QCTPMdSpi::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
cout << "OnRspSubForQuoteRsp";
}

void QCTPMdSpi::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField * pSpecificInstrument, CThostFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
{
	cout << "OnRspUnSubForQuoteRsp";
}

void QCTPMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField * pDepthMarketData)
{
	cout << "InstrumentID:" << pDepthMarketData->InstrumentID << "||SettlementPrice:" << pDepthMarketData->SettlementPrice << "||UpdateMillisec:" << pDepthMarketData->UpdateMillisec << "||×îÐÂ¼Û:" << pDepthMarketData->LastPrice << endl;

	//mysql_insert->InsertDepthMarketData(pDepthMarketData);

}

void QCTPMdSpi::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField * pForQuoteRsp)
{
	cout << "OnRtnForQuoteRsp";
}


void QCTPMdSpi::SetLoginFiled(const char * _BrokerID, const char * _UserID, const char * _Password){

	

	BrokerID = _BrokerID;
	UserID = _UserID;
	Password = _Password;

}



#include "QCTPMdSpi.h"
#include <string>
#include<iostream>
#include "ctp_api/ThostFtdcUserApiDataType.h"
#include "ctp_api/ThostFtdcUserApiStruct.h"
#include "ctp_api/ThostFtdcMdApi.h"
#include "ctp_api/ThostFtdcTraderApi.h"
#include "DepthMarketData.pb.h"
#include <QtWidgets/QApplication>
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


///        0x1001 ÍøÂç¶ÁÊ§°Ü
///        0x1002 ÍøÂçÐ´Ê§°Ü
///        0x2001 ½ÓÊÕÐÄÌø³¬Ê±
///        0x2002 ·¢ËÍÐÄÌøÊ§°Ü
///        0x2003 ÊÕµ½´íÎó±¨ÎÄ
void QCTPMdSpi::OnFrontDisconnected(int nReason)
{
	switch (nReason){

	case 0x1001:
		cout << "ÍøÂç¶ÁÊ§°Ü" << endl;
		break;
	case 0x1002:
		cout << "ÍøÂçÐ´Ê§°Ü" << endl;
		break;
	case 0x2001:
		cout << "½ÓÊÕÐÄÌø³¬Ê±" << endl;
		break;
	case 0x2002:
		cout << "·¢ËÍÐÄÌøÊ§°Ü" << endl;
		break;
	case 0x2003:
		cout << "ÊÕµ½´íÎó±¨ÎÄ" << endl;
		break;
	}
	

	cout << "OnFrontDisconnected";
}

void QCTPMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	cout << "OnHeartBeatWarning====>" << nTimeLapse;
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

	DepthMarketData * data = new DepthMarketData;
	CThostFtdcDepthMarketDataField_2_PB(data, pDepthMarketData);
	delete data;
	//data->set_tradingday(pDepthMarketData->TradingDay);


	cout << "InstrumentID:" << pDepthMarketData->InstrumentID << "||SettlementPrice:" << pDepthMarketData->SettlementPrice << "||UpdateMillisec:" << pDepthMarketData->UpdateMillisec << "||×îÐÂ¼Û:" << pDepthMarketData->LastPrice << endl;
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

void QCTPMdSpi::CThostFtdcDepthMarketDataField_2_PB(DepthMarketData * pb_bean,CThostFtdcDepthMarketDataField * pDepthMarketData)
{
	pb_bean->set_tradingday(pDepthMarketData->TradingDay);
	pb_bean->set_instrumentid(pDepthMarketData->InstrumentID);
	pb_bean->set_exchangeid(pDepthMarketData->ExchangeID);
	pb_bean->set_exchangeinstid(pDepthMarketData->ExchangeInstID);
	pb_bean->set_lastprice(checkDouble(pDepthMarketData->LastPrice));
	pb_bean->set_presettlementprice(checkDouble(pDepthMarketData->PreSettlementPrice));
	pb_bean->set_precloseprice(checkDouble(pDepthMarketData->PreClosePrice));
	pb_bean->set_preopeninterest(checkDouble(pDepthMarketData->PreOpenInterest));
	pb_bean->set_openprice(checkDouble(pDepthMarketData->OpenPrice));
	pb_bean->set_highestprice(checkDouble(pDepthMarketData->HighestPrice));
	pb_bean->set_lowestprice(checkDouble(pDepthMarketData->LowestPrice));
	pb_bean->set_volume(pDepthMarketData->Volume);
	pb_bean->set_turnover(checkDouble(pDepthMarketData->Turnover));
	pb_bean->set_openinterest(checkDouble(pDepthMarketData->OpenInterest));
	pb_bean->set_closeprice(checkDouble(pDepthMarketData->ClosePrice));
	pb_bean->set_settlementprice(checkDouble(pDepthMarketData->SettlementPrice));
	pb_bean->set_upperlimitprice(checkDouble(pDepthMarketData->UpperLimitPrice));
	pb_bean->set_lowerlimitprice(checkDouble(pDepthMarketData->LowerLimitPrice));
	pb_bean->set_predelta(checkDouble(pDepthMarketData->PreDelta));
	pb_bean->set_currdelta(checkDouble(pDepthMarketData->CurrDelta));
	pb_bean->set_updatetime(pDepthMarketData->UpdateTime);
	pb_bean->set_updatemillisec(pDepthMarketData->UpdateMillisec);
	pb_bean->set_bidprice1(checkDouble(pDepthMarketData->BidPrice1));
	pb_bean->set_bidprice2(checkDouble(pDepthMarketData->BidPrice2));
	pb_bean->set_bidprice3(checkDouble(pDepthMarketData->BidPrice3));
	pb_bean->set_bidprice4(checkDouble(pDepthMarketData->BidPrice4));
	pb_bean->set_bidprice5(checkDouble(pDepthMarketData->BidPrice5));
	pb_bean->set_bidvolume1(pDepthMarketData->BidVolume1);
	pb_bean->set_bidvolume2(pDepthMarketData->BidVolume2);
	pb_bean->set_bidvolume3(pDepthMarketData->BidVolume3);
	pb_bean->set_bidvolume4(pDepthMarketData->BidVolume4);
	pb_bean->set_bidvolume5(pDepthMarketData->BidVolume5);
	pb_bean->set_askprice1(checkDouble(pDepthMarketData->AskPrice1));
	pb_bean->set_askprice2(checkDouble(pDepthMarketData->AskPrice2));
	pb_bean->set_askprice3(checkDouble(pDepthMarketData->AskPrice3));
	pb_bean->set_askprice4(checkDouble(pDepthMarketData->AskPrice4));
	pb_bean->set_askprice5(checkDouble(pDepthMarketData->AskPrice5));
	pb_bean->set_askvolume1(pDepthMarketData->AskVolume1);
	pb_bean->set_askvolume2(pDepthMarketData->AskVolume2);
	pb_bean->set_askvolume3(pDepthMarketData->AskVolume3);
	pb_bean->set_askvolume4(pDepthMarketData->AskVolume4);
	pb_bean->set_askvolume5(pDepthMarketData->AskVolume5);
	pb_bean->set_averageprice(checkDouble(pDepthMarketData->AveragePrice));
	pb_bean->set_actionday(pDepthMarketData->ActionDay);

	

}

double QCTPMdSpi::checkDouble(double number)
{
	if (number == DBL_MAX)
	{
		return 0;
	}
	return number;
}


#pragma once
#pragma execution_character_set("utf-8")
#include "ui_data_query.h"
#include <string>

DataQueryWindow::DataQueryWindow(std::string _code,QWidget * parent) :QDialog(parent){

	this_code = _code;

	setupUi();


}

void DataQueryWindow::setupUi(){

	code_label = new QLabel(tr("合约代码："));
	code = new QLabel(tr(this_code.c_str()));
	last_label = new QLabel(tr("最新价:"));
	last = new QLabel(0);

	OpenPriceLabel = new QLabel("今开盘");
	OpenPrice = new QLabel;

	ClosePriceLabel = new QLabel("今收盘");
	ClosePrice = new QLabel;

	minLabel = new QLabel("最低价");
	min = new QLabel;
	 
	maxLabel = new QLabel("最高价");
	max = new QLabel;


	hLayout = new QHBoxLayout;

	hLayout->addWidget(code_label);
	hLayout->addWidget(code);
	hLayout->addWidget(last_label);
	hLayout->addWidget(last);
	hLayout->addWidget(OpenPriceLabel);
	hLayout->addWidget(OpenPrice);
	hLayout->addWidget(ClosePriceLabel);
	hLayout->addWidget(ClosePrice);

	hLayout->addWidget(minLabel);
	hLayout->addWidget(min);

	hLayout->addWidget(maxLabel);
	hLayout->addWidget(max);

	hLayout->addStretch();

	//初始化列表
	QStringList headerLabels;
	headerLabels <<"交易日"<< "最后修改时间" << "最后修改毫秒" << "最新价" << "上次结算价" << "昨收盘" << "今开盘" << "最高价" << "最低价";
	table = new QTableWidget();
	table->setColumnCount(9);
	table->setHorizontalHeaderLabels(headerLabels);

	vLayout = new QVBoxLayout;
	vLayout->addLayout(hLayout);
	vLayout->addWidget(table);
	setLayout(vLayout);
}

QSize DataQueryWindow::sizeHint() const{
	return size();
}
QSize DataQueryWindow::size() const{
	return QSize(500,400);
}

DataQueryWindow::~DataQueryWindow()
{
	delete code_label ;
	delete code;
	delete last_label;
	delete last;
	delete hLayout;
	delete table;
	delete vLayout;
	
}

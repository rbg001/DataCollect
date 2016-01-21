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
	code = new QLabel("0");
	last_label = new QLabel(tr("最新价:"));
	last = new QLabel(0);


	hLayout = new QHBoxLayout;

	hLayout->addWidget(code_label);
	hLayout->addWidget(code);
	hLayout->addWidget(last_label);
	hLayout->addWidget(last);
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

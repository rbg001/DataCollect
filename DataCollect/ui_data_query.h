#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_DATA_QUERY_H
#define UI_DATA_QUERY_H

#include <QtWidgets>
#include <string>

class DataQueryWindow :public QDialog{

	Q_OBJECT

public:
	DataQueryWindow(std::string _code,QWidget * parent = 0);
	~DataQueryWindow();
private:

	std::string this_code;

	//合约代码
	QLabel * code_label;
	QLabel * code;


	//最新价
	QLabel * last_label;
	QLabel * last;


	//今开盘
	QLabel * OpenPriceLabel;
	QLabel * OpenPrice;

	//今收盘
	QLabel * ClosePriceLabel;
	QLabel * ClosePrice;

	

	//最低价
	QLabel * minLabel;
	QLabel * min;
	//最高价
	QLabel * maxLabel;
	QLabel * max;



	QHBoxLayout * hLayout;
	QVBoxLayout * vLayout;
	QTableWidget * table;

	void setupUi();

	QSize sizeHint() const;
	QSize size() const;

};
#endif
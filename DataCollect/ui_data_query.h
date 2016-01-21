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
	QLabel * code_label;
	QLabel * code;
	QLabel * last_label;
	QLabel * last;

	QHBoxLayout * hLayout;
	QVBoxLayout * vLayout;
	QTableWidget * table;

	void setupUi();

	QSize sizeHint() const;
	QSize size() const;

};
#endif
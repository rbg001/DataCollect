#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_CONFIG
#define  UI_CONFIG
#include <QtWidgets>
#include "ContractConfig.pb.h"

class Ui_Config : public QWidget 
{
	Q_OBJECT
public:
	Ui_Config(QWidget * parent = 0);
protected:
private:
	ContractConfig* ReadContractConfig();//读取配置文件
	void WriteConfig();//保存配置文件
	void ViewConfig();//更新List控件的显示
	ContractConfig* CConfig;

	QLabel* namelabel;
	QLabel* codelabel;

	QLabel* beginDateLabel;
	QLabel* endDateLabel;

	QLabel* beginTimeLabel1;
	QLabel* endTimeLabel1;

	QLabel* beginTimeLabel2;
	QLabel* endTimeLabel2;

	QLineEdit * nameText;
	QLineEdit * codeText;

	QLineEdit * beginDateText;
	QLineEdit * endDateText;

	QLineEdit * beginTime1Text;
	QLineEdit * endTime1Text;

	QLineEdit * beginTime2Text;
	QLineEdit * endTime2Text;

	QTableWidget * configListView;

	QPushButton * addButton;
	QPushButton * clearButton;
	QPushButton * saveButton;
	QPushButton * cancelButton;

	QGridLayout * gridLayOut;


	void setupUi();

};

#endif
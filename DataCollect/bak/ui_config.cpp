#pragma once
#pragma execution_character_set("utf-8")
#include "ui_config.h"

Ui_Config::Ui_Config(QWidget * parent /* = 0 */) :QWidget(parent){

	setupUi();

}

void Ui_Config::setupUi(){

	QStringList headerLabels;
	headerLabels << "合约名称" << "合约编码" << "合约开始时间" << "合约结束时间" << "开盘时间1" << "收盘时间1" << "开盘时间2" << "收盘时间2";

	namelabel = new QLabel;
	namelabel->setText("合约名称");

	codelabel = new QLabel;
	codelabel->setText("合约编码");

	beginDateLabel = new QLabel;
	beginDateLabel->setText("合约开始时间");

	endDateLabel = new QLabel;
	endDateLabel->setText("合约结束时间");

	beginTimeLabel1 = new QLabel;
	beginTimeLabel1->setText("开盘时间1");

	endTimeLabel1 = new QLabel;
	endTimeLabel1->setText("收盘时间1");

	beginTimeLabel2 = new QLabel;
	beginTimeLabel2->setText("开盘时间2");

	endTimeLabel2 = new QLabel;
	endTimeLabel2->setText("收盘时间2");

	nameText = new QLineEdit;
	codeText = new QLineEdit;

	beginDateText = new QLineEdit;
	endDateText = new QLineEdit;

	beginTime1Text = new QLineEdit;
	endTime1Text = new QLineEdit;

	beginTime2Text = new QLineEdit;
	endTime2Text = new QLineEdit;

	configListView = new QTableWidget;
	configListView->setHorizontalHeaderLabels(headerLabels);
	configListView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);


	addButton = new QPushButton; addButton->setText("添加");
	clearButton = new QPushButton; clearButton->setText("清除");
	saveButton = new QPushButton; saveButton->setText("保存");
	cancelButton = new QPushButton; cancelButton->setText("关闭");

	gridLayOut = new QGridLayout;

	gridLayOut->addWidget(namelabel, 0, 0, 1, 1);
	gridLayOut->addWidget(nameText, 0, 1, 1, 1);
	gridLayOut->addWidget(codelabel, 0, 2, 1, 1);
	gridLayOut->addWidget(codeText, 0, 3, 1, 1);


	gridLayOut->addWidget(beginDateLabel, 1, 0, 1, 1);
	gridLayOut->addWidget(beginDateText, 1, 1, 1, 1);
	gridLayOut->addWidget(endDateLabel, 1, 2, 1, 1);
	gridLayOut->addWidget(endDateText, 1, 3, 1, 1);

	gridLayOut->addWidget(beginTimeLabel1, 2, 0, 1, 1);
	gridLayOut->addWidget(beginTime1Text, 2, 1, 1, 1);
	gridLayOut->addWidget(endTimeLabel1, 2, 2, 1, 1);
	gridLayOut->addWidget(endTime1Text, 2, 3, 1, 1);

	gridLayOut->addWidget(beginTimeLabel2, 3, 0, 1, 1);
	gridLayOut->addWidget(beginTime2Text, 3, 1, 1, 1);
	gridLayOut->addWidget(endTimeLabel2, 3, 2, 1, 1);
	gridLayOut->addWidget(endTime2Text, 3, 3, 1, 1);

	gridLayOut->addWidget(addButton, 4, 0, 1, 1);
	gridLayOut->addWidget(clearButton, 4, 1, 1, 1);
	gridLayOut->addWidget(saveButton, 4, 2, 1, 1);
	gridLayOut->addWidget(cancelButton, 4, 3, 1, 1);


	gridLayOut->addWidget(configListView, 5, 0, 0, 4);

	setLayout(gridLayOut);
}


ContractConfig* Ui_Config::ReadContractConfig()//读取配置文件
{
	return NULL;
}
void Ui_Config::WriteConfig()//保存配置文件
{
}
void Ui_Config::ViewConfig()//更新List控件的显示
{
}
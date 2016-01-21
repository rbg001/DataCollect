#pragma once
#pragma execution_character_set("utf-8")
#include "ui_file_name.h"
#include "ui_main_window.h"
FileNameWindow::FileNameWindow(MainWindow * _mainWindow, QWidget * parent) :QDialog(parent){
	mainWindow = _mainWindow;
	setupUi();
}

void FileNameWindow::setupUi()
{

	setWindowTitle("合约代码");
	field_hLayout = new QHBoxLayout;


	code_label = new QLabel(tr("输入一个合约编号:"));
	code_text = new QLineEdit;
	ok_btn = new QPushButton(tr("确认"));
	cancel_btn = new QPushButton(tr("取消"));
	field_hLayout->addWidget(code_label);
	field_hLayout->addWidget(code_text);


	btn_hLayout = new QHBoxLayout;
	btn_hLayout->addStretch();
	btn_hLayout->addWidget(ok_btn);
	btn_hLayout->addWidget(cancel_btn);


	vLayout = new QVBoxLayout;
	vLayout->addLayout(field_hLayout);
	vLayout->addLayout(btn_hLayout);
	setLayout(vLayout);
	connect(cancel_btn,SIGNAL(clicked()), this, SLOT(close()));
	connect(ok_btn, SIGNAL(clicked()), this, SLOT(openQueryWindow()));

}

void FileNameWindow::openQueryWindow()
{
	mainWindow->openNewQueryWindow(code_text->text().toStdString());
	close();
}

FileNameWindow::~FileNameWindow()
{
	delete code_label ;
	delete code_text;
	delete ok_btn;
	delete cancel_btn;
	delete field_hLayout;
	delete btn_hLayout;
	delete vLayout;
}

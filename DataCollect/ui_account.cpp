#pragma once
#pragma execution_character_set("utf-8")
#include "ui_account.h"
#include "Account.h"
AccountWindow::AccountWindow(QWidget * parent /* = 0 */) :QDialog(parent){
	 
	setWindowTitle("账号设置");
	setupUi();
	InitData();
	setupEvent();

} 

void AccountWindow::setupUi()
{

	setWindowTitle("账号配置");
	setWindowIcon(QIcon(":/DataCollect/img/polaroid-2.png"));

	broker_label = new QLabel("Broker ID");
	userId_label = new QLabel("User ID");
	passwd_label = new QLabel("Password");
	frontIp_label = new QLabel("Front Ip");
	
	broker_text = new QLineEdit;
	userId_text = new QLineEdit;
	passwd_text = new QLineEdit;
	frontIp_text = new QLineEdit;

	saveButton = new QPushButton("保存");
	cancelButton = new QPushButton("关闭");

	g_field_layout = new QGridLayout;
	h_button_layout = new QHBoxLayout;
	v_layout = new QVBoxLayout;

	g_field_layout->addWidget(broker_label, 0, 0);
	g_field_layout->addWidget(broker_text, 0, 1);
	g_field_layout->addWidget(userId_label, 1, 0);
	g_field_layout->addWidget(userId_text, 1, 1);
	g_field_layout->addWidget(passwd_label, 2, 0);
	g_field_layout->addWidget(passwd_text, 2, 1);
	g_field_layout->addWidget(frontIp_label, 3, 0);
	g_field_layout->addWidget(frontIp_text, 3, 1);

	h_button_layout->addStretch();
	h_button_layout->addWidget(saveButton);
	h_button_layout->addWidget(cancelButton);

	v_layout->addLayout(g_field_layout);

	v_layout->addLayout(h_button_layout);

	setLayout(v_layout);
}

void AccountWindow::setupEvent()
{
	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveData()));
	connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

AccountWindow::~AccountWindow()
{

	delete broker_label;
	delete userId_label;
	delete passwd_label;
	delete frontIp_label;
	delete broker_text;
	delete userId_text;
	delete passwd_text;
	delete frontIp_text;
	delete g_field_layout;
	delete h_button_layout;
	delete v_layout;
	delete accountConfig;
	delete account;

}

void AccountWindow::InitData()
{
	account = new Account;
	accountConfig = account->ReadAccountConfig();
	if (accountConfig!=NULL){
		broker_text->setText(accountConfig->brokerid().c_str());
		userId_text->setText(accountConfig->userid().c_str());
		passwd_text->setText(accountConfig->password().c_str());
		frontIp_text->setText(accountConfig->front_ip().c_str());
	}

}

void AccountWindow::saveData()
{

	if (accountConfig==NULL)
	{
		accountConfig = new AccountConfig;
	}
	accountConfig->set_brokerid(broker_text->text().toStdString());
	accountConfig->set_userid(userId_text->text().toStdString());
	accountConfig->set_password(passwd_text->text().toStdString());
	accountConfig->set_front_ip(frontIp_text->text().toStdString());
	account->accountConfig = accountConfig;
	account->SaveAccountConfig();
}

bool AccountWindow::checkData()
{
	return false;
}

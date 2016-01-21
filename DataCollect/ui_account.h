#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_ACCOUNT_H
#define UI_ACCOUNT_H

#include <QtWidgets>
class Account;
class AccountConfig;
class AccountWindow :public QDialog
{
	Q_OBJECT;
public:
	AccountWindow(QWidget * parent = 0);
	~AccountWindow();
protected:
private:
	QLabel * broker_label;
	QLabel * userId_label;
	QLabel * passwd_label;
	QLabel * frontIp_label;

	QLineEdit * broker_text;
	QLineEdit * userId_text;
	QLineEdit * passwd_text;
	QLineEdit * frontIp_text;

	QPushButton * saveButton;
	QPushButton * cancelButton;

	QGridLayout * g_field_layout;
	QHBoxLayout * h_button_layout;
	QVBoxLayout * v_layout;
	Account * account;
	AccountConfig * accountConfig;
	void InitData();
	void setupUi();
	void setupEvent();
	bool checkData();

	private slots:
	void saveData();
};

#endif 
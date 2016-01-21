#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_FILE_NAME_H
#define  UI_FILE_NAME_H
#include <QtWidgets>
class MainWindow;
class FileNameWindow :public QDialog
{
	Q_OBJECT
public:
	FileNameWindow(MainWindow * mainWindow, QWidget * parent = 0);
	~FileNameWindow();
protected:
private:
	MainWindow * mainWindow;
	QLabel * code_label;
	QLineEdit * code_text;
	QPushButton * ok_btn;
	QPushButton * cancel_btn;
	QHBoxLayout * field_hLayout;
	QHBoxLayout * btn_hLayout;
	QVBoxLayout * vLayout;
	void setupUi();
private slots:
	void openQueryWindow();

};

#endif
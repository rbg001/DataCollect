#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_CONFIG_H
#define  UI_CONFIG_H
#include <QtWidgets>
#include "ContractConfig.pb.h"

class Ui_Config : public QDialog
{
	Q_OBJECT
public:
	Ui_Config(QWidget * parent = 0);
	~Ui_Config();
protected:
private:
	QString CheckInput();
	void ReadContractConfig();//读取配置文件
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

	QDateEdit * beginDateText;
	QDateEdit * endDateText;

	QTimeEdit * beginTime1Text;
	QTimeEdit * endTime1Text;

	QTimeEdit * beginTime2Text;
	QTimeEdit * endTime2Text;

	QTableWidget * configListView;

	QPushButton * addButton;
	QPushButton * clearButton;
	QPushButton * saveButton;
	QPushButton * cancelButton;
	QPushButton * deleteButton;

	QGridLayout * gridLayOut;
	QVBoxLayout * vLayout;
	QHBoxLayout * hLayout;
	QHBoxLayout * buttonHLayout;
	

	void setupUi();

	QSize size() const;
	QSize sizeHint() const;
	void setupEvent();
	bool CheckCodeRepeat();
	void SaveConfig();
	
	private slots:
		void AddConfig();
		void SaveConfigEvent();
		void CleanInput();
		void DeleteSelectedConfig();
	
};

#endif
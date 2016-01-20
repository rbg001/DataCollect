#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H
#include "QMainWindow"
#include "ui_config.h"





class AccountWindow;
class ContractConfig;

class  MainWindow : public QMainWindow
{
	Q_OBJECT;
public:
	MainWindow(QWidget * parent = 0);
	~MainWindow();
protected:
private:
	char ** code_list = NULL;//用来保存合约列表
	int code_size = 0;
	int run_status = 0; //0 代表没有运行 1 代表运行

	QSize sizeHint() const;
	QSize size()const;

	void createActions();
	void createMenus();
	void createEvent();
	void readConfig();

	QAction * startCollect;
	QAction * stopCollect;
	QAction * newMonitor;
	QAction * statusBar;
	QAction * showConfigWindow;
	QAction * showAccountConfig;
	QMenu * menu;
	QToolBar *toolBar;

	Ui_Config *  config_window = NULL;
	ContractConfig * config_data = NULL;
	AccountWindow * accWindow = NULL;
	private slots:
		void openConfigWindow();
		void openAccountConfigWindow();
		void startCollectEvent();
};




#endif
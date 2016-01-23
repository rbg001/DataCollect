#pragma once
#pragma execution_character_set("utf-8")
#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H
#include "QMainWindow"
#include "ui_config.h"
#include "ui_data_query.h"
#include <string>
#include   <map> 



class AccountWindow;
class ContractConfig;
class CThostFtdcMdApi;
class QCTPMdSpi;
class AccountConfig;
class  FileNameWindow;
using namespace  std;
class  MainWindow : public QMainWindow
{
	Q_OBJECT;
public:
	MainWindow(QWidget * parent = 0);
	~MainWindow();
	void openNewQueryWindow(string code);
	//保存了打开的查询窗口
	map<string, QMdiSubWindow *>   window_map;
protected:
private:
	
	//成员变量
	int run_status = 0; //0 代表没有运行 1 代表运行

	char ** code_list = NULL;//用来保存合约列表
	int code_size = 0;
	ContractConfig * config_data = NULL;
	AccountConfig * account_data = NULL;
	
	
	CThostFtdcMdApi* pUserApi = NULL;
	QCTPMdSpi * pUserSpi = NULL;



	//成员方法
	QSize sizeHint() const;
	QSize size()const;
	void setupUi();
	void createActions();
	void createMenus();
	void createEvent();
	void readConfig();
	


	//action 和menu
	QAction * startCollect;
	QAction * stopCollect;
	QAction * newMonitor;
	QAction * statusBar;
	QAction * showConfigWindow;
	QAction * showAccountConfig;
	QMenu * menu;
	QToolBar *toolBar;

	//窗口
	Ui_Config *  config_window = NULL;
	AccountWindow * accWindow = NULL;
	DataQueryWindow * queryWindow = NULL;
	FileNameWindow * file_window = NULL;
	


	//容器
	QMdiArea * mdi;
	QScrollArea *scrollAre;
	private slots:
		void openConfigWindow();
		void openAccountConfigWindow();
		void startCollectEvent();
		
		void newFileNameWindow();
};




#endif
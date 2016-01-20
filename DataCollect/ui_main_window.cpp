#pragma once
#pragma execution_character_set("utf-8")
#define CONFIG_FILE_NAME "ContractConfig.pb"
#include "ui_main_window.h"
#include "ContractConfig.pb.h"
#include<QAction>
#include <QtWidgets>

#include <io.h>
#include <fstream>

#include "ui_account.h"
#include "ui_config.h"
#include <string>
#include "ArrayUtil.h"


MainWindow::MainWindow(QWidget * parent) :QMainWindow(parent){
	//测试
	createActions();
	createMenus();
	createEvent();
	readConfig();
}

void MainWindow::createActions(){
	setWindowTitle("数据收集");
	setWindowIcon(QIcon(":/DataCollect/img/waller-2.png"));

	startCollect = new QAction(tr("开始运行"), this);
	startCollect->setIcon(QIcon(":/DataCollect/img/play.png"));
	stopCollect = new QAction(tr("停止运行"),this);
	stopCollect->setIcon(QIcon(":/DataCollect/img/stop.png"));
	newMonitor = new QAction(tr("新建数据监视"),this);
	newMonitor->setIcon(QIcon(":/DataCollect/img/camera.png"));
	showAccountConfig = new QAction(tr("账号配置"), this);
	showAccountConfig->setIcon(QIcon(":/DataCollect/img/polaroid-2.png"));
	statusBar = new QAction(tr("状态图"),this);
	statusBar->setIcon(QIcon(":/DataCollect/img/star.png"));
	showConfigWindow = new QAction(tr("合约配置"),this);
	showConfigWindow->setIcon(QIcon(":/DataCollect/img/align-horizontal-centers.png"));
}

void MainWindow::createMenus(){

	
	menu = menuBar()->addMenu(QIcon(":/DataCollect/img/settings.png"),tr("菜单"));


	menu->addAction(startCollect);
	menu->addAction(stopCollect);
	menu->addAction(newMonitor);
	menu->addAction(statusBar);
	menu->addSeparator();
	menu->addAction(showConfigWindow);
	menu->addAction(showAccountConfig);

	toolBar = addToolBar(tr("菜单二"));
	toolBar->addAction(startCollect);
	toolBar->addAction(stopCollect);
	toolBar->addAction(newMonitor);
	toolBar->addAction(statusBar);
	toolBar->addSeparator();
	toolBar->addAction(showConfigWindow);
	toolBar->addAction(showAccountConfig);
	
}

QSize MainWindow::sizeHint() const{
	return size();
}
QSize MainWindow::size()const{
	
	return QSize(1000, 600);
}

void MainWindow::openConfigWindow()
{
	if (config_window==NULL)
	{
		config_window = new Ui_Config;
	}
	
	config_window->setModal(true);
	config_window->show();
}

void MainWindow::createEvent()
{
	connect(showConfigWindow, SIGNAL(triggered()), this, SLOT(openConfigWindow()));
	connect(showAccountConfig, SIGNAL(triggered()), this, SLOT(openAccountConfigWindow()));
	connect(startCollect, SIGNAL(triggered()), this, SLOT(startCollectEvent()));
}

void MainWindow::readConfig()
{
	using namespace std;
	config_data = new ContractConfig();

	if (access(CONFIG_FILE_NAME, 0) == 0){
		fstream input("ContractConfig.pb", ios::in | ios::binary);
		config_data->ParseFromIstream(&input);
		input.close();
	}
}

void MainWindow::openAccountConfigWindow()
{
	if (accWindow == NULL){
		accWindow = new AccountWindow;
	}
	
	accWindow->setModal(true);
	accWindow->show();
}


MainWindow::~MainWindow(){

	delete startCollect;
	delete stopCollect;
	delete newMonitor;
	delete statusBar;
	delete showConfigWindow;
	delete showAccountConfig;
	delete menu;
	delete toolBar;
	delete config_data;

	delete  config_window;
	delete  accWindow;



	//删除合约列表占用的空间
	for (int i = 0; i < code_size; i++)
	{
		delete[]code_list[i];
	}


	delete[] code_list;

}

void MainWindow::startCollectEvent()
{


	//读取配置文件
	using namespace std;
	ContractConfig config;

	if (access(CONFIG_FILE_NAME, 0) == 0){
		fstream input(CONFIG_FILE_NAME, ios::in | ios::binary);
		config.ParseFromIstream(&input);
		input.close();
		QMessageBox message(QMessageBox::Icon::Warning, "Warning", "开始", QMessageBox::Ok, NULL);
		
		message.exec();
	}
	else{
		QMessageBox message(QMessageBox::Icon::Warning, "Warning", "没有配置合约列表", QMessageBox::Ok, NULL);
		message.exec();
		return;
	}


	
		//初始化合约列表

		ArrayUtil util;
		if (code_list != NULL)
		{
			for (int i = 0; i < code_size; i++)
			{
				delete[]code_list[i];
			}
			delete[] code_list;
		}

		code_size = config.contracts_size();

		string * code_tmp = new string[code_size];
		for (int i = 0; i < code_size; i++)
		{
			code_tmp[i] = config.contracts(i).contractcode();
		}

		code_list = util.getArr(code_tmp, code_size);

		for (int i = 0; i < code_size; i++)
		{
			qDebug(code_list[i]);
		}
		delete []code_tmp;
}





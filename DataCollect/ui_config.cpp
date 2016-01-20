#pragma once
#pragma execution_character_set("utf-8")
#include "ui_config.h"
#include <io.h>
#include <fstream>

#include "QMessageBox"
#define CONFIG_FILE_NAME "ContractConfig.pb"
#define NAME_INPUT_WAR "合约名称不能为空"
#define CODE_INPUT_WAR "合约编号不能为空"
#define CODE_REPEAT "合约编号重复"

Ui_Config::Ui_Config(QWidget * parent /* = 0 */) :QDialog(parent){
	
	setupUi();
	setupEvent();
	ReadContractConfig();
	ViewConfig();

}
Ui_Config::~Ui_Config(){

	 
	delete namelabel;
	delete codelabel;

	delete beginDateLabel;
	delete endDateLabel;

	delete beginTimeLabel1;
	delete endTimeLabel1;

	delete beginTimeLabel2;
	delete endTimeLabel2;

	delete nameText;
	delete codeText;

	delete beginDateText;
	delete endDateText;

	delete beginTime1Text;
	delete endTime1Text;

	delete beginTime2Text;
	delete endTime2Text;

	delete configListView;

	delete addButton;
	delete clearButton;
	delete saveButton;
	delete cancelButton;
	delete deleteButton;

	delete gridLayOut;
	delete buttonHLayout;
	delete hLayout;
	delete vLayout;
	SaveConfig();
	delete CConfig;
	

}

void Ui_Config::setupUi(){


	setWindowTitle("合约配置");
	setWindowIcon(QIcon(":/DataCollect/img/align-horizontal-centers.png"));


	//设置界面不允许缩放
	setFixedSize(size());
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	//初始化label标签
	namelabel = new QLabel("<b>合约名称</b>");
	QPalette red;
	red.setColor(QPalette::WindowText, Qt::red);
	namelabel->setPalette(red);

	codelabel = new QLabel;
	codelabel->setText("<b>合约编码</b>");
	codelabel->setPalette(red);

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

	//初始化编辑控件
	nameText = new QLineEdit;
	codeText = new QLineEdit;

	beginDateText = new QDateEdit;
	beginDateText->setDate(QDate::currentDate());
	

	endDateText = new QDateEdit;
	endDateText->setDate(QDate::currentDate());
	beginTime1Text = new QTimeEdit;
	endTime1Text = new QTimeEdit;

	beginTime2Text = new QTimeEdit ;
	endTime2Text = new QTimeEdit;

	

	//初始化列表
	QStringList headerLabels;
	headerLabels << "合约名称" << "合约编码" << "合约开始时间" << "合约结束时间" << "开盘时间1" << "收盘时间1" << "开盘时间2" << "收盘时间2";
	configListView = new QTableWidget();
	configListView->setColumnCount(8);
	configListView->setHorizontalHeaderLabels(headerLabels);
	
	configListView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
	configListView->verticalHeader()->setDefaultSectionSize(20);
	//设置选择行为，以行为单位
	configListView->setSelectionBehavior(QAbstractItemView::SelectRows);
	//设置选择模式，选择单行
	//configListView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	//禁止编辑
	configListView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	addButton = new QPushButton; addButton->setText("添加");
	clearButton = new QPushButton; clearButton->setText("清除");
	saveButton = new QPushButton; saveButton->setText("保存");
	cancelButton = new QPushButton; cancelButton->setText("关闭");
	deleteButton = new QPushButton;
	deleteButton->setText("删除选中");

	//开始页面布局
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




	buttonHLayout = new QHBoxLayout;
	buttonHLayout->addStretch();
	buttonHLayout->addWidget(addButton);
	buttonHLayout->addWidget(clearButton);
	buttonHLayout->addWidget(saveButton);
	buttonHLayout->addWidget(deleteButton);
	buttonHLayout->addWidget(cancelButton);

	vLayout = new QVBoxLayout;
	hLayout = new QHBoxLayout;
	hLayout->addWidget(configListView);
	vLayout->addLayout(gridLayOut);
	vLayout->addLayout(buttonHLayout);
	vLayout->addLayout(hLayout);

	

	setLayout(vLayout);
}

//读取配置文件
void Ui_Config::ReadContractConfig()
{
	using namespace std;
	CConfig = new ContractConfig();
	
	if (access(CONFIG_FILE_NAME, 0)==0){
		fstream input(CONFIG_FILE_NAME, ios::in | ios::binary);
		CConfig->ParseFromIstream(&input);
	}
}

QString Ui_Config::CheckInput(){
	if (nameText->text()=="")
	{
		return NAME_INPUT_WAR;
	}

	if (codeText->text()=="")
	{
		return CODE_INPUT_WAR;
	}

	if (!CheckCodeRepeat()){
		return CODE_REPEAT;
	}
	return "";

}
//保存配置文件
void Ui_Config::WriteConfig()
{
}
//更新List控件的显示
void Ui_Config::ViewConfig()
{
	configListView-> setRowCount(0);
	configListView->clearContents();
	int config_item_size = CConfig->contracts_size();
	if (config_item_size != 0){
		
		for (int i = 0; i < config_item_size;i++)
		{
			int row_index = configListView->rowCount();
			configListView->insertRow(row_index);
			configListView->setItem(row_index, 0, new QTableWidgetItem(CConfig->contracts(i).contractname().c_str()));
			configListView->setItem(row_index, 1, new QTableWidgetItem(CConfig->contracts(i).contractcode().c_str()));
			configListView->setItem(row_index, 2, new QTableWidgetItem(CConfig->contracts(i).begindate().c_str()));
			configListView->setItem(row_index, 3, new QTableWidgetItem(CConfig->contracts(i).enddate().c_str()));
			configListView->setItem(row_index, 4, new QTableWidgetItem(CConfig->contracts(i).begintime1().c_str()));
			configListView->setItem(row_index, 5, new QTableWidgetItem(CConfig->contracts(i).endtime1().c_str()));
			configListView->setItem(row_index, 6, new QTableWidgetItem(CConfig->contracts(i).begintime2().c_str()));
			configListView->setItem(row_index, 7, new QTableWidgetItem(CConfig->contracts(i).endtime2().c_str()));
		}

	}

}

void Ui_Config::AddConfig(){
	QString mess = CheckInput();
	if (mess == "")
	{

		ContractConfig_ContractItem* item = CConfig->add_contracts();
		item->set_contractname(nameText->text().toStdString());
		item->set_contractcode(codeText->text().toStdString());
		item->set_begindate(beginDateText->text().toStdString());
		item->set_enddate(endDateText->text().toStdString());
		item->set_begintime1(beginTime1Text->text().toStdString());
		item->set_endtime1(endTime1Text->text().toStdString());
		item->set_begintime2(beginTime2Text->text().toStdString());
		item->set_endtime2(endTime2Text->text().toStdString());
		CleanInput();
	}
	else{
		QMessageBox message(QMessageBox::Icon::Warning, "Warning", mess, QMessageBox::Ok, NULL);
		message.exec();
	}
	ViewConfig();

}
void Ui_Config::SaveConfigEvent(){
	try
	{
		SaveConfig();
	}
	catch (std::ios_base::failure e)
	{
		qDebug(e.what());
		QMessageBox message(QMessageBox::Icon::Warning, "保存异常", e.what(), QMessageBox::Ok, NULL);
		message.exec();
		return;
	}
	QMessageBox message(QMessageBox::Icon::Information, "Info", "保存成功", QMessageBox::Ok, NULL);
	message.exec();

	
	
}
void Ui_Config::SaveConfig(){
	using namespace std;
	try
	{
		fstream out("ContractConfig.pb", ios::out | ios::binary);
		CConfig->SerializePartialToOstream(&out);
	}
	catch (std::ios_base::failure e)
	{
		throw e;
	}

	
}


void Ui_Config::setupEvent(){
	connect(addButton, SIGNAL(clicked()), this, SLOT(AddConfig()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(SaveConfigEvent()));
	connect(deleteButton, SIGNAL(clicked()), this, SLOT(DeleteSelectedConfig()));
	connect(clearButton, SIGNAL(clicked()), this, SLOT(CleanInput()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
	
}


bool Ui_Config::CheckCodeRepeat(){
	using namespace  std;
	int size = CConfig->contracts_size();
	string new_code = codeText->text().toStdString();
	if (size <= 0)
	{
		return true;
	}
	for (int i = 0; i < size;i++)
	{
		string code = CConfig->contracts(i).contractcode();
		if (code == new_code){
			return false;
		}
	}

	return true;


}
void Ui_Config::CleanInput(){
	nameText->clear();
	codeText->clear();
}


void Ui_Config::DeleteSelectedConfig(){
	QList<QTableWidgetSelectionRange> ranges = configListView->selectedRanges();
	int count = ranges.count();
	if (count<=0)
	{
			QMessageBox message(QMessageBox::Icon::Warning, "Warning", "没有选择任何行", QMessageBox::Ok, NULL);
			message.exec();
			return;
	}
	for (int i = 0; i < count; i++)
	{
		int topRow = ranges.at(i).topRow();
		int bottomRow = ranges.at(i).bottomRow();
		int count = 0;
		for (int j = topRow; j <= bottomRow; j++)
		{
			CConfig->mutable_contracts()->DeleteSubrange(j - count, 1);
			count++;
			
		}
		
	}

	SaveConfig();
	ViewConfig();
	
}

QSize Ui_Config::size() const{
	
	return QSize(850, 500);
}

QSize Ui_Config::sizeHint() const{
	return size();
}



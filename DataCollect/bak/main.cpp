#include "datacollect.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "ContractConfig.pb.h"
#include "ui_config.h"
#include <fstream>  
void WriteToPB();
void ReadFromPB();
using namespace std;
int main(int argc, char *argv[])
{

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
	QApplication a(argc, argv);

	//DataCollect w;
	//w.show();
	Ui_Config config;
	config.show();

	return a.exec();


	//WriteToPB();
	//ReadFromPB();





}

void ReadFromPB(){
	fstream input("ContractConfig.pb", ios::in | ios::binary);
	ContractConfig * config = new ContractConfig;
	config->ParseFromIstream(&input);
	int size = config->contracts_size();
	for (int a = 0; a < size;a++)
	{
		ContractConfig_ContractItem item = config->contracts(a);
		cout << item.contractname()<<endl;
	}


	config->ParseFromIstream(&input);
	

	delete config;
}

void WriteToPB(){

	ContractConfig * config = new ContractConfig;
	
	ContractConfig_ContractItem* item = config->add_contracts();
	item->set_contractname("沪铜");
	item->set_contractcode("cu1206");
	item->set_begindate("2015-01-01");
	item->set_enddate("2016-01-01");
	item->set_begintime1("21:00:00");
	item->set_endtime1("23:00:00");
	item->set_begintime2("9:00");
	item->set_begintime2("10:00");
	fstream output("ContractConfig.pb", ios::out | ios::trunc | ios::binary);
	
	config->SerializePartialToOstream(&output);
	delete config;


}
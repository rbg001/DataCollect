#ifndef DATACOLLECT_H
#define DATACOLLECT_H

#include <QtWidgets/QMainWindow>
#include "ui_datacollect.h"

class DataCollect : public QMainWindow
{
	Q_OBJECT

public:
	DataCollect(QWidget *parent = 0);
	~DataCollect();

private:
	Ui::DataCollectClass ui;
};

#endif // DATACOLLECT_H

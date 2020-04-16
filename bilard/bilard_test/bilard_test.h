#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_bilard_test.h"

class bilard_test : public QMainWindow
{
	Q_OBJECT

public:
	bilard_test(QWidget *parent = Q_NULLPTR);

private:
	Ui::bilard_testClass ui;
};

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>

#include "ChoseSing/AdaptiveDinamicTable.h"
#include "CalcButton.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AdaptiveDinamicTable *table = new AdaptiveDinamicTable(4, 4, 3, 1, this);

    ResultWindow* result_window = new ResultWindow("Окно результата", this);

    CalcButton* calc_button = new CalcButton(table, result_window, "Рассчитать", this);

    ui->main_layout->addWidget(table);
    ui->main_layout->addWidget(calc_button);
    ui->main_layout->addWidget(result_window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

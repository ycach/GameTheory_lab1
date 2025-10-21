#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "DinamicTable.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    DinamicTable *table = new DinamicTable(4, 4, this);
    table->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    setCentralWidget(table);


}

MainWindow::~MainWindow()
{
    delete ui;
}

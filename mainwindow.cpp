#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ChoseSing/AdaptiveDinamicTable.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    AdaptiveDinamicTable *table = new AdaptiveDinamicTable(4, 4, 3, 1, this);

    QPushButton *testButton = new QPushButton("Получить данные", this);
    connect(testButton, &QPushButton::clicked, this, [table]() {
        Matrix<double> data = table->GetData();
    });
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(table);
    layout->addWidget(testButton);
    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
    delete ui;
}

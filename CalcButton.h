#ifndef CALCBUTTON_H
#define CALCBUTTON_H

#include <QPushButton>

#include "ChoseSing/AdaptiveDinamicTable.h"
#include "ResultShower/ResultWindow.h"

class CalcButton : public QPushButton
{
    Q_OBJECT
public:
    CalcButton(AdaptiveDinamicTable* table, ResultWindow* result_window, QString text = "Рассчитать", QWidget* parent = nullptr);

private slots:
    void Calculate();

private:
    AdaptiveDinamicTable* table_data;
    ResultWindow* result_window;
    bool lock;
    void Lock();
    void Unlock();
};

#endif // CALCBUTTON_H

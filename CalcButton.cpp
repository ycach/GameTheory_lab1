#include "CalcButton.h"
#include "CalcFunctions.h"

#include "CastomResultShower/CastomRecord.h"


CalcButton::CalcButton(AdaptiveDinamicTable* table, ResultWindow* result_window, QString text, QWidget* parent) : QPushButton(text, parent) {
    lock = false;
    this->table_data = table;
    this->result_window = result_window;

    connect(table, &AdaptiveDinamicTable::ErrorGetData, this, &CalcButton::Lock);
    connect(this, &QPushButton::clicked, this, &CalcButton::Calculate);
}


void CalcButton::Lock(){
    lock = true;
}
void CalcButton::Unlock(){
    lock = false;
}

void CalcButton::Calculate(){
    Matrix<double> data = table_data->GetData();
    if(!lock){
        std::vector<bool> min_max_sings = table_data->GetMaxSingsState();
        std::vector<double> result = CalcFunc::CalculateOptimalStrategy(data, min_max_sings);

        CastomRecord* new_record = new CastomRecord(result, min_max_sings, "Результат расчета", result_window);
        result_window->AddRecord(new_record);
    }
    lock = false;
}

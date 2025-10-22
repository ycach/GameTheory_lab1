#include "AdaptiveDinamicTable.h"

#include <QHBoxLayout>
#include "MinMaxButton.h"

AdaptiveDinamicTable::AdaptiveDinamicTable(int data_rows, int data_columns, int title_rows, int title_cols, QWidget* parent)
    : DinamicTable(data_rows, data_columns, title_rows, title_cols, parent){
    CreateTitlesStile();
}

std::vector<bool> AdaptiveDinamicTable::GetMaxSingsState() const{
    std::vector<bool> result;
    result.reserve(active_columns);

    for (int idx = titles_columns; idx < active_columns + titles_columns; ++idx) {
        QWidget* widget = cellWidget(2, idx);
        MinMaxButton* btn = qobject_cast<MinMaxButton*>(widget);
        if (btn) {
            result.push_back(btn->IsMaxState());
        } else {
            result.push_back(false);
        }
    }

    return result;
}

void AdaptiveDinamicTable::AddActiveColumn(){
    DinamicTable::AddActiveColumn();

    int index = columnCount() - 2;
    MinMaxButton *btnMinMax = new MinMaxButton(index, true, this);
    btnMinMax->setToolTip("Сменить норму признака");
    setCellWidget(2, index, btnMinMax);

    connect(this, &DinamicTable::SignalColumnRemoved,
            btnMinMax, &MinMaxButton::IndexUpdate);

}

void AdaptiveDinamicTable::CreateTitlesStile(){
    for(int idx = titles_columns; idx < active_columns + titles_columns; idx++){
        MinMaxButton *btnMinMax = new MinMaxButton(idx, true, this);
        btnMinMax->setToolTip("Сменить норму признака");
        setCellWidget(2, idx, btnMinMax);

        connect(this, &DinamicTable::SignalColumnRemoved,
                btnMinMax, &MinMaxButton::IndexUpdate);
    }
}

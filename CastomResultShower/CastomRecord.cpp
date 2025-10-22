#include "CastomRecord.h"

#include <algorithm>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <Qlabel>
#include <QSpacerItem>

CastomRecord::CastomRecord(std::vector<double> result,
                           std::vector<bool> min_max,
                           const QString& title,
                           QWidget* parent)
    : ResultRecord(title, parent){

    this->result = result;
    this->min_max_sings = min_max;

}


void CastomRecord::CreateRecord(){
    QVBoxLayout* main_layout = new QVBoxLayout(this);

    for(int i = 0; i < result.size(); i++){
        QHBoxLayout* result_layout = new QHBoxLayout();

        QLineEdit* result_name = new QLineEdit(this);
        QString base_name = QString("Стратегия %1:").arg(i + 1);
        result_name->setText(base_name);
        result_layout->addWidget(result_name);

        QString label_text = "F = " + QString::number(result[i]);
        QLabel* label_result = new QLabel(label_text, this);
        result_layout->addWidget(label_result);

        QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Expanding);
        result_layout->addItem(spacer);

        main_layout->addLayout(result_layout);
    }

    int count = 0;
    QString max_sings = "Максимизированные критерии: ";
    QString min_sings = "Минимизированные критерии: ";
    for(int i = 0; i < min_max_sings.size(); i++){
        if(min_max_sings[i])
            max_sings += QString::number(i + 1) + " ";
        else{
            min_sings += QString::number(i + 1) + " ";
            count++;
        }
    }

    if(count == 0){
        QHBoxLayout* static_layout = new QHBoxLayout();
        QLabel* label = new QLabel("Все критерии максимизированы", this);
        static_layout->addWidget(label);
        main_layout->addLayout(static_layout);
    }
    else if(count == min_max_sings.size()){
        QHBoxLayout* static_layout = new QHBoxLayout();
        QLabel* label = new QLabel("Все критерии минимизированы", this);
        static_layout->addWidget(label);
        main_layout->addLayout(static_layout);

    }else{
        QHBoxLayout* max_layout = new QHBoxLayout();
        QLabel* label_max = new QLabel(max_sings, this);
        max_layout->addWidget(label_max);
        main_layout->addLayout(max_layout);

        QHBoxLayout* min_layout = new QHBoxLayout();
        QLabel* label_min = new QLabel(min_sings, this);
        min_layout->addWidget(label_min);
        main_layout->addLayout(min_layout);
    }

    QHBoxLayout* conclusion_layout = new QHBoxLayout();
    auto it = std::max_element(result.begin(), result.end());
    int best_value_index = std::distance(result.begin(), it);
    double best_value = *it;

    QString conclusion = "Наилучшей стратегией является стратегия под номером " +
                         QString::number(best_value_index + 1) +
                         "; F = " + QString::number(best_value);
    QLabel* conclusion_label = new QLabel(conclusion, this);

    conclusion_layout->addWidget(conclusion_label);
    main_layout->addLayout( conclusion_layout);

}


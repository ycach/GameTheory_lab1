#include "MinMaxButton.h"

MinMaxButton::MinMaxButton(int index, bool max_state, QWidget* parent) : QPushButton(parent) {
    this->is_max_state = max_state;
    this->sing_index = index;
    changeColorAndText();

    connect(this, &QPushButton::clicked, this, &MinMaxButton::Swap);

}


int MinMaxButton::GetIndex() const{
    return sing_index;
}
bool MinMaxButton::IsMaxState() const{
    return is_max_state;
}

void MinMaxButton::Swap(){
    is_max_state = !is_max_state;
    changeColorAndText();
}

void MinMaxButton::changeColorAndText(){
    if(is_max_state){
        setStyleSheet("background-color: green;");
        setText("max");
    }
    else{
        setStyleSheet("background-color: red;");
        setText("min");
    }
}

void MinMaxButton::IndexUpdate(int removed_index){
    if (removed_index < sing_index){
        sing_index--;
    }
}

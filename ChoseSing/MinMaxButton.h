#ifndef MINMAXBUTTON_H
#define MINMAXBUTTON_H

#include <QPushButton>

class MinMaxButton : public QPushButton
{
    Q_OBJECT
public:
    MinMaxButton(int index, bool max_state = true, QWidget* parent = nullptr);

    int GetIndex() const;
    bool IsMaxState() const;

    void IndexUpdate(int removed_index);
private slots:
    void Swap();

private:
    int sing_index;
    bool is_max_state;

    void changeColorAndText();

};

#endif // MINMAXBUTTON_H

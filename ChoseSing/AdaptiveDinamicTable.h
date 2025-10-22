#ifndef ADAPTIVEDINAMICTABLE_H
#define ADAPTIVEDINAMICTABLE_H

#include <vector>
#include <QWidget>
#include "DinamicTable.h"

class AdaptiveDinamicTable : public DinamicTable
{
    Q_OBJECT
public:
    explicit AdaptiveDinamicTable(int data_rows = 4, int data_columns = 4, int title_rows = 2, int title_cols = 3, QWidget* parent = nullptr);

    std::vector<bool> GetMaxSingsState() const;

    void AddActiveColumn() override;

protected:
    void CreateTitlesStile() override;

};

#endif // ADAPTIVEDINAMICTABLE_H

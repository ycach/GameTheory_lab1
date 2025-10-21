#ifndef DINAMICTABLE_H
#define DINAMICTABLE_H
#include <QTableWidget>
#include <QPushButton>

class DinamicTable : public QTableWidget{
    Q_OBJECT
public:
    DinamicTable(int active_rows = 4, int active_columns = 4, QWidget* parent = nullptr);
    ~DinamicTable() = default;

    void AddActiveRow();
    void RemoveActiveRow(int rowIndex);
    void AddActiveColumn();
    void RemoveActiveColumn(int colIndex);

    int GetTitleRows();
    int GetTitleColumns();

signals:
    void SignalColumnRemoved(int removedIndex);
    void SignalRowRemoved(int removedIndex);

private:
    int active_rows;
    int active_columns;

    int titles_rows = 2;
    int titles_columns = 1;



    void CreateTitlesStile();
    void CreateAddButtons();

};

class Title : public QWidget{
    Q_OBJECT
public:
    Title(int index, bool is_column, DinamicTable* parent = nullptr);
    ~Title() = default;


private:

    void UpdateIndex(int index);

    int index;
    bool is_column;
    DinamicTable* parent_table;
    QPushButton* dell_button;
};
#endif // DINAMICTABLE_H

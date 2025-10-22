#ifndef CASTOMRECORD_H
#define CASTOMRECORD_H

#include <ResultRecord.h>
#include "ChoseSing/AdaptiveDinamicTable.h"

class CastomRecord : public ResultRecord
{
public:
    CastomRecord(std::vector<double> result, std::vector<bool> min_max,const QString& title = "Результат расчета", QWidget* parent = nullptr);
    ~CastomRecord() = default;

protected:
    void CreateRecord() override;

private:
    std::vector<double> result;
    std::vector<bool> min_max_sings;
};

#endif // CASTOMRECORD_H

#ifndef CALCFUNCTIONS_H
#define CALCFUNCTIONS_H
#include <vector>
#include "MatrixData/Matrix.h"

namespace CalcFunc {
    std::vector<double> CalculateOptimalStrategy(Matrix<double> matrix, std::vector<bool> max_sings);
    std::vector<double> Maximize(std::vector<double> data);
    std::vector<double> Minimize(std::vector<double> data);
    double FunctionTarget(std::vector<double> sings, std::vector<double> weight);

}

#endif // CALCFUNCTIONS_H

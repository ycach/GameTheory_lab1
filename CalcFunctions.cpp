#include "CalcFunctions.h"
#include <algorithm>


std::vector<double> CalcFunc::CalculateOptimalStrategy(Matrix<double> matrix, std::vector<bool> max_sings){
    std::vector<std::vector<double>> sings;
    std::vector<double> weight = matrix.GetRow(matrix.GetRowsCount()-1);
    matrix.RemoveRow(matrix.GetRowsCount()-1);
    for(int i = 0; i < matrix.GetColumnsCount(); i++){
        if(max_sings[i]){
            std::vector<double> sing = Maximize(matrix.GetColumn(i));
            sings.push_back(sing);
        }else{
            std::vector<double> sing = Minimize(matrix.GetColumn(i));
            sings.push_back(sing);
        }
    }

    std::vector<std::vector<double>> transpose_sings;
    for(int i = 0; i < sings.size(); i++){
        std::vector<double> row;
        for(int j = 0; j < sings[0].size(); j++){
            row.push_back(sings[i][j]);
        }
        transpose_sings.push_back(row);
    }

    std::vector<double> result;
    for(int i = 0; i < transpose_sings.size(); i++){
        result.push_back(FunctionTarget(transpose_sings[i], weight));
    }

    return result;
}

std::vector<double> CalcFunc::Maximize(std::vector<double> data){
    auto max_it = std::max_element(data.begin(), data.end());
    double max_val = *max_it;

    std::vector<double> result;
    result.reserve(data.size());

    for (double elm : data) {
        if (max_val == 0.0) {
            result.push_back(0.0);
        } else {
            result.push_back(elm / max_val);
        }
    }
    return result;
}
std::vector<double> CalcFunc::Minimize(std::vector<double> data){
    auto max_it = std::max_element(data.begin(), data.end());
    double max_val = *max_it;

    std::vector<double> result;
    result.reserve(data.size());

    for (double elm : data) {
        if (max_val == 0.0) {
            result.push_back(0.0);
        } else {
            result.push_back(1 - (elm / max_val));
        }
    }

    return result;
}
double CalcFunc::FunctionTarget(std::vector<double> sings, std::vector<double> weight){
    double sum = 0.0;
    if(sings.size()==weight.size()){
        for(int i = 0; i < sings.size(); i++){
            sum+= sings[i] * weight[i];
        }
    }
    return sum;
}

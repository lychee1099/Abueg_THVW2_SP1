#ifndef CT_H
#define CT_H

#include <vector>

using std::vector;

struct Data_1D;
struct Data_2D;

class CentralTendency {
private:
    Data_1D* dataset_1_1D;
    Data_1D* dataset_2_1D;

    Data_2D* dataset_1_2D;
    Data_2D* dataset_2_2D;

    void mean_1D();
    void median_1D();
    void mode_1D();

    void mean_2D();
    void median_2D();
    void mode_2D();

public:
    CentralTendency(vector<double> ds1, vector<double> ds2);
    CentralTendency(vector<vector<double>> ds1, vector<vector<double>> ds2);
    ~CentralTendency();

    double mean(int n);
    double mean(int n, bool whole, int n_row);

    double median(int n);
    double median(int n, bool whole, int n_row);

    vector<double> mode(int n);
    vector<double> mode(int n, bool whole, int n_row);
};

#endif
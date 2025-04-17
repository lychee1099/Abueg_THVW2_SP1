#ifndef CROSSCORR_H
#define CROSSCORR_H

#include <vector>

using std::vector;

class CrossCorr {
private:
    vector<vector<double>> corr;

    vector<vector<double>> dataset_1;
    vector<vector<double>> dataset_2;
public:
    CrossCorr(vector<vector<double>> ds1, vector<vector<double>> ds2);

    void doCrossCorr();
    void setDatasets(vector<vector<double>> ds1, vector<vector<double>> ds2);
    const vector<vector<double>>& getCorr();
};

#endif
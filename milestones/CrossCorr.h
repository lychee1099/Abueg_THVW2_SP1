#ifndef CROSSCORR_H
#define CROSSCORR_H

#include <vector>

using std::vector;

class CrossCorr {
private:
    vector<vector<double>> corr;
public:
    CrossCorr(vector<vector<double>> ds1, vector<vector<double>> ds2);
    const vector<vector<double>>& getCorr();
};

#endif
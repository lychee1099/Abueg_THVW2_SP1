#ifndef LC_H
#define LC_H

#include <vector>

using std::vector;

// flip, multiply, accu, shift

// some observation stuff = resulting vector has size of (sum of size of 2 vecs) - 1

class LinearConv {
private:
    vector<double> convoluted;

public:
    LinearConv(vector<double> ds1, vector<double> ds2);
    ~LinearConv();

    const vector<double>& getConvolutedVector();
};

#endif
#include "LinearConv.h"

#include "DLL.h"

// checked using https://www.rapidtables.com/calc/math/convolution-calculator.html

LinearConv::LinearConv(vector<double> ds1, vector<double> ds2)
{
    DLL list1;
    DLL list2;

    int n = ds1.size() + ds2.size() - 1;

    ds1.resize(n);
    ds2.resize(n);

    // list1 "acts" as a queue; list2 "acts" as a stack
    for (int i = 0; i < n; i++) {
        list1.insertEnd(ds1[i]);
        list2.insertStart(ds2[i]);
    }

    convoluted.resize(n);

    double sum;
    for (int i = n - 1; i >= 0; i--) {
        sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += list1[j] * list2[j];
        }
        convoluted[i] = sum;

        // think of it as reverse dequeue then queue
        list1.popEnd();
        list1.insertStart(0);
    }
}

LinearConv::~LinearConv()
{
}

const vector<double> &LinearConv::getConvolutedVector()
{
    return convoluted;
}

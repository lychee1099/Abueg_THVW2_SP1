#include "LinearConv.h"

#include "DLL.h"

// checked using https://www.rapidtables.com/calc/math/convolution-calculator.html

LinearConv::LinearConv(vector<double> ds1, vector<double> ds2)
{
    setDatasets(ds1, ds2);
}

LinearConv::~LinearConv()
{}

void LinearConv::doLinearConv()
{
    // flip, multiply, accu, shift

    DLL list1;
    DLL list2;

    // some observation stuff = resulting vector has size of (sum of size of 2 vecs) - 1
    int n = dataset_1.size() + dataset_2.size() - 1;

    // pad both datasets with 0s
    dataset_1.resize(n);
    dataset_2.resize(n);

    // list1 "acts" as a queue; list2 "acts" as a stack
    for (int i = 0; i < n; i++) {
        list1.insertEnd(dataset_1[i]);
        
        // this flips the elements
        list2.insertStart(dataset_2[i]);
    }

    convoluted.resize(n);

    double sum;
    for (int i = n - 1; i >= 0; i--) {
        sum = 0.0;

        // multiply the elements of the lists and accumulate
        for (int j = 0; j < n; j++) {
            sum += list1[j] * list2[j];
        }
        convoluted[i] = sum;

        // think of this as reverse dequeue then queue
        // shift first DLL to right
        list1.popEnd();
        list1.insertStart(0);
    }
}

void LinearConv::setDatasets(vector<double> ds1, vector<double> ds2)
{
    dataset_1 = ds1;
    dataset_2 = ds2;
}

const vector<double> &LinearConv::getConvolutedVector()
{
    return convoluted;
}

#include "CrossCorr.h"

#include "DLL.h"

CrossCorr::CrossCorr(vector<vector<double>> ds1, vector<vector<double>> ds2)
{
    int n_corr_rows = ds1.size() - ds2.size() + 1;
    int n_corr_cols = ds1[0].size() - ds2[0].size() + 1;

    corr.resize(n_corr_rows);

    ds2.resize(ds1.size());

    DLL list1_flat;
    DLL list2_flat;
    // turn vec<vec> into vec<dll> with 0 paddings
    for (int i = 0; i < ds2.size(); i++) {
        int new_size = ds1[i].size();
        ds2[i].resize(new_size);

        for (int j = 0; j < new_size; j++) {
            list2_flat.insertEnd(ds2[i][j]);
            list1_flat.insertEnd(ds1[i][j]);
        }
    }

    // multiply and shift (the second vec)!
    // and pop vec1 (like a stack)

    // i think this whole loop is still O(n^2)
    double sum;
    for (int i = 0; i < n_corr_rows; i++) {
        DLL list2_flat_temp(list2_flat);
        sum = 0.0;

        corr[i].resize(n_corr_cols);

        for (int m = 0; m < n_corr_cols; m++) {
            for (int j = 0; j < list1_flat.getSize(); j++) {
                sum += list1_flat[j] * list2_flat_temp[j];
            }

            list2_flat_temp.popEnd();
            list2_flat_temp.insertStart(0);

            corr[i][m] = sum;
        }   

        for (int k = 0; k < ds1.size(); k++) {
            list1_flat.popFront();
            list1_flat.insertEnd(0);
        }
    }
}

const vector<vector<double>> &CrossCorr::getCorr()
{
    return corr;
}

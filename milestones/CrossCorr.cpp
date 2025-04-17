#include "CrossCorr.h"

#include "DLL.h"

CrossCorr::CrossCorr(vector<vector<double>> ds1, vector<vector<double>> ds2)
{
    setDatasets(ds1, ds2);
}

void CrossCorr::doCrossCorr()
{
    // get the dims of the resulting corr
    // ty induction
    int n_corr_rows = dataset_1.size() - dataset_2.size() + 1;
    int n_corr_cols = dataset_1[0].size() - dataset_2[0].size() + 1;

    corr.resize(n_corr_rows);

    // pads dataset_2 with 0s in the "row dimension"
    dataset_2.resize(dataset_1.size());

    DLL list1_flat;
    DLL list2_flat;
    
    for (int i = 0; i < dataset_2.size(); i++) {
        // pads dataset_2 with 0s in the "column dimension"
        int new_size = dataset_1[i].size();
        dataset_2[i].resize(new_size);

        for (int j = 0; j < new_size; j++) {
            list2_flat.insertEnd(dataset_2[i][j]);
            list1_flat.insertEnd(dataset_1[i][j]);
        }
    }

    // i think this whole loop is still O(n^2)
    double sum;
    for (int i = 0; i < n_corr_rows; i++) {
        // needs to preserve the original DLL for the next rows
        DLL list2_flat_temp(list2_flat);
        sum = 0.0;

        corr[i].resize(n_corr_cols);
        for (int m = 0; m < n_corr_cols; m++) {
            // multiply the elements of the flattened lists and accumulate
            for (int j = 0; j < list1_flat.getSize(); j++) {
                sum += list1_flat[j] * list2_flat_temp[j];
            }
            corr[i][m] = sum;

            // shift second DLL to right
            list2_flat_temp.popEnd();
            list2_flat_temp.insertStart(0);
        }   

        // shift first DLL to left
        for (int k = 0; k < dataset_1[i].size(); k++) {
            list1_flat.popFront();
            list1_flat.insertEnd(0);
        }
    }
}

void CrossCorr::setDatasets(vector<vector<double>> ds1, vector<vector<double>> ds2)
{
    dataset_1 = ds1;
    dataset_2 = ds2;
}

const vector<vector<double>> &CrossCorr::getCorr()
{
    return corr;
}

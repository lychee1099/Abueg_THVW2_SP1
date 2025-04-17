#include "CentralTendency.h"
#include "Sort.h"

#include <iostream>
using namespace std;

struct Data_1D {
    vector<double> dataset;
    double mean = 0.0;
    double median = 0.0;

    vector<double> mode = {};

    int size;
};

struct Data_2D {
    Data_1D flattened; // will contain cen ten of whole array

    vector<Data_1D> rows; // will contain cen ten of each row
    int n_rows;
};

// PRIVATE METHODS

// Get mean for 1D datasets
// Sum whole dataset then divide by its size
void CentralTendency::mean_1D()
{
    double sum = 0;
    if (dataset_1_1D->size != 0) {
        for (int i = 0; i < dataset_1_1D->size; i++) {
            sum += dataset_1_1D->dataset[i];
        }
        dataset_1_1D->mean = sum / dataset_1_1D->size;
    }

    sum = 0;
    if (dataset_2_1D->size != 0) {
        for (int i = 0; i < dataset_2_1D->size; i++) {
            sum += dataset_2_1D->dataset[i];
        }
        dataset_2_1D->mean = sum / dataset_2_1D->size;
    }
}

// Get median for 1D datasets
// Get the middle element of the sorted dataset
void CentralTendency::median_1D()
{
    int mid_index;

    if (dataset_1_1D->size != 0) {
        if (dataset_1_1D->size % 2 == 1) {
            mid_index = dataset_1_1D->size / 2;
            dataset_1_1D->median = dataset_1_1D->dataset[mid_index];
        } else {
            mid_index = dataset_1_1D->size / 2;
            dataset_1_1D->median = (dataset_1_1D->dataset[mid_index] + 
                dataset_1_1D->dataset[mid_index - 1]) / 2;
        }
    }  

    if (dataset_2_1D->size != 0) {
        if (dataset_2_1D->size % 2 == 1) {
            mid_index = dataset_2_1D->size / 2;
            dataset_2_1D->median = dataset_2_1D->dataset[mid_index];
        } else {
            mid_index = dataset_2_1D->size / 2;
            dataset_2_1D->median = (dataset_2_1D->dataset[mid_index] + 
            dataset_2_1D->dataset[mid_index - 1]) / 2;
        }
    }
}

// Get mode of 1D dataset
// Count no. of each element then put into vector if it is the greatest
void CentralTendency::mode_1D()
{
    // acts like a queue
    vector<double> possible_modes;
    int greatest = 0;

    int count = 1;
    double compare_with;

    if (dataset_1_1D->size != 0) {
        compare_with = dataset_1_1D->dataset[0];
        for (int i = 1; i < dataset_1_1D->size + 1; i++) {
            // Since dataset is sorted, same elements are placed together
            // So, we stop counting if the current element is not the same anymore
            // OR if it is past the last element (to check the last element)
            if (dataset_1_1D->dataset[i] != compare_with || i >= dataset_1_1D->size) {
                if (count > greatest) {
                    greatest = count;

                    possible_modes.clear();
                    possible_modes.push_back(compare_with); 
                } else if (count == greatest) {
                    possible_modes.push_back(compare_with);                
                }

                count = 1;
                compare_with = dataset_1_1D->dataset[i];
                continue;
            }

            count++;
        }

        dataset_1_1D->mode = possible_modes;
    }
    
    possible_modes.clear();
    greatest = 0;

    count = 1;
    if (dataset_2_1D->size != 0) {
        compare_with = dataset_2_1D->dataset[0];
        for (int i = 1; i < dataset_2_1D->size + 1; i++) {
            if (dataset_2_1D->dataset[i] != compare_with || i >= dataset_2_1D->size) {
                if (count > greatest) {
                    greatest = count;
                    possible_modes.clear();
                    possible_modes.push_back(compare_with); 
                } else if (count == greatest) {
                    possible_modes.push_back(compare_with);                
                }

                count = 1;
                compare_with = dataset_2_1D->dataset[i];
                continue;
            }

            count++;
        }

        dataset_2_1D->mode = possible_modes;
    }
}

// Get mean of 2D datasets
// For mean of whole dataset, you treat the flattened dataset as a 1D dataset and use mean func
// For mean of each row, treat each row as a 1D dataset and use the mean func
void CentralTendency::mean_2D()
{
    // mean of whole dataset
    CentralTendency whole(dataset_1_2D->flattened.dataset, dataset_2_2D->flattened.dataset);
    dataset_1_2D->flattened.mean = whole.mean(1);
    dataset_2_2D->flattened.mean = whole.mean(2);

    // mean of each row
    // two different loops since dataset 1 has lesser dimensions
    // since a CentralTendency for 1D datasets requires two datasets,
    // we define the second as an empty dataset
    for (int i = 0; i < dataset_1_2D->n_rows; i++) {
        CentralTendency each_row(dataset_1_2D->rows[i].dataset, {});
        dataset_1_2D->rows[i].mean = each_row.mean(1);
    }

    for (int i = 0; i < dataset_2_2D->n_rows; i++) {
        CentralTendency each_row(dataset_2_2D->rows[i].dataset, {});
        dataset_2_2D->rows[i].mean = each_row.mean(1);
    }
}

// Get median of 2D datasets
// For median of whole dataset, you treat the flattened dataset as a 1D dataset and use median func
// For median of each row, treat each row as a 1D dataset and use the median func
void CentralTendency::median_2D()
{
    // median of whole dataset
    CentralTendency whole(dataset_1_2D->flattened.dataset, dataset_2_2D->flattened.dataset);
    dataset_1_2D->flattened.median = whole.median(1);
    dataset_2_2D->flattened.median = whole.median(2);

    // median of each row
    // two different loops since dataset 1 has lesser dimensions
    // since a CentralTendency for 1D datasets requires two datasets,
    // we define the second as an empty dataset
    for (int i = 0; i < dataset_1_2D->n_rows; i++) {
        CentralTendency each_row(dataset_1_2D->rows[i].dataset, {});
        dataset_1_2D->rows[i].median = each_row.median(1);
    }

    for (int i = 0; i < dataset_2_2D->n_rows; i++) {
        CentralTendency each_row(dataset_2_2D->rows[i].dataset, {});
        dataset_2_2D->rows[i].median = each_row.median(1);
    }
}

// Get mode of 2D datasets
// For mode of whole dataset, you treat the flattened dataset as a 1D dataset and use mode func
// For mode of each row, treat each row as a 1D dataset and use the mode func
void CentralTendency::mode_2D()
{
    // mode of whole dataset
    CentralTendency whole(dataset_1_2D->flattened.dataset, dataset_2_2D->flattened.dataset);
    dataset_1_2D->flattened.mode = whole.mode(1);
    dataset_2_2D->flattened.mode = whole.mode(2);

    // mode of each row
    // two different loops since dataset 1 has lesser dimensions
    // since a CentralTendency for 1D datasets requires two datasets,
    // we define the second as an empty dataset
    for (int i = 0; i < dataset_1_2D->n_rows; i++) {
        CentralTendency each_row(dataset_1_2D->rows[i].dataset, {});
        dataset_1_2D->rows[i].mode = each_row.mode(1);
    }

    for (int i = 0; i < dataset_2_2D->n_rows; i++) {
        CentralTendency each_row(dataset_2_2D->rows[i].dataset, {});
        dataset_2_2D->rows[i].mode = each_row.mode(1);
    }
}

// PUBLIC METHODS

CentralTendency::CentralTendency(vector<double> ds1, vector<double> ds2)
{
    // sort
    // quicksort(&ds1.data()[0], &ds1.data()[ds1.size() - 1]);
    // quicksort(&ds2.data()[0], &ds2.data()[ds2.size() - 1]);

    merge_sort(&ds1.data()[0], &ds1.data()[ds1.size() - 1]);
    merge_sort(&ds2.data()[0], &ds2.data()[ds2.size() - 1]);

    dataset_1_1D = new Data_1D;
    dataset_2_1D = new Data_1D;

    dataset_1_1D->dataset = ds1;
    dataset_2_1D->dataset = ds2;

    dataset_1_1D->size = ds1.size();
    dataset_2_1D->size = ds2.size();

    dataset_1_2D = nullptr;
    dataset_2_2D = nullptr;
}

CentralTendency::CentralTendency(vector<vector<double>>& ds1, vector<vector<double>>& ds2)
{
    dataset_1_2D = new Data_2D;
    dataset_2_2D = new Data_2D;

    dataset_1_2D->n_rows = ds1.size();
    dataset_2_2D->n_rows = ds2.size();

    // flatten
    vector<double> flat1;
    for (int i = 0; i < dataset_1_2D->n_rows; i++) {
        for (int j = 0; j < ds1[i].size();j++) {
            flat1.push_back(ds1[i][j]);
        }
    }

    vector<double> flat2;
    for (int i = 0; i < dataset_2_2D->n_rows; i++) {
        for (int j = 0; j < ds2[i].size();j++) {
            flat2.push_back(ds2[i][j]);
        }
    }

    // sort
    // quicksort(&flat1.data()[0], &flat1.data()[flat1.size()-1]);
    // quicksort(&flat2.data()[0], &flat2.data()[flat2.size()-1]);

    merge_sort(&flat1.data()[0], &flat1.data()[flat1.size()-1]);
    merge_sort(&flat2.data()[0], &flat2.data()[flat2.size()-1]);

    // assign stuff
    dataset_1_2D->flattened.dataset = flat1;
    dataset_1_2D->flattened.size = flat1.size();

    dataset_2_2D->flattened.dataset = flat2;
    dataset_2_2D->flattened.size = flat2.size();

    // put flattened back to 2d arrays
    dataset_1_2D->rows.resize(dataset_1_2D->n_rows);
    for (int i = 0; i < dataset_1_2D->n_rows; i++) {
        for (int j = 0; j < ds1[i].size(); j++) {
            int index = 0;
            if (i > 0) {
                // adding an offset to access the ith row of the flattened array
                index = j + i * ds1[i-1].size();
            } else {
                index = j;
            }

            dataset_1_2D->rows[i].dataset.push_back(flat1[index]);    
        }
        dataset_1_2D->rows[i].size = ds1[i].size();
    }

    dataset_2_2D->rows.resize(dataset_2_2D->n_rows);
    for (int i = 0; i < dataset_2_2D->n_rows; i++) {
        for (int j = 0; j < ds2[i].size(); j++) {
            int index = 0;
            if (i > 0) {
                index = j + i * ds1[i-1].size();
            } else {
                index = j;
            }

            dataset_2_2D->rows[i].dataset.push_back(flat2[index]);    
        }
        dataset_2_2D->rows[i].size = ds2[i].size();
    }

    dataset_1_1D = nullptr;
    dataset_2_1D = nullptr;
}

CentralTendency::~CentralTendency()
{
    // wow no memory leaks?!?!
    if (dataset_1_1D && dataset_2_1D) {
        delete dataset_1_1D;
        delete dataset_2_1D;

        dataset_1_1D = nullptr;
        dataset_2_1D = nullptr;
    }

    if (dataset_1_2D && dataset_2_2D) {
        delete dataset_1_2D;
        delete dataset_2_2D;

        dataset_1_2D = nullptr;
        dataset_2_2D = nullptr;
    }
}

// public mean method for 1D datasets
double CentralTendency::mean(int n)
{
    if (dataset_1_1D && dataset_2_1D) {
        mean_1D();

        if (n == 1) {
            return dataset_1_1D->mean;
        } else if (n == 2) {
            return dataset_2_1D->mean;
        }
    }

    return 0.0;
}

// public mean method for 2D datasets
double CentralTendency::mean(int n, bool whole, int n_row)
{
    if (!(dataset_1_2D && dataset_2_2D)) {
        return 0.0;
    }

    mean_2D();

    if (n == 1) {
        if (whole) {
            return dataset_1_2D->flattened.mean;
        }
        return dataset_1_2D->rows[n_row].mean;
    } else if (n == 2) {
        if (whole) {
            return dataset_2_2D->flattened.mean;
        }
        return dataset_2_2D->rows[n_row].mean;
    } else {
        return 0.0;
    }
}

// public median method for 1D datasets
double CentralTendency::median(int n)
{
    if (dataset_1_1D && dataset_2_1D) {
        median_1D();

        if (n == 1) {
            return dataset_1_1D->median;
        } else if (n == 2) {
            return dataset_2_1D->median;
        }
    }
    return 0.0;
}

// public median method for 2D datasets
double CentralTendency::median(int n, bool whole, int n_row)
{
    if (!(dataset_1_2D && dataset_2_2D)) {
        return 0.0;
    }

    median_2D();
    if (n == 1) {
        if (whole) {
            return dataset_1_2D->flattened.median;
        }
        return dataset_1_2D->rows[n_row].median;
    } else if (n == 2) {
        if (whole) {
            return dataset_2_2D->flattened.median;
        }
        return dataset_2_2D->rows[n_row].median;
    } else {
        return 0.0;
    }
}

// public mode method for 1D datasets
vector<double> CentralTendency::mode(int n)
{
    if (dataset_1_1D && dataset_2_1D) {
        mode_1D();

        if (n == 1) {
            return dataset_1_1D->mode;
        } else if (n == 2) {
            return dataset_2_1D->mode;
        }
    }
    return vector<double>();
}

// public mode method for 2D datasets
vector<double> CentralTendency::mode(int n, bool whole, int n_row)
{
    if (!(dataset_1_2D && dataset_2_2D)) {
        return vector<double>();
    }

    mode_2D();
    if (n == 1) {
        if (whole) {
            return dataset_1_2D->flattened.mode;
        }
        return dataset_1_2D->rows[n_row].mode;
    } else if (n == 2) {
        if (whole) {
            return dataset_2_2D->flattened.mode;
        }
        return dataset_2_2D->rows[n_row].mode;
    } else {
        return vector<double>();
    }
}

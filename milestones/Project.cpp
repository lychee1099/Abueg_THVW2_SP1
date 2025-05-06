#include "Project.h"

#include "CentralTendency.h"
#include "LinearConv.h"
#include "CrossCorr.h"

#include <iostream>
using namespace std;

bool Project::askDim()
{
    cout << "1D or 2D? (Y/N): ";
    char resp;
    cin >> resp;

    if (toupper(resp) == 'Y') {
        dim = true;
        return true;
    } else if (toupper(resp) == 'N') {
        dim = false;
        return true;
    }

    cout << "Invalid input!" << endl;

    return false;
}

bool Project::process1D()
{
    int n1;
    int n2;

    cout << "----------------------------------------" << endl;
    cout << "Enter NO. OF ELEMENTS of first 1D dataset: ";
    cin >> n1;

    cout << "Enter NO. OF ELEMENTS of second 1D dataset: ";
    cin >> n2;

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of first 1D dataset (space separated or newline separated): ";

    vector<double> d1;
    double elem;
    for (int i = 0; i < n1; i++) {
        cin >> elem;
        d1.push_back(elem);
    }

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of second 1D dataset (space separated or newline separated): ";

    vector<double> d2;
    for (int i = 0; i < n2; i++) {
        cin >> elem;
        d2.push_back(elem);
    }

    cout << "----------------------------------------" << endl;

    CentralTendency ct(d1, d2);
    cout << "D1 mean: " << ct.mean(1) << "\nD1 median: " << ct.median(1) << "\nD1 mode(s): ";

    vector<double> modes = ct.mode(1);
    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << " ";
    }

    cout << endl << "----------------------------------------" << endl;

    cout << "D2 mean: " << ct.mean(2) << "\nD2 median: " << ct.median(2) << "\nD1 mode(s): ";

    modes = ct.mode(2);
    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << " ";
    }

    cout << endl << "----------------------------------------" << endl;

    cout << "Linear Convolution: ";

    LinearConv lc(d1, d2);
    lc.doLinearConv();
    vector<double> conv = lc.getConvolutedVector();
    cout << "[";
    for (int i = 0; i < conv.size(); i++) {
        cout << conv[i];
        if (i == conv.size() - 1) { continue; }
        cout << ", ";
    }
    cout << "]";

    cout << endl << "----------------------------------------" << endl;
    cout << "'Cross Corr': ";
    CrossCorr cc;
    if (d1.size() >= d2.size()) {
        cc = CrossCorr({d1}, {d2});
    } else {
        cc = CrossCorr({d2}, {d1});
    }
    
    cc.doCrossCorr();
    vector<vector<double>> corr = cc.getCorr();

    cout << "[ ";
    for (int i = 0; i < corr.size(); i++) {
        cout << "[";
        for (int j = 0; j < corr[i].size(); j++) {
            cout << corr[i][j];
            if (j == corr[i].size() - 1) { continue; }
            cout << ", ";
        }

        cout << "]"; 
        if (i == corr.size() - 1) { continue; }
        cout << "," << endl; 
    }
    cout << " ]";
    
    cout << endl << "----------------------------------------" << endl;

    return false;
}

bool Project::process2D()
{
    int n1;
    int m1;

    int n2;
    int m2;

    cout << "----------------------------------------" << endl;
    cout << "Enter NO. OF ROWS of first 2D dataset: ";
    cin >> n1;

    cout << "Enter NO. OF COLUMNS of first 2D dataset: ";
    cin >> m1;

    cout << "Enter NO. OF ROWS of second 2D dataset (should be less than or equal to the rows of first dataset): ";
    cin >> n2;

    cout << "Enter NO. OF COLUMNS of second 2D dataset (should be less than or equal to the cols of first dataset): ";
    cin >> m2;

    if (n2 > n1 || m2 > m1) {
        cout << "Either row or column of second 2D should be less than or equal to the rows/cols of first 2D dataset" << endl;
        return true;
    }

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of first 2D dataset (space separated or newline separated): ";

    vector<vector<double>> d1;
    d1.resize(n1);

    double elem;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            cin >> elem;
            d1[i].push_back(elem);
        }
    }

    cout << endl;

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of second 2D dataset (space separated or newline separated): ";

    vector<vector<double>> d2;
    d2.resize(n2);

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            cin >> elem;
            d2[i].push_back(elem);
        }
    }

    cout << "----------------------------------------" << endl;

    // whole dataset
    CentralTendency ct(d1, d2);
    cout << "D1 mean: " << ct.mean(1, true, 0) << "\nD1 median: " << ct.median(1, true, 0) << "\nD1 mode(s): ";

    vector<double> modes = ct.mode(1, true, 0);
    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << " ";
    }

    cout << endl << "----------------------------------------" << endl;

    // whole dataset
    cout << "D2 mean: " << ct.mean(2, true, 0) << "\nD2 median: " << ct.median(2, true, 0) << "\nD1 mode(s): ";

    modes = ct.mode(2, true, 0);
    for (int i = 0; i < modes.size(); i++) {
        cout << modes[i] << " ";
    }

    cout << endl << "----------------------------------------" << endl;

    // each row dataset 1
    cout << "EACH ROW OF D1" << endl;
    cout << "D1 mean: ";
    for (int i = 0; i < d1.size(); i++) {
        cout << ct.mean(1, false, i) << " ";
    }
    
    cout << "\nD1 median: ";
    for (int i = 0; i < d1.size(); i++) {
        cout << ct.median(1, false, i) << " ";
    }
    
    cout<< "\nD1 mode(s): ";
    for (int i = 0; i < d1.size(); i++) {
         modes = ct.mode(1, false, i);
         for (int i = 0; i < modes.size(); i++) {
            cout <<modes[i] << " ";
        }
        cout << "\n";
    }

    cout << endl << "----------------------------------------" << endl;

    // each row dataset 2
    cout << "EACH ROW OF D2" << endl;
    cout << "D2 mean: ";
    for (int i = 0; i < d2.size(); i++) {
        cout << ct.mean(2, false, i) << " ";
    }
    
    cout << "\nD2 median: ";
    for (int i = 0; i < d2.size(); i++) {
        cout << ct.median(2, false, i) << " ";
    }
    
    cout<< "\nD2 mode(s): ";
    for (int i = 0; i < d2.size(); i++) {
         modes = ct.mode(2, false, i);
         for (int i = 0; i < modes.size(); i++) {
            cout <<modes[i] << " ";
        }
        cout << "\n";
    }

    cout << endl << "----------------------------------------" << endl;
    cout << "Cross Corr: " << endl;

    CrossCorr cc(d1, d2);
    cc.doCrossCorr();
    vector<vector<double>> corr = cc.getCorr();

    cout << "[ ";
    for (int i = 0; i < corr.size(); i++) {
        cout << "[";
        for (int j = 0; j < corr[i].size(); j++) {
            cout << corr[i][j];
            if (j == corr[i].size() - 1) { continue; }
            cout << ", ";
        }

        cout << "]"; 
        if (i == corr.size() - 1) { continue; }
        cout << "," << endl; 
    }
    cout << " ]";

    cout << endl << "----------------------------------------" << endl;

    return false;
}

void Project::run(bool &flag)
{
    if (askDim()) {
        if (dim) {
            flag = process1D();
        } else {
            flag = process2D();
        }
    }
}
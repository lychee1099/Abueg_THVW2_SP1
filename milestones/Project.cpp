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

void Project::process1D()
{
    int n1;
    int n2;

    cout << "----------------------------------------" << endl;
    cout << "Enter NO. OF ELEMENTS of first 1D dataset: ";
    cin >> n1;

    cout << "Enter NO. OF ELEMENTS of second 1D dataset: ";
    cin >> n2;

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of first 1D dataset: ";

    vector<double> d1;
    double elem;
    for (int i = 0; i < n1; i++) {
        cin >> elem;
        d1.push_back(elem);
    }
    cout << endl;

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of second 1D dataset: ";

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

    cout << "Convoluted elements: ";

    LinearConv lc(d1, d2);
    vector<double> conv = lc.getConvolutedVector();
    for (int i = 0; i < conv.size(); i++) {
        cout << conv[i] << " ";
    }

    cout << endl << "----------------------------------------" << endl;
}

void Project::process2D()
{
    int n1;
    int m1;

    int n2;
    int m2;

    cout << "----------------------------------------" << endl;
    cout << "Enter NO. OF ROWS of first 1D dataset: ";
    cin >> n1;

    cout << "Enter NO. OF COLUMNS of first 1D dataset: ";
    cin >> m1;

    cout << "Enter NO. OF ROWS of second 1D dataset: ";
    cin >> n2;

    cout << "Enter NO. OF COLUMNS of second 1D dataset: ";
    cin >> m2;

    cout << "----------------------------------------" << endl;
    cout << "Enter ELEMENTS of first 1D dataset: ";

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
    cout << "Enter ELEMENTS of second 1D dataset: ";

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
    cout << "Cross Corr elements: ";

    CrossCorr cc(d1, d2);
    vector<vector<double>> corr = cc.getCorr();

    for (int i = 0; i < corr.size(); i++) {
        for (int j = 0; j < corr[i].size(); j++) {
            cout << corr[i][j] << " ";
        }
    }
    cout << endl << "----------------------------------------" << endl;
}

void Project::run(bool &flag)
{
    if (askDim()) {
        if (dim) {
            process1D();
            flag = false;
        } else {
            process2D();
            flag = false;
        }
    }
}
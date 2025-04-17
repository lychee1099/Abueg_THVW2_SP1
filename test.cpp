#include <iostream>

// #include "CentralTendency.h"
// #include "CrossCorr.h"
// #include "LinearConv.h"

using namespace std;

int main() {

    double test;
    cin >> test;
    cout << test;
    // vector<double> d1;
    // vector<double> d2;

    // d1 = {10, 10, 10, 3, 2, 1, 5, 4, 5, 6, 6};
    // d2 = {10, 10, 10, 2, 3, 1, 5, 4, 6, 7, 6, 7};

    // LinearConv lc(d1, d2);
    // vector<double> res = lc.getConvolutedVector();
    // for (int i = 0; i < res.size(); i++) {
    //     cout << res[i] << endl;
    // }

    // vector<vector<double>> d3;
    // vector<vector<double>> d4;
    
    // d3 = {
    //     {1, 2, 1},
    //     {1, 2, 3},
    //     {1, 2, 8}
    // };

    // d4 = {
    //     {1, 0},
    //     {1, -1}
    // };

    // CrossCorr cc(d3, d4);
    // vector<vector<double>> corr = cc.getCorr();

    // // cout << corr.size() << endl;
    // // cout << corr[0][0] << endl;

    // for (int i = 0; i < corr.size(); i++) {
    //     for (int j = 0; j < corr[i].size(); j++) {
    //         cout << corr[i][j] << endl;
    //     }
    // }

    // vector<double> d1;
    // vector<double> d2;

    // // d1 = {1, 2, 3, 4, 5, 5, 6, 6, 10, 10, 10};
    // // d2 = {1, 2, 3, 4, 5, 6, 6, 7, 7, 10, 10, 10};

    // d1 = {10, 10, 10, 3, 2, 1, 5, 4, 5, 6, 6};
    // d2 = {10, 10, 10, 2, 3, 1, 5, 4, 6, 7, 6, 7};
    // CentralTendency ct(d1, d2);

    // cout << "D1 mean: " << ct.mean(1) << "\n" 
    // << "D1 median: " << ct.median(1) << "\n" << "D1 mode(s): ";
    
    // vector<double> d1_mode = ct.mode(1);
    // for (int i = 0; i < d1_mode.size(); i++) {
    //     cout << d1_mode[i] << " ";
    // }
    // cout << endl;

    // cout << "D2 mean: " << ct.mean(2) << "\n" 
    // << "D2 median: " << ct.median(2) << "\n" << "D2 mode(s): ";
    
    // vector<double> d2_mode = ct.mode(2);
    // for (int i = 0; i < d2_mode.size(); i++) {
    //     cout << d2_mode[i] << " ";
    // }
    // cout << endl;

    // cout << endl;

    // vector<vector<double>> d3;
    // vector<vector<double>> d4;
    
    // // d3 = {
    // //     {1, 2, 3, 4},
    // //     {5, 6, 7, 8},
    // //     {9, 10, 11, 12},
    // //     {13, 14, 15, 16},
    // // };

    // // d4 = {
    // //     {17, 18, 19},
    // //     {20, 21, 22}
    // // };

    // d3 = {
    //     {5, 6, 7, 8},
    //     {1, 2, 3, 4},
    //     {13, 14, 15, 16},
    //     {9, 10, 11, 12},
    // };

    // d4 = {
    //     {20, 21, 22},
    //     {17, 18, 19},
    // };

    // CentralTendency ct2(d3, d4);
    // cout << "D3 mean: " << ct2.mean(1, true, 0) << "\n" 
    // << "D3 median: " << ct2.median(1, true, 0) << "\n" << "D3 mode(s): ";

    // vector<double> d3_mode = ct2.mode(1, true, 0);

    // for (int i = 0; i < d3_mode.size(); i++) {
    //     cout << d3_mode[i] << " ";
    // }
    // cout << endl;

    // cout << "D4 mean: " << ct2.mean(2, true, 0) << "\n" 
    // << "D4 median: " << ct2.median(2, true, 0) << "\n" << "D4 mode(s): ";

    // vector<double> d4_mode = ct2.mode(2, true, 0);

    // for (int i = 0; i < d4_mode.size(); i++) {
    //     cout << d4_mode[i] << " ";
    // }
    // cout << endl;
    // cout << endl;

    // cout << "each row\n";
    // cout << "D3 mean: ";
    // for (int i = 0; i < d3.size(); i++) {
    //     cout << ct2.mean(1, false, i) << " ";
    // }
    // cout << endl;

    // cout << "D3 median: ";
    // for (int i = 0; i < d3.size(); i++) {
    //     cout << ct2.median(1, false, i) << " ";
    // }
    // cout << endl;

    // cout << "D3 mode: ";
    // for (int i = 0; i < d3.size(); i++) {
    //      d3_mode = ct2.mode(1, false, i);
    //      for (int i = 0; i < d3_mode.size(); i++) {
    //         cout << d3_mode[i] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << endl;

    // cout << "D4 mean: ";
    // for (int i = 0; i < d4.size(); i++) {
    //     cout << ct2.mean(2, false, i) << " ";
    // }
    // cout << endl;

    // cout << "D4 median: ";
    // for (int i = 0; i < d4.size(); i++) {
    //     cout << ct2.median(2, false, i) << " ";
    // }
    // cout << endl;

    // cout << "D4 mode: ";
    // for (int i = 0; i < d4.size(); i++) {
    //      d4_mode = ct2.mode(2, false, i);
    //      for (int i = 0; i < d4_mode.size(); i++) {
    //         cout << d4_mode[i] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << endl;
    
}
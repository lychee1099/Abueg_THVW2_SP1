#ifndef SORT_H
#define SORT_H

// FROM WA3
void merge(double* low, double* mid, double* high);
void merge_sort(double* low, double* high);

double* partition(double* low, double* high);
void quicksort(double* low, double* high);

#endif
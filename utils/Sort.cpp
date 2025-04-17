#include "Sort.h"

// -- jezic thvw2

// REFERENCE: https://www.geeksforgeeks.org/merge-sort/ ; https://www.geeksforgeeks.org/quick-sort-algorithm/
// (ty geeksforgeeks)

// FROM WA3

// merge sort - recurse until one element; then sort and merge

// low - points to leftmost of split array;
// mid - points to middle; high - points to rightmost of split array; 
void merge(double* low, double* mid, double* high) {
    // split array into two
    int n_left = mid - low + 1;
    int n_right = high - mid;

    double* left = new double[n_left];
    double* right = new double[n_right];

    for (int i = 0; i < n_left; i++) {
        left[i] = *(i + low);
    }

    for (int i = 0; i < n_right; i++) {
        right[i] = *(i + mid + 1);
    }

    // compare the elements in two arrays then put the lower value to
    // the low pointer since it points to original array
    int i = 0;
    int j = 0;
    while (i < n_left && j < n_right) {
        if (left[i] <= right[j]) {
            *low = left[i];
            i++;
        }
        else if (right[j] <= left[i]) {
            *low = right[j];
            j++;
        }
        low++;
    }  

   // elements left in one of arrays will be copied; we know they are the highest elements
   while (i < n_left) {
    *low = left[i];
    i++;
    low++;
   }

   while (j < n_right) {
    *low = right[j];
    j++;
    low++;
   }

    delete[] left;
    delete[] right;
}

void merge_sort(double* low, double* high) {
    // high and low pointing to same element; one element left->sorted
    if (high - low <= 0) {
        return;
    }

    double* mid = low + (high - low) / 2;

    merge_sort(low, mid);
    merge_sort(mid + 1, high);
    merge(low, mid, high);
}


// quicksort
// partition - pick a pivot; all left of pivot is less than pivot; all right of pivot is greater than pivot

// low - points to leftmost of array;
// high - points to rightmost of split array
double* partition(double* low, double* high) {
    double* pivot = high;

    double* i = low;
    double* j = high;

    // move i to right until it is larger than pivot
    // move j to the left until it is smaller than pivot
    // swap if true
    //end if i and j overlap

    while (i < j) {
        if (*i > *pivot && *j < *pivot) {
            int temp = *i;
            *i = *j;
            *j = temp;
        }

        while (*i <= *pivot && i != pivot) {
            i++;
        }

        while (*j >= *pivot && j != low) {
            j--;
        }
    }

    double temp = *i;
    *i = *pivot;
    *pivot = temp;

    return i;
}

void quicksort(double* low, double* high) {
    // high and low pointing to same element; one element left->sorted
    if (high - low <= 0) {
        return;
    }

    double* pivot = partition(low, high);

    quicksort(low, pivot - 1);
    quicksort(pivot + 1, high);
}
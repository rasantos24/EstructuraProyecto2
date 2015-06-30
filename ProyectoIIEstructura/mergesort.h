#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
using namespace std;

class MergeSort
{
public:
    MergeSort(int arreglo[]);
    int a[90000];
    void fundo(const int bajo, const int medio, const int alto);
    void mergeSort(const int bajo, const int alto);
};

#endif // MERGESORT_H

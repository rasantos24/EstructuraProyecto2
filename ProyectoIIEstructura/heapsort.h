#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
using namespace std;

class HeapSort
{
public:
    HeapSort(int arreglo[]);
    int a[9000];
    void construir(int nada);
    void heapSort(int nudo);
    void maximo(int *a, int i, int n);
};


#endif // HEAPSORT_H

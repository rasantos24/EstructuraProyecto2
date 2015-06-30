#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
using namespace std;

class QuickSort
{
public:
    QuickSort(int arreglo[]);
    int a[9000];
    void quickSort(int izquierda, int derecha);
    int pivote(int izquierda, int derecha);
    void cambio(int& a, int& b);
    void noCambio(int& a, int& b);
    void imprimir(const int& N);
};

#endif // QUICKSORT_H

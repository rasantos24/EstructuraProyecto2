#ifndef INICIARSORT_H
#define INICIARSORT_H
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "mergesort.h"
#include "binsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "bubblesort.h"

using namespace std;

class IniciarSort
{
public:
    IniciarSort();
    int size;
    int arreglo[9000];
    int hipo[9000];
    MergeSort *Merge;
    QuickSort *Quick;
    HeapSort *Heap;
    BinSort *Bin;
    BubbleSort *Bubble;
    void iniciaQuickSort();
    void iniciaMergeSort();
    void iniciaBinSort();
    void iniciaBubbleSort();
    void iniciaHeapSort();
};

#endif // INICIARSORT_H

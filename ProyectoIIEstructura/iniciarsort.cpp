#include "iniciarsort.h"

IniciarSort::IniciarSort()
{
    srand(time(0));
    size = 9000;
    for(int i=0; i<size; i++)
    {
        arreglo[i]=1+(rand()%100);
        hipo[i]=1+(rand()%100);
    }

    Merge = new MergeSort(arreglo);
    Quick = new QuickSort(arreglo);
    Heap = new HeapSort(arreglo);
    Bin = new BinSort(arreglo);
    Bubble = new BubbleSort(arreglo);

}
void IniciarSort::iniciaQuickSort()
{
    Quick->quickSort(0,size-1);
}

void IniciarSort::iniciaMergeSort()
{
    Merge->mergeSort(0,size-1);
}

void IniciarSort::iniciaBubbleSort()
{
    Bubble->bubbleSort(size);
}

void IniciarSort::iniciaBinSort()
{
    Bin->binSort(size);
}

void IniciarSort::iniciaHeapSort()
{
    Heap->construir(size);
    Heap->heapSort(size);
}


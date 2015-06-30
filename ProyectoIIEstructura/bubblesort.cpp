#include "bubblesort.h"

BubbleSort::BubbleSort(int arreglo[])
{
    for(int i=0; i<9000; i++)
        a[i] = arreglo[i];
}

void BubbleSort::bubbleSort(int nada)
{
  for(int i=0; i<nada; ++i)
    for(int j=0; j<nada-i-1; ++j)
      if (a[j] > a[j+1])
      {
        int tempo = a[j];
        a[j] = a[j+1];
        a[j+1] = tempo;
      }
}

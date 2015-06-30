#include "heapsort.h"

HeapSort::HeapSort(int arreglo[])
{
    for(int i=0; i<9000; i++)
        a[i]=arreglo[i];
}

void HeapSort::maximo(int *a, int i, int n)
{
    int justo, tempo;
    tempo = a[i];
    justo = 2*i;
    while (justo <= n)
    {
        if(justo < n && a[justo+1] > a[justo])
            justo = justo+1;
        if(tempo > a[justo])
            break;
        else if(tempo <= a[justo])
        {
            a[justo/2] = a[justo];
            justo = 2*justo;
        }
    }
    a[justo/2] = tempo;
    return;
}
void HeapSort::heapSort(int nudo)
{
    int tempo;
    for (int i=nudo; i>=2; i--)
    {
        tempo = a[i];
        a[i] = a[1];
        a[1] = tempo;
        maximo(a, 1, i-1);
    }
}
void HeapSort::construir(int nada)
{
    for(int i=nada/2; i>=1; i--)
        maximo(a, i, nada);
}


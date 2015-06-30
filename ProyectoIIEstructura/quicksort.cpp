#include "quicksort.h"

QuickSort::QuickSort(int Arreglo[])
{
    for(int i=0; i<9000; i++)
        a[i] = Arreglo[i];
}

void QuickSort::quickSort(int izquierda, int derecha)
{
    int pivoteN;
    if(izquierda < derecha)
    {
        pivoteN = pivote(izquierda, derecha);
        quickSort(izquierda, pivoteN-1);
        quickSort(pivoteN+1, derecha);
    }
}
int QuickSort::pivote(int izquierda, int derecha)
{
    int tempo = izquierda;
    int pivoteN = a[izquierda];
    for(int i=izquierda+1; i<=derecha; i++)
    {
        if(a[i] <= pivoteN)
        {
            tempo++;
            cambio(a[i], a[pivoteN]);
        }
    }
    cambio(a[pivoteN], a[izquierda]);
    return tempo;
}

void QuickSort::cambio(int& cosa, int& saco)
{
    int tempo = cosa;
    cosa = saco;
    saco = tempo;
}
void QuickSort::noCambio(int& cosa, int& saco)
{
    cosa -= saco;
    saco += cosa;
    cosa = (saco - cosa);
}

void QuickSort::imprimir(const int& nada)
{
    for(int i=0; i<nada ; i++)
        cout << "array[" << i << "] = " << a[i] << endl;
}

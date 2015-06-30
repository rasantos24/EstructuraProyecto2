#include "mergesort.h"

MergeSort::MergeSort(int arreglo[])
{
    for(int i=0; i<9000; i++)
        a[i] = arreglo[i];
}
void MergeSort:: fundo(const int bajo, const int medio, const int alto)
{

    int *saco = new int[alto+1 - bajo];
    int hoy,ima,justo,kya;
    hoy=bajo;
    ima=0;
    justo=medio+1;

    while((hoy<=medio)&&(justo<=alto))
    {
        if(a[hoy]<=a[justo])
        {
            saco[ima]=a[hoy];
            hoy++;
        }
        else
        {
            saco[ima]=a[justo];
            justo++;
        }
        ima++;
    }

    if(hoy > medio)
    {
        for(kya=justo; kya<=alto; kya++)
        {
            saco[ima]=a[kya];
            ima++;
        }
    }
    else
    {
        for(kya=hoy; kya<=medio; kya++)
        {
            saco[ima]=a[kya];
            ima++;
        }
    }

    for(kya=0; kya<=alto-bajo; kya++)
        a[kya+bajo]=saco[kya];
    delete []saco;
}

void MergeSort::mergeSort(const int bajo, const int alto)
{
    int medio;
    if(bajo < alto)
    {
        medio = (bajo + alto) / 2;
        mergeSort(bajo, medio);
        mergeSort(medio+1, alto);
        fundo(bajo, medio, alto);
    }
}

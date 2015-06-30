#include "binsort.h"

BinSort::BinSort(int arreglo[])
{
    for(int i=0; i<9000; i++)
        a[i]=arreglo[i];
}

void BinSort::binSort(int nada)
{
  int mira = 501;

  int cubos[mira];

  for(int i=0; i<mira; ++i)
    cubos[i]=0;

  for(int i=0; i<nada; ++i)
    ++cubos[a[i]];

  for(int i=0, j=0; j<mira; ++j)
    for(int k=cubos[j]; k>0; --k)
      a[i++] = j;
}


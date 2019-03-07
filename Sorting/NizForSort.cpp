#include "NizForSort.h"
#include <malloc.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

NizForSort::NizForSort(int n)
{
	this->n = n;
	Niz = (int*)malloc(n * sizeof(int));
	this->sortiranje = nullptr;
}

NizForSort::~NizForSort()
{
	if (Niz != nullptr)
	{
		free(Niz);
	}
}



void NizForSort::Sort()
{
	if(sortiranje != nullptr)
	sortiranje(Niz, n);
}

void NizForSort::Printf()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << Niz[i] << " ";
	}
	cout << "END!" << endl;
}

void NizForSort::SetSort(void (*sortiranje)(int*, int))
{
	this->sortiranje = sortiranje;
}

void NizForSort::SetArray(int b[])
{
	Niz = b;
}

void NizForSort::LoadArray(string path)
{
	ifstream ulaz;
	ulaz.open(path);
	ulaz >> n;
	free(Niz);
	Niz = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		ulaz >> Niz[i];
	}
	ulaz.close();
}

void NizForSort::generate(int low, int high, int n)
{

	if (this->Niz != nullptr)
	{
		free(Niz);
	}

	Niz = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		Niz[i] = rand()%1000;
	}

}

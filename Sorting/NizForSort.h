#pragma once

#include<string>

using namespace std;

class NizForSort
{
public:
	NizForSort(int n);
	~NizForSort();

	void Sort();
	void Printf();
	void SetSort(void (*sortiranje)(int*, int));
	void SetArray(int b[]);
	void LoadArray(string path);
private:
	int* Niz;
	int n;
	void (*sortiranje)(int*, int);
};

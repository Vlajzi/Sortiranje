#include "NizForSort.h"
#include "SortingAlgorithms.h"
#include <iostream>
#include <chrono>
#include "windows.h"
#include "psapi.h"



using namespace std;
using namespace std::chrono;
using namespace Algoritmi;

void Racun(void (*sortiranje)(int*, int),int count);

int main(int argc, char* argv[])
{
	

	/*cout << "Selection"<<endl;
	Racun(SelectionSort);
	cout << "Insertion"<<endl;
	Racun(InsercionSort);
	cout << "Bubble" << endl;
	Racun(BubbleSort);*/
	/*cout << "Quick" << endl;
	Racun(QuickSort,1000);
	
	cout << "CountingSort" << endl;
	Racun(CountingSort, 1000);*/
	int numb = 100;
	for (int i = 0; i < 7; i++)
	{

		cout << "HeapSort" << endl;
		Racun(HeapSort, numb);
		cout << "BucketSort" << endl;
		Racun(BucketSort, numb);
		numb *= 10;
	}
	//return 0;


	

	return 0;
}



void Racun(void (*sortiranje)(int*, int),int count)
{
	NizForSort* n1;

	n1 = new NizForSort(10);
	n1->SetSort(sortiranje);
	//n1->LoadArray("C:\\Users\\Intel\\Desktop\\Test.txt");
	n1->generate(0, 1000, count);


	//n1->Printf();
	//time
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	n1->Sort();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), (PPROCESS_MEMORY_COUNTERS)&pmc, sizeof(pmc));
	SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;
	cout << "Total virtual memory used: " << virtualMemUsedByMe << endl;

	//time
	//n1->Printf();

	auto duration = duration_cast<nanoseconds>(t2 - t1).count();

	cout << duration << endl << "--KRAJ--" << endl;
}





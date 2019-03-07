#include "NizForSort.h"
#include "SortingAlgorithms.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
using namespace Algoritmi;

void Racun(void (*sortiranje)(int*, int));

int main(int argc, char* argv[])
{
	cout << "Selection"<<endl;
	Racun(SelectionSort);
	cout << "Insertion"<<endl;
	Racun(InsercionSort);
	cout << "Bubble" << endl;
	Racun(BubbleSort);
	cout << "Quick" << endl;
	Racun(QuickSort);
	cout << "HeapSort" << endl;
	Racun(HeapSort);
	cout << "CountingSort" << endl;
	Racun(CountingSort);
	cout << "BucketSort" << endl;
	Racun(BucketSort);
	return 0;
}



void Racun(void (*sortiranje)(int*, int))
{
	NizForSort* n1;

	n1 = new NizForSort(10);
	n1->SetSort(sortiranje);
	//n1->LoadArray("C:\\Users\\Intel\\Desktop\\Test.txt");
	n1->generate(0, 1000, 1000);


	//n1->Printf();
	//time
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	n1->Sort();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	//time
	//n1->Printf();

	auto duration = duration_cast<nanoseconds>(t2 - t1).count();

	cout << duration << endl << "--KRAJ--" << endl;
}





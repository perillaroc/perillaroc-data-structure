// windroc@BIT£¬2012.10.09
// ÅÅĞòËã·¨

#include "stdafx.h"

#include "insertion_sort.h"
<<<<<<< HEAD
=======
#include "exchange_sort.h"
>>>>>>> origin/master
#include "selection_sort.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void TestSortAlgorithm(std::vector<int>& data_array, void p(std::vector<int>&))
{
	ostream_iterator<int> output(cout," ");
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	p(data_array);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {-1,49,38,65,97,76,13,27,49};
	int a_count = sizeof(a)/sizeof(int);
	ostream_iterator<int> output(cout," ");

	vector<int> data_array(a,a+a_count);
	
	cout<<"StraightInsertionSort£º"<<endl;
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	InsertionSort::StraightInsertionSort(data_array);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"BinaryInsertionSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	InsertionSort::BinaryInsertionSort(data_array);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"ShellInsertionSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	InsertionSort::ShellInsertionSort(data_array);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"========================="<<endl;
	
	// ½»»»ÅÅĞò

	cout<<"BubbleSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
<<<<<<< HEAD
	SelectionSort::BubbleSort(data_array);
=======
	ExchangeSort::BubbleSort(data_array);
>>>>>>> origin/master
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"CocktailSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
<<<<<<< HEAD
	SelectionSort::CocktailSort(data_array);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"OddEvenSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	SelectionSort::OddEvenSort(data_array);
=======
	ExchangeSort::CocktailSort(data_array);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

    cout<<"CombSort"<<endl;
    data_array.assign(a,a+a_count);
    copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
    ExchangeSort::CombSort(data_array);
    copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"OddEvenSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
	ExchangeSort::OddEvenSort(data_array);
>>>>>>> origin/master
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"QuickSort"<<endl;
	data_array.assign(a,a+a_count);
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
<<<<<<< HEAD
	SelectionSort::QuickSort(data_array);
=======
	ExchangeSort::QuickSort(data_array);
>>>>>>> origin/master
	copy(data_array.begin()+1,data_array.end(),output);cout<<endl;

	cout<<"BogoSort"<<endl;
	data_array.assign(a,a+a_count);
<<<<<<< HEAD
	TestSortAlgorithm(data_array,SelectionSort::BogoSort);

	cout<<"========================="<<endl;

=======
	TestSortAlgorithm(data_array,ExchangeSort::BogoSort);

	cout<<"========================="<<endl;

    // Ñ¡ÔñÅÅĞò
    cout<<"SimpleSelectionSort"<<endl;
    data_array.assign(a,a+a_count);
    copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
    SelectionSort::SimpleSelectionSort(data_array);
    copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
    
    cout<<"HeapSort"<<endl;
    data_array.assign(a,a+a_count);
    copy(data_array.begin()+1,data_array.end(),output);cout<<endl;
    SelectionSort::HeapSort(data_array);
    copy(data_array.begin()+1,data_array.end(),output);cout<<endl;


>>>>>>> origin/master
	system("pause");
	return 0;
}


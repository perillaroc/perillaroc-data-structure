#include "selection_sort.h"
#include <algorithm>
#include <iostream>
using namespace std;
SelectionSort::SelectionSort(void)
{
}

SelectionSort::~SelectionSort(void)
{
}
// √∞≈›≈≈–Ú
void SelectionSort::BubbleSort( std::vector<int>& data_array )
{
	int num_count = data_array.size()-1;
	bool swapped = true;
	int i = 1;
	while(swapped && i<num_count)
	{
		// µ⁄iÃÀ
		swapped = false;
		for(int j=1;j<num_count-i+1; j++)
		{
			if (data_array[j]>data_array[j+1])
			{
				int t = data_array[j];
				data_array[j] = data_array[j+1];
				data_array[j+1] = t;
				swapped = true;
			}
		}
		i++;
	}
	return;
}

void SelectionSort::CocktailSort( std::vector<int>& data_array )
{
	int num_count = data_array.size()-1;
	int low = 1;
	int high = num_count;
	bool swapped = true;
	while(swapped)
	{
		swapped = false;
		for (int i=low; i<high; i++)
		{
			if (data_array[i]>data_array[i+1])
			{
				int t = data_array[i];
				data_array[i] = data_array[i+1];
				data_array[i+1] = t;
				swapped = true;
			}
		}
		high--;
		for(int i=high; i>low; i--)
		{
			if (data_array[i]<data_array[i-1])
			{
				int t = data_array[i];
				data_array[i] = data_array[i-1];
				data_array[i-1] = t;
				swapped = true;
			}
		}
		low++;
	}
	return;
}

// ∆Ê≈º≈≈–Ú
void SelectionSort::OddEvenSort( std::vector<int>& data_array )
{
	bool sorted = false;
	int num_count = data_array.size()-1;
	while(!sorted)
	{
		sorted = true;
		for(int i=1; i<=num_count-1; i+=2)
		{
			if (data_array[i]>data_array[i+1])
			{
				swap(data_array[i], data_array[i+1]);
				sorted = false;
			}
		}

		for(int i=2; i<=num_count-1; i+=2)
		{
			if (data_array[i]>data_array[i+1])
			{
				swap(data_array[i], data_array[i+1]);
				sorted = false;
			}
		}
	}
	return;
}


// øÏÀŸ≈≈–Ú£¨µ•ÃÀ
int SelectionSort::QuickSortPartition( std::vector<int>& data_array, int low, int high )
{
	int key = data_array[low];
	data_array[0] = data_array[low];
	while(low<high)
	{
		while(low<high && data_array[high]>=key) --high;
		data_array[low] = data_array[high];
		while(low<high && data_array[low]<=key) ++low;
		data_array[high] = data_array[low];
	}
	data_array[low] = data_array[0];
	return low;
}

// øÏÀŸ≈≈–Ú£¨µ›πÈÀ„∑®
void SelectionSort::QuickSort( std::vector<int>& data_array, int low, int high )
{
	if(low<high)
	{
		int p = QuickSortPartition(data_array,low,high);
		QuickSort(data_array,low,p-1);
		QuickSort(data_array,p+1,high);
	}
}

// øÏÀŸ≈≈–Ú
void SelectionSort::QuickSort( std::vector<int>& data_array)
{
	QuickSort(data_array,1,data_array.size()-1);
}

// Bogo≈≈–Ú
void SelectionSort::BogoSort( std::vector<int>& data_array )
{
	int i = 0;
	while (!BogoSortInOrder(data_array))
	{
		i++;
		BogoSortRandomSwap(data_array);
	}
	cout<<"swap times:"<<i<<endl;
	return;
}

bool SelectionSort::BogoSortInOrder( std::vector<int>& data_array )
{
	int i = 1;
	int num_count = data_array.size()-1;
	while(i<num_count && data_array[i]<=data_array[i+1]) i++;
	if(i==num_count) return true;
	else return false;
}

void SelectionSort::BogoSortRandomSwap( std::vector<int>& data_array )
{
	int num_count = data_array.size()-1;
	for (int i=1; i<=num_count; i++)
	{
		int pos = rand()%num_count + 1;
		swap(data_array[i],data_array[pos]);
	}
}


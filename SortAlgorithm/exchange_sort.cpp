#include "exchange_sort.h"
#include <algorithm>
#ifdef WINDROC_DEBUG
#include <iostream>
#endif
using namespace std;
ExchangeSort::ExchangeSort(void)
{
}

ExchangeSort::~ExchangeSort(void)
{
}
// √∞≈›≈≈–Ú
void ExchangeSort::BubbleSort( std::vector<int>& data_array )
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

void ExchangeSort::CocktailSort( std::vector<int>& data_array )
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

void ExchangeSort::CombSort( std::vector<int>& data_array )
{
    double shrink_factor = 1.247330950103979;
    int num_count = data_array.size()-1;
    int gap = num_count;
    int swapped = true;
    while (gap>=1 && swapped)
    {
        swapped = false;
        if (gap>1) gap = gap/shrink_factor;
        for (int i=gap+1;i<=num_count;i++)
        {
            if (data_array[i]<data_array[i-gap])
            {
                swap(data_array[i],data_array[i-gap]);
                swapped = true;
            }
        }
    }
    return;
}


// ∆Ê≈º≈≈–Ú
void ExchangeSort::OddEvenSort( std::vector<int>& data_array )
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
int ExchangeSort::QuickSortPartition( std::vector<int>& data_array, int low, int high )
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
void ExchangeSort::QuickSort( std::vector<int>& data_array, int low, int high )
{
	if(low<high)
	{
		int p = QuickSortPartition(data_array,low,high);
		QuickSort(data_array,low,p-1);
		QuickSort(data_array,p+1,high);
	}
}

// øÏÀŸ≈≈–Ú
void ExchangeSort::QuickSort( std::vector<int>& data_array)
{
	QuickSort(data_array,1,data_array.size()-1);
}

// Bogo≈≈–Ú
void ExchangeSort::BogoSort( std::vector<int>& data_array )
{
	int i = 0;
	while (!BogoSortInOrder(data_array))
	{
		i++;
		BogoSortRandomSwap(data_array);
	}
#ifdef WINDROC_DEBUG
	cout<<"swap times:"<<i<<endl;
#endif
	return;
}

bool ExchangeSort::BogoSortInOrder( std::vector<int>& data_array )
{
	int i = 1;
	int num_count = data_array.size()-1;
	while(i<num_count && data_array[i]<=data_array[i+1]) i++;
	if(i==num_count) return true;
	else return false;
}

void ExchangeSort::BogoSortRandomSwap( std::vector<int>& data_array )
{
	int num_count = data_array.size()-1;
	for (int i=1; i<=num_count; i++)
	{
		int pos = rand()%num_count + 1;
		swap(data_array[i],data_array[pos]);
	}
}



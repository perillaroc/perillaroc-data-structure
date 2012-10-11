#include "selection_sort.h"
#include <algorithm>
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> origin/master
using namespace std;
SelectionSort::SelectionSort(void)
{
}

SelectionSort::~SelectionSort(void)
{
}
<<<<<<< HEAD
// ð������
void SelectionSort::BubbleSort( std::vector<int>& data_array )
{
	int num_count = data_array.size()-1;
	bool swapped = true;
	int i = 1;
	while(swapped && i<num_count)
	{
		// ��i��
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

// ��ż����
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


// �������򣬵���
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

// �������򣬵ݹ��㷨
void SelectionSort::QuickSort( std::vector<int>& data_array, int low, int high )
{
	if(low<high)
	{
		int p = QuickSortPartition(data_array,low,high);
		QuickSort(data_array,low,p-1);
		QuickSort(data_array,p+1,high);
	}
}

// ��������
void SelectionSort::QuickSort( std::vector<int>& data_array)
{
	QuickSort(data_array,1,data_array.size()-1);
}

// Bogo����
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

=======

// ��ѡ������
void SelectionSort::SimpleSelectionSort( std::vector<int>& data_array )
{
    int array_size = data_array.size()-1;
    for (int i=1; i<=array_size; i++)
    {
        int pos = SimpleSelectionSortSelectMin(data_array,i);
        if (pos!=i)
            swap(data_array[i],data_array[pos]);
    }
    return;
}

int SelectionSort::SimpleSelectionSortSelectMin( std::vector<int>& data_array,int start_pos, int end_pos /*= -1*/ )
{
    if (end_pos == -1)
        end_pos = data_array.size()-1;
    int min_value = data_array[start_pos];
    int min_pos = start_pos;
    for (int i=start_pos+1;i<=end_pos;i++)
    {
        if (data_array[i]<min_value)
        {
            min_value = data_array[i];
            min_pos = i;
        }
    }
    return min_pos;
}

void SelectionSort::HeapSort( std::vector<int>& data_array )
{
    int size = data_array.size() - 1;
    for (int i = size/2;i>0;i--) // 
        HeapSortAdjustMaxHeap(data_array,i,size);
    for(int i=size; i>1; i--)
    {
        swap(data_array[1],data_array[i]);
        HeapSortAdjustMaxHeap(data_array,1,i-1);
    }
    return;
}

// data_array[start_pos...end_pos]�У�start_posԪ�����򲻶ԣ�������Ԫ�ص�λ��
void SelectionSort::HeapSortAdjustMaxHeap( std::vector<int>& data_array, int start_pos, int end_pos )
{
    int a = data_array[start_pos];
    for(int i = start_pos*2; i <= end_pos; i*=2)
    {
        if(i<end_pos && data_array[i]<data_array[i+1]) i++;
        if(!(a<data_array[i])) break;
        data_array[start_pos] = data_array[i];
        start_pos = i;
    }
    data_array[start_pos] = a;
}
>>>>>>> origin/master

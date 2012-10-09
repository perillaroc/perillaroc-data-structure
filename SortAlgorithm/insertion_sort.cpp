#include "insertion_sort.h"
using namespace std;
InsertionSort::InsertionSort(void)
{
}

InsertionSort::~InsertionSort(void)
{
}

void InsertionSort::StraightInsertionSort( std::vector<int>& data_array )
{
	int t = data_array[0];
	int total_num_count_plus_1 = data_array.size();
	for(int i=2; i != total_num_count_plus_1; i++)
	{
		if (data_array[i]<data_array[i-1])
		{
			data_array[0] = data_array[i];
			data_array[i] = data_array[i-1];
			int j;
			for (j = i-2; data_array[0]<data_array[j]; j--)
				data_array[j+1] = data_array[j];
			data_array[j+1] = data_array[0];
		}
	}
	data_array[0] = t;
	return;
}

// ÕÛ°ë²éÕÒ
void InsertionSort::BinaryInsertionSort( std::vector<int>& data_array )
{
	int total_number_count_plus_1 = data_array.size();
	for(int i=2; i!=total_number_count_plus_1; i++)
	{
		if (data_array[i]<data_array[i-1])
		{
			data_array[0] = data_array[i];
			int low = 1;
			int high = i-1;
			while(low<=high)
			{
				int mid = (low+high)/2;
				if(data_array[0]<data_array[mid])
					high = mid-1;
				else
					low = mid+1;
			}
			for (int j=i-1;j>=high+1; j--)
				data_array[j+1] = data_array[j];
			data_array[high+1] = data_array[0];
		}
	}
	return;
}

// Ï£¶ûÅÅĞò£¬Ä¬ÈÏ²½³¤ĞòÁĞ
void InsertionSort::ShellInsertionSort( std::vector<int>& data_array )
{
	vector<int> step_array;
	for(int i=data_array.size()/2; i>=1; i/=2)
		step_array.push_back(i);
	ShellInsertionSort(data_array,step_array);
	return;
}

// Ï£¶ûÅÅĞò
void InsertionSort::ShellInsertionSort( std::vector<int>& data_array, std::vector<int>& step_array )
{
	for (vector<int>::iterator b = step_array.begin(); b!=step_array.end(); b++)
	{
		ShellInsertionSortSingle(data_array,*b);
	}
	return;
}
// µ¥²½Ï£¶ûÅÅĞò
void InsertionSort::ShellInsertionSortSingle( std::vector<int>& data_array, int step )
{
	int num_count_plus_one = data_array.size();
	for(int i=step+1; i<num_count_plus_one; i++)
	{
		if (data_array[i]<data_array[i-step])
		{
			data_array[0] = data_array[i];
			int j;
			for (j=i-step; j>0 && data_array[0]<data_array[j]; j-=step)
				data_array[j+step] = data_array[j];
			data_array[j+step] = data_array[0];
		}
	}
}

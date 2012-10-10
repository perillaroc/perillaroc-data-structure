#include "selection_sort.h"
#include <algorithm>
using namespace std;
SelectionSort::SelectionSort(void)
{
}

SelectionSort::~SelectionSort(void)
{
}

// 简单选择排序
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

// data_array[start_pos...end_pos]中，start_pos元素排序不对，调整该元素的位置
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

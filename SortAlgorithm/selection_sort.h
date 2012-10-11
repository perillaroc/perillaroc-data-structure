#pragma once
#include <vector>

// ѡ������
class SelectionSort
{
public:
    SelectionSort(void);
    virtual ~SelectionSort(void);
    
    // ��ѡ������
    static void SimpleSelectionSort(std::vector<int>& data_array);

    static int SimpleSelectionSortSelectMin(std::vector<int>& data_array,int start_pos, int end_pos = -1);

    // ������
    static void HeapSort(std::vector<int>& data_array);
    
    // �󶥶�
    static void HeapSortAdjustMaxHeap(std::vector<int>& data_array, int start_pos, int end_pos);
};

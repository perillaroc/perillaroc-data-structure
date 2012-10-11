#pragma once
#include <vector>

// —°‘Ò≈≈–Ú
class SelectionSort
{
public:
    SelectionSort(void);
    virtual ~SelectionSort(void);
    
    // ºÚµ•—°‘Ò≈≈–Ú
    static void SimpleSelectionSort(std::vector<int>& data_array);

    static int SimpleSelectionSortSelectMin(std::vector<int>& data_array,int start_pos, int end_pos = -1);

    // ∂—≈≈–Ú
    static void HeapSort(std::vector<int>& data_array);
    
    // ¥Û∂•∂—
    static void HeapSortAdjustMaxHeap(std::vector<int>& data_array, int start_pos, int end_pos);
};

#pragma once

#include <vector>

// 插入排序
// 数据用vector<int>表示，且从下标1开始，0作为哨兵元素
class InsertionSort
{
public:
	InsertionSort(void);
	virtual ~InsertionSort(void);

	// 直接插入排序
	static void StraightInsertionSort(std::vector<int>& data_array);

	// 折半插入排序
	static void BinaryInsertionSort(std::vector<int>& data_array);

	// 2-路插入排序
	//static void TwoRoadInsertionSort(std::vector<int>& data_array);

	// 表插入排序
	//static void TableInsertionSort(std::vector<int>& data_array);
	
	// 希尔排序
	static void ShellInsertionSort(std::vector<int>& data_array);
	static void ShellInsertionSort(std::vector<int>& data_array, std::vector<int>& step_array);
	static void ShellInsertionSortSingle(std::vector<int>& data_array, int step);

	// Library Sort

	// ... Sort
	
private:
	
};

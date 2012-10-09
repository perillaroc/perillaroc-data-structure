#pragma once
#include <vector>
// 选择排序
// 基本操作：交换
class SelectionSort
{
public:
	SelectionSort(void);
	virtual ~SelectionSort(void);

	// 冒泡排序
	static void BubbleSort(std::vector<int>& data_array);

	// 鸡尾酒排序
	// http://zh.wikipedia.org/wiki/%E9%B8%A1%E5%B0%BE%E9%85%92%E6%8E%92%E5%BA%8F
	// 鸡尾酒排序等于是冒泡排序的轻微变形。不同的地方在于从低到高然后从高到低，
	// 而冒泡排序则仅从低到高去比较序列里的每个元素。他可以得到比冒泡排序稍微
	// 好一点的效能，原因是冒泡排序只从一个方向进行比对(由低到高)，每次循环只
	// 移动一个项目。
	static void CocktailSort(std::vector<int>& data_array);

	// 奇偶排序
	// http://zh.wikipedia.org/wiki/%E5%A5%87%E5%81%B6%E6%8E%92%E5%BA%8F
	// 奇偶排序法的思路是在数组中重复两趟扫描。第一趟扫描选择所有的数据项对，
	// a[j]和a[j+1]，j是奇数(j=1, 3, 5……)。如果它们的关键字的值次序颠倒，
	// 就交换它们。第二趟扫描对所有的偶数数据项进行同样的操作(j=2, 4,6……)。
	// 重复进行这样两趟的排序直到数组全部有序。
	// 可用于并行计算，每对数据是独立的。
	static void OddEvenSort(std::vector<int>& data_array);

	// 快速排序
	static void QuickSort(std::vector<int>& data_array);
	// 快速排序，递归算法
	static void QuickSort(std::vector<int>& data_array, int low, int high);
	// 快速排序，单趟
	static int QuickSortPartition(std::vector<int>& data_array, int low, int high);

	// Bogo排序
	// http://zh.wikipedia.org/wiki/Bogo%E6%8E%92%E5%BA%8F
	// 这个排序有意思。
	// Bogo排序（bogo-sort）是个既不实用又原始的排序算法，其原理等同将一堆卡片抛起，
	// 落在桌上后检查卡片是否已整齐排列好，若非就再抛一次。
	// 又名猴子排序。无限猴子定理的表述如下：让一只猴子在打字机上随机地按键，当按
	// 键时间达到无穷时，几乎必然能够打出任何给定的文字，比如莎士比亚的全套著作。
	static void BogoSort(std::vector<int>& data_array);
	// 判断是否已经排好序
	static bool BogoSortInOrder(std::vector<int>& data_array);
	// 随机交换
	static void BogoSortRandomSwap(std::vector<int>& data_array);

};

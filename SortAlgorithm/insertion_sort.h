#pragma once

#include <vector>

// ��������
// ������vector<int>��ʾ���Ҵ��±�1��ʼ��0��Ϊ�ڱ�Ԫ��
class InsertionSort
{
public:
	InsertionSort(void);
	virtual ~InsertionSort(void);

	// ֱ�Ӳ�������
	static void StraightInsertionSort(std::vector<int>& data_array);

	// �۰��������
	static void BinaryInsertionSort(std::vector<int>& data_array);

	// 2-·��������
	//static void TwoRoadInsertionSort(std::vector<int>& data_array);

	// ���������
	//static void TableInsertionSort(std::vector<int>& data_array);
	
	// ϣ������
	static void ShellInsertionSort(std::vector<int>& data_array);
	static void ShellInsertionSort(std::vector<int>& data_array, std::vector<int>& step_array);
	static void ShellInsertionSortSingle(std::vector<int>& data_array, int step);

	// Library Sort

	// ... Sort
	
private:
	
};

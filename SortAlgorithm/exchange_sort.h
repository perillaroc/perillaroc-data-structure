#pragma once
#include <vector>
// ѡ������
// ��������������
class ExchangeSort
{
public:
	ExchangeSort(void);
	virtual ~ExchangeSort(void);

	// ð������
	static void BubbleSort(std::vector<int>& data_array);

	// ��β������
	// http://zh.wikipedia.org/wiki/%E9%B8%A1%E5%B0%BE%E9%85%92%E6%8E%92%E5%BA%8F
	// ��β�����������ð���������΢���Ρ���ͬ�ĵط����ڴӵ͵���Ȼ��Ӹߵ��ͣ�
	// ��ð����������ӵ͵���ȥ�Ƚ��������ÿ��Ԫ�ء������Եõ���ð��������΢
	// ��һ���Ч�ܣ�ԭ����ð������ֻ��һ��������бȶ�(�ɵ͵���)��ÿ��ѭ��ֻ
	// �ƶ�һ����Ŀ��
	static void CocktailSort(std::vector<int>& data_array);

    // ������
    // http://zh.wikipedia.org/wiki/%E6%A2%B3%E6%8E%92%E5%BA%8F
    // ˼����ϣ����������
    // ��������ĭ����Ϳ���������Ҫּ���������ڹ꣬�༴������β����С��ֵ��
    // ��Щ��ֵ�������ĭ��������������Եأ����ӣ��༴������ǰ�˵Ĵ���ֵ��
    // ��Ӱ����ĭ�����Ч�ܡ�
    // 
    // ����ĭ�����У�ֻ�Ƚ����������ڵĶ�����������
    // �˼����ʵ�ɴ���1�����Բ��������ϣ������ͬ�������ͬ�۵㡣
    // �������У���ʼʱ�ļ���趨Ϊ���г��ȣ�����ѭ�����Թ̶�
    // ���ʵݼ���ͨ���ݼ����趨Ϊ1.3����һ��ѭ���У���������ͬ��ĭ����һ������
    // �д��׵�βɨ��һ�Σ��Ƚϼ����������ͬ��������ļ�಻�̶���1�������
    // ��ݼ���1��������ٶ��������д�������ã�������ĭ����������鼰������
    static void CombSort(std::vector<int>& data_array);

	// ��ż����
	// http://zh.wikipedia.org/wiki/%E5%A5%87%E5%81%B6%E6%8E%92%E5%BA%8F
	// ��ż���򷨵�˼·�����������ظ�����ɨ�衣��һ��ɨ��ѡ�����е�������ԣ�
	// a[j]��a[j+1]��j������(j=1, 3, 5����)��������ǵĹؼ��ֵ�ֵ����ߵ���
	// �ͽ������ǡ��ڶ���ɨ������е�ż�����������ͬ���Ĳ���(j=2, 4,6����)��
	// �ظ������������˵�����ֱ������ȫ������
	// �����ڲ��м��㣬ÿ�������Ƕ����ġ�
	static void OddEvenSort(std::vector<int>& data_array);

	// ��������
	static void QuickSort(std::vector<int>& data_array);
	// �������򣬵ݹ��㷨
	static void QuickSort(std::vector<int>& data_array, int low, int high);
	// �������򣬵���
	static int QuickSortPartition(std::vector<int>& data_array, int low, int high);

	// Bogo����
	// http://zh.wikipedia.org/wiki/Bogo%E6%8E%92%E5%BA%8F
	// �����������˼��
	// Bogo����bogo-sort���Ǹ��Ȳ�ʵ����ԭʼ�������㷨����ԭ����ͬ��һ�ѿ�Ƭ����
	// �������Ϻ��鿨Ƭ�Ƿ����������кã����Ǿ�����һ�Ρ�
	// ���������������޺��Ӷ����ı������£���һֻ�����ڴ��ֻ�������ذ���������
	// ��ʱ��ﵽ����ʱ��������Ȼ�ܹ�����κθ��������֣�����ɯʿ���ǵ�ȫ��������
	static void BogoSort(std::vector<int>& data_array);
	// �ж��Ƿ��Ѿ��ź���
	static bool BogoSortInOrder(std::vector<int>& data_array);
	// �������
	static void BogoSortRandomSwap(std::vector<int>& data_array);

};
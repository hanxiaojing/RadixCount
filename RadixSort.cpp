#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<assert.h>


void Print(int*  a,int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}


int MaxRadix(int* a, int size)
{
	int radix = 10;
	int count = 1;
	int i = 0;
	for (int i = 0; i<size; i++)
	{
		while (a[i] > radix)
		{
			radix *= 10;
			count++;
		}
	}
	
	return count;
}


void _PartRadix(int* a, int size,int divisor)
{
	int count[10] = { 0 };

	//处理数组count，统计每个数据的个、十、百等位出现的个数
	for (int i = 0; i < size; i++)
	{
		int num = a[i] / divisor;
		count[num % 10]++;
	}

	//处理数组start，统计每个元素的起始位置
	int start[10] = { 0 };
	for (int i = 1; i < 10; i++)
	{
		start[i] = start[i - 1] + count[i - 1];
	}

	//遍历数组a,将这些元素放在tmp的计算好的位置上
	int* tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		int num = a[i] / divisor;
		tmp[start[num % 10]++] = a[i];//若该位有重复数，则加加坐标向起始位置的后面放即可
	}

	//拷回个位或十位或百位排序好的数组，开始下一个位的排序
	for (int i = 0; i < size; i++)
	{
		a[i] = tmp[i];
	}
}

void RadixSort(int* a, int size)
{
	assert(a);
	for (int i = 1; i <= MaxRadix(a, size);i++)
	{
		int divisor = 1;//获得除数，便于依次得到数据个位、十位、百位……
		int k = i;
		while (--k)
		{
			divisor *= 10;
		}
		_PartRadix(a, size, divisor);

	}
}

void TestRadixSort()
{
	int a[] = { 12, 34, 12222, 4568, 26, 1, 16, 10, 2, 4, 4, 93, 7, 5, 2, 4 };
	RadixSort(a, sizeof(a) / sizeof(a[0]));
	Print(a,sizeof(a)/sizeof(a[0]));

}


int main()
{
	TestRadixSort();
	system("pause");
	return 0;
}
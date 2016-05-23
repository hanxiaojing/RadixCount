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

	//��������count��ͳ��ÿ�����ݵĸ���ʮ���ٵ�λ���ֵĸ���
	for (int i = 0; i < size; i++)
	{
		int num = a[i] / divisor;
		count[num % 10]++;
	}

	//��������start��ͳ��ÿ��Ԫ�ص���ʼλ��
	int start[10] = { 0 };
	for (int i = 1; i < 10; i++)
	{
		start[i] = start[i - 1] + count[i - 1];
	}

	//��������a,����ЩԪ�ط���tmp�ļ���õ�λ����
	int* tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		int num = a[i] / divisor;
		tmp[start[num % 10]++] = a[i];//����λ���ظ�������Ӽ���������ʼλ�õĺ���ż���
	}

	//���ظ�λ��ʮλ���λ����õ����飬��ʼ��һ��λ������
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
		int divisor = 1;//��ó������������εõ����ݸ�λ��ʮλ����λ����
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
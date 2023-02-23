/************************希尔排序***********************/
template <typename T> void shellsort(T data[], int n)
{
	int i, j, flag, counter = 1, gap = n;
	T temp;
	while (gap > 1)
	{
		gap = gap / 2; //采用 shell 增量取法，每次增量减半
		do {
			flag = 0; //子序列排序采用冒泡排序法
			for (i = 0; i <= n - gap - counter; i++)
			{
				j = i + gap;
				if (data[i] > data[j])
				{
					exchange(&data[i], &data[j]);
					flag = 1;
				}
			}
		} while (counter < n && flag == 1);
	}
}
/********************交换函数*************************/
template<typename T> void exchange(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//案例
//对数据集{32,26,15,89,87,100,654,54,33,26}进行希尔排序，并输出结果。
#include <iostream> 
#include "shellsort.h" 
using namespace std;
/************************希尔排序***********************/
template <typename T> void shellsort(T data[], int n)
{
	int i, j, flag, counter = 1, gap = n;
	T temp;
	while (gap > 1)
	{
		gap = gap / 2; //采用 shell 增量取法，每次增量减半
		do {
			flag = 0; //子序列排序采用冒泡排序法
			for (i = 0; i <= n - gap - counter; i++)
			{
				j = i + gap;
				if (data[i] > data[j])
				{
					exchange(&data[i], &data[j]);
					flag = 1;
				}
			}
		} while (counter < n && flag == 1);
	}
}
/**************************值交换函数**************************/
template<typename T> void exchange(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int data[10] = { 32,26,15,89,87,100,654,54,33,26 };
	cout << "排序前数据：" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	shellsort(data, 10);
	cout << "排序后数据：" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
//快速排序是一种运用分治思想的算法
/************快速排序算法***********************/
template <class T>
void quickSort(T data[], int p, int r)
{
	int position = 0;
	if (p < r)
	{
		position = partition(data, p, r); //返回划界元素的最终位置
		quickSort(data, p, position - 1); //对划分的子序列进行递归操作
		quickSort(data, position + 1, r);
	}
}
/*************序列划分函数**********************/
template<class T> int partition(T data[], int p, int r)
{
	Int position;
	T temp = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (data[j] <= temp) //发现小于划界元素的键值时
		{ //交换元素 i+1 和元素 j 的值
			i += 1;
			exchange(&data[i], &data[j]);
		}

	}
	exchange(&data[i + 1], &data[r]);
	return i + 1;
}
/**************元素值交换函数*******************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//案例
//有一个数组（23,56,44,32,78,2,10），用快速排序算法进行排序，并输出排序后的数组
/************快速排序算法***********************/
template <class T>
void quickSort(T data[], int p, int r)
{
	int position = 0;
	if (p < r)
	{
		position = partition(data, p, r); //返回划界元素的最终位置
		quickSort(data, p, position - 1); //对划分的子序列进行递归操作
		quickSort(data, p + 1, r);
	}
}
/*************序列划分函数**********************/
template<class T> int partition(T data[], int p, int r)
{
	Int position;
	T temp = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (data[j] <= temp) //发现小于划界元素的键值时
		{ //交换元素 i+1 和元素 j 的值
			i += 1;
			exchange(&data[i], &data[j]);
		}

	}
	exchange(&data[i + 1], &data[r]);
	return i + 1;
}
/**************元素值交换函数*******************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int data[] = { 23,56,44,32,78,2,10 };
	int length = 7;
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	quickSort(data, 0, 6);
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

//编写一个 C++程序，将数组{2,5,7,8,3,6,11,24,0,1}按从大到小的顺序排列
#include <iostream> 
#include "quicksort.h"
using namespace std;
/***********我们只列出改动的函数部分，未改动的部分参见上题***************/
/*************改进的序列划分函数**********************/
template<class T> int partition(T data[], int p, int r)
{
	int position;
	T temp = data[p];
	int i = r + 1;
	for (int j = r; j > p; j--)
	{
		if (data[j] <= temp) //发现小于划界元素的键值时
		{ //交换元素 i+1 和元素 j 的值
			i -= 1;
			exchange(&data[i], &data[j]);
		}
	}
	exchange(&data[i - 1], &data[p]);
	return i - 1;
}
int main()
{
	int data[] = { 2,5,7,8,3,6,11,24,0,1 };
	int length = 10;
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	quickSort(data, 0, 9); //表明首尾元素的序号
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

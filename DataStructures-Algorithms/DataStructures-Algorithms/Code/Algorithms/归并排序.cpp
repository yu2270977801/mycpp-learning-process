/********合并函数************/
template <class T>
void merge(T A[], T B[], T C[], int lengthA, int lengthB)
//lengthA 和 lengthB 分别表示 A 和 B 的长度
{
	int i = 0, j = 0, counter = 0; //i，j 和 counter 分别为数组 A，B 和 C 的游标
	while (counter < lengthA + lengthB)
	{
		if (A[i] < B[j]) //判断 A 和 B 中相应元素的大小
		{
			C[counter] = A[i]; //将较小的元素先放入 C 中
			i++;
			counter++;
		}
		else {
			C[counter] = B[j];
			j++;
			counter++;
		}
		if (i == lengthA) //判断数组 A 是否遍历完成，游标是否到 A 的末尾
		{
			while (j < lengthB) //如果 A 遍历完成且 B 未完成
			{
				C[counter] = B[j]; //将 B 中剩余的元素依次存入 C 中剩下的位置
				j++;
				counter++;
			}
		}
		else if (j == lengthB)
			//如果 B 完成而 A 未完成，则将 A 中剩下的元素依次存入 C 中剩下的位置
		{
			while (i < lengthA)
			{
				C[counter] = A[i];
				i++;
				counter++;
			}
		}
	}
}
/*****************归并排序算法****************/
template<class T>
void mergeSort(T A[], int n)
{
	if (n > 1)
	{
		int i = n / 2;
		int j = n - n / 2;
		T B[n / 2];
		T C[n - n / 2];
		for (int k = 0; k < i; k++) //当 n>1 时，将数组分划成子序列
			B[k] = A[k];
		for (int k = 0; k < j; k++)
			C[k] = A[k + i];
		mergeSort(B, i); //对每个子序列递归进行归并排序
		mergeSort(C, j);
		merge(B, C, A, i, j); //合并有序的子序列
	}
}

//案例
//用 C++语言编写一个程序，将数组{23,25,48,73,12,82,75,30,16}从小到大排序，并输出结果
#include <iostream> 
#include "mergesort.h" 
using namespace std;
/********合并函数************/
template <class T>
void merge(T A[], T B[], T C[], int lengthA, int lengthB)
//lengthA 和 lengthB 分别表示 A 和 B 的长度
{
	int i = 0, j = 0, counter = 0; //i，j 和 counter 分别为数组 A，B 和 C 的游标
	while (counter < lengthA + lengthB)
	{
		if (A[i] < B[j]) //判断 A 和 B 中相应元素的大小
		{ //将较小的元素先放入 C 中
			C[counter] = A[i];
			i++;
			counter++;
		}
		else {
			C[counter] = B[j];
			j++;
			counter++;
		}
		if (i == lengthA) //判断数组 A 是否遍历完成，游标是否到 A 的末尾
		{
			while (j < lengthB) //如果 A 遍历完成且 B 未完成
			{ //将 B 中剩余的元素依次存入 C 中剩下的位置
				C[counter] = B[j];
				j++;
				counter++;
			}
		}
		else if (j == lengthB)
		{
			while (i < lengthA)
				//如果 B 完成而 A 未完成，则将 A 中剩下的元素依次存入 C 中剩下的位置
			{
				C[counter] = A[i];
				i++;
				counter++;
			}
		}
	}
}
/*****************归并排序算法****************/
template<class T>
void mergeSort(T A[], int n)
{
	if (n > 1)
	{
		int i = n / 2;
		int j = n - n / 2;
		T B[n / 2];
		T C[n - n / 2];
		for (int k = 0; k < i; k++) //当 n>1 时，将数组分划成子序列
			B[k] = A[k];
		for (int k = 0; k < j; k++)
			C[k] = A[k + i];
		mergeSort(B, i); //对每个子序列递归进行归并排序
		mergeSort(C, j);
		merge(B, C, A, i, j); //合并有序的子序列
	}
}
int main()
{
	int data[9] = { 23,25,48,73,12,82,75,30,16 };
	cout << "排序前数据序列：" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	mergeSort(data, 9);
	cout << "排序后结果：" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
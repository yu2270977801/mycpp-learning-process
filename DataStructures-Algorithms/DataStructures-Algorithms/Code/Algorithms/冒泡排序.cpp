//冒泡排序主要思想是：扫描所有数据，两两比较，发现违反轻气泡在重气泡之下原则的数，交换其位置，让重气泡下沉，轻气泡上浮。
/******定义元素交换函数********/
template<typename keytype>
void swap(keytype* a, keytype* b)
{
	keytype temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/******冒泡排序算法************/
template <typename keytype>
void bubbleSort(keytype data[], int n)
{
	int flag; //设置交换标志
	int i = 1, j;
	do { //初始化标志值为 0 
		for (j = 0; j + 1 < n; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]); //交换两个元素的值
				flag = 1; //将标志值改为 1，表明本趟排序中发生了元素交换动作
			}
		}
		i++;
	} while (i < n && flag == 1); //当 i<n 且本趟排序进行了数据交换的时候才继续循环
}

//案例
//有一个整数型数组{23,43,23,19,87,65,78,90,7,10}，实现一个 C++程序，用冒泡排序算法对该数组排序，并输出结果。
#include <iostream> 
using namespace std;
void bubbleSort(int[], int);
void swap(int*, int*);
int main()
{
	int data[10] = { 23,43,23,19,87,65,78,90,7,10 };
	cout << "排序前的数组为：" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	bubbleSort(data, 10);
	cout << "排序后的数组为：" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
/*****************交换函数********************/
/*************交换两数的值****************/
void swap(int* a, int* b)
{
	/*********************根据定理 a = a^b^b*****************************/
	/*****************利用按位与运算交换两数的值，省去中间变量***************/
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
/**************************冒泡排序算法函数*************************/
void bubbleSort(int data[], int n)
{
	int flag;
	int i = 1, j;
	do
	{
		flag = 0;
		for (j = 0; j + 1 < n; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
				flag = 1;
			}
		}
		i++;
	} while (i < n && flag == 1);
}


//按从大到小的顺序排序{25,30,16,87,89,102,1,23}并输出结果。
#include <iostream> 
using namespace std;
template<typename T> void bubbleSort(T[], int n); //声明冒泡排序算法函数
int main()
{
	int d[8] = { 25,30,16,87,89,102,1,23 };
	cout << "原数组的元素值为：" << endl;
	for (int i = 0; i < 8; i++)
		cout << d[i] << " ";
	cout << endl;
	bubbleSort2(d, 8);
	cout << "排序后数组的元素值为：" << endl;
	for (int i = 0; i < 8; i++)
		cout << d[i] << " ";
	cout << endl;
	return 0;
}
/*************************冒泡排序算法***********************/
template <typename T> void bubbleSort(T data[], int n)
{
	int flag = 1;
	int i = n - 1, j = 0;
	T temp;
	while (i > 0 && flag == 1)
	{
		flag = 0;
		for (j = 0; j + 1 <= i; j++)
		{
			if (data[j] < data[j + 1]) //将值较大的元素往前移，实现从大到小地排列
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				flag = 1;
			}
		}
		i--;
	}
}









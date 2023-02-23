/****************************计数排序***************************/
template <class T> void countingSort(T* ar, int n)
{
	int i, //循环计数
		k, //数组 B 的长度
		dx = 0; //反向填充目标数组时的位置标识
	T max = ar[0], //待排数组中的最大值
		mini = ar[0]; //待排数组中的最小值
	for (i = 1; i < n; i++) //找出待排数组中的最大、最小值
	{
		if (ar[i] > max)
			max = ar[i];
		else if (ar[i] < mini)
			mini = ar[i];
	}
	k = max - mini + 1; //根据最大、最小值计算 k 
	int* b = (int*)malloc(k * sizeof(int)); //创建数组 B 
	for (i = 0; i < k; i++) //初始化数组 B 
	{
		b[i] = 0;
	}
	for (i = 0; i < n; i++) //统计每个元素的个数
	{
		b[ar[i] - mini]++;
	}
	for (i = 0; i < k; i++) //反向填充目标数组
	{
		while ((b[i]--) > 0)
		{
			ar[idx++] = i + mini;
		}
	}
	free(b); //释放数组 b 
}

//案例
//利用计数排序对数据集{30,54,87,98,86,34,25,55,41,67,45,32,26,22}排序
#include <cstdlib> 
#include <iostream> 
using namespace std;
template <class T> void countingSort(T* ar, int n)
{
	int i, //循环计数
		k, //数组 B 的长度
		dx = 0; //反向填充目标数组时的位置标识
	T max = ar[0], //待排数组中的最大值
		mini = ar[0]; //待排数组中的最小值
	for (i = 1; i < n; i++) //找出待排数组中的最大、最小值
	{
		if (ar[i] > max)
			max = ar[i];
		else if (ar[i] < mini)
			mini = ar[i];
	}
	k = max - mini + 1; //根据最大、最小值计算 k 
	int* b = (int*)malloc(k * sizeof(int)); //创建数组 B 
	for (i = 0; i < k; i++) //初始化数组 B 
	{
		b[i] = 0;
	}
	for (i = 0; i < n; i++) //统计每个元素的个数
	{
		b[ar[i] - mini]++;
	}
	for (i = 0; i < k; i++) //反向填充目标数组
	{
		while ((b[i]--) > 0)
		{
			ar[idx++] = i + mini;
		}
	}
	free(b); //释放数组 b 
}
int main()
{
	int data[] = { 30,54,87,98,86,34,25,55,41,67,45,32,26,22 };
	cout << "排序前数据：" << endl;
	for (int i = 0; i < 14; i++)
		cout << data[i] << " ";
	cout << endl;
	countingSort(data, 14);
	cout << "排序后数据：" << endl;
	for (int i = 0; i < 14; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
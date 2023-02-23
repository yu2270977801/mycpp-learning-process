//采用自排序有冒泡排序算法的方式
#include <cmath> 
using namespace std;
/**************************基数排序算法******************************/
template <class T> void radixSort(T data[], int n, int d)
/********设置 3 个参数，data 为待排序数组，n 为数组元素个数，d 为所有元素的最多位数
***********/
{
	int weight = 10; //设置基本权值
	int i = 1;
	int flag = 1; //设置标志位
	while (i <= d)
	{
		int j = 1;
		int currentWeight = static_cast<int>(pow(weight, i));
		int diviceWeight = static_cast<int>(pow(weight, i - 1));
		//获取元素的第 k 位值，需要 data[j]对 weight 的 i 次方求模再除以 weight 的 i-1 次方
		/*********对每一位上数的子排序我们采用冒泡排序算法*********/
		do
		{
			flag = 0;
			for (int k = 0; k + 1 < n; k++)
			{
				if (data[k] % currentWeight / diviceWeight >
					data[k + 1] % currentWeight / diviceWeight)
				{
					T temp = data[k];
					data[k] = data[k + 1];
					data[k + 1] = temp;
					flag = 1;
				}
			}
			j++;
		} while ((j < n) && (flag == 1));
		i++;
	}
}

//为了优化运行时间，也可以采用空间换时间的策略，下面使我们采用链表结构实现的算法
void radixSort(int data[], int n, int d, int w)
/*****data 为待排序数组，n 为元素个数，d 为元素最大位数********/
{
	int* temp = new int[n]; //临时数组存储每趟排序的中间数据
	int* count = new int[w];
	//存储每一位相同元素个数的临时数组，weight 表示数据的权即进制
	int i, j, k;
	int degree = 1;
	//开始排序，共排序 d 趟
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < w; j++) //将记录元素每位同值数的数组初始化
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++) //统计每一位上相同值的元素个数
		{
			k = (data[j] / degree) % 10; //求各位上的值
			count[k]++;
		}
		for (j = 1; j < w; j++)//根据同位值的数量计算在原数组中各组值的结束位置
		{
			count[j] = count[j] + count[j - 1];
		}
		for (j = n - 1; j >= 0; j--) //从后往前依次将各组的值放入临时数组中
		{
			k = data[j] / degree % 10;
			count[k]--;
			temp[count[k]] = data[j];
		}
		for (j = 0; j < n; j++) //将数组复制到原数组中
			data[j] = temp[j];
		degree = degree * 10; //提升当前排序的权值，更新排序位
	}
	delete[] temp; //释放临时数组内存
	delete[] count;
}

//案例
//用基数排序对数组{35,64,88,87,896,354,15,64,1}排序
#include<iostream> 
#include "radixsort.h" 
using namespace std;
void radixSort(int data[], int n, int d, int w)
{
	int* temp = new int[n];
	int* count = new int[w];
	//存储每一位相同元素个数的临时数组，weight 表示数据的权即进制
	int i, j, k;
	int degree = 1;
	//开始排序，共排序 d 趟
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < w; j++)
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++)
		{
			k = (data[j] / degree) % 10; //求各位上的值
			count[k]++;
		}
		for (j = 1; j < w; j++)
			//根据同位值的数量计算在原数组中各组值的结束位置
		{
			count[j] = count[j] + count[j - 1];
		}
		for (j = n - 1; j >= 0; j--) //从后往前依次将各组的值放入临时数组中
		{
			k = data[j] / degree % 10;
			count[k]--;
			temp[count[k]] = data[j];
		}
		for (j = 0; j < n; j++)
			data[j] = temp[j];
		degree = degree * 10;
	}
	delete[] temp;
	delete[] count;
}
int main()
{
	int data[9] = { 35,64,88,87,896,354,15,64,1 };
	cout << "排序前的数据：" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	radixSort(data, 9, 3, 10);
	cout << "排序后的数据：" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
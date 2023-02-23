/**********************选择排序*****************************/
template <class T> void selectionsort(T data[], int n)
{
	int i = 1, j; //i 表示排序的趟数
	int max; //记录每趟排序中最大元素的位置
	T temp;
	while (i <= n - 1)
	{
		max = n - i; //将 max 初始化为待排元素的最末位置
		for (j = 0; j < n - i + 1; j++)
		{
			if (data[j] > data[max]) //寻找待排元素中最大元素的位置
				max = j;
		}
		if (max != n - i) //将最大元素交换到待排元素的末尾 
		{
			temp = data[max];
			data[max] = data[n - i];
			data[n - i] = temp;
		}
		i++;
	}
}

//案例
//利用选择排序算法对字母 E，X，A，M，P，L，E 按字母表排序
#include <iostream> 
using namespace std;
template <class T> void selectionsort(T data[], int n)
{
	int i = 1, j;
	int max; //记录每趟排序中最大元素的位置
	T temp;
	while (i <= n - 1)
	{
		max = n - i; //将 max 初始化为待排元素的最末位置
		for (j = 0; j < n - i + 1; j++)
		{
			if (data[j] > data[max]) //寻找待排元素中最大元素的位置
				max = j;
		}
		if (max != n - i) //将最大元素交换到待排元素的末尾 
		{
			temp = data[max];
			data[max] = data[n - i];
			data[n - i] = temp;
		}
		i++;
	}
}
int main()
{
	char data[] = { 'E','X','A','M','P','L','E' };
	cout << "排序前数据：" << endl;
	for (int i = 0; i < 7; i++)
		cout << data[i] << " ";
	cout << endl;
	selectionsort(data, 7);
	cout << "排序后数据：" << endl;
	for (int i = 0; i < 7; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

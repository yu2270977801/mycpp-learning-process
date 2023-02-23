//要进行堆排序算法有 3 个基本的操作，即建堆、保持堆性质和元素交换
/***************************保持堆特性函数***********************/
template<class T> void keepHeap(T data[], int heap_size, int k)
/******data 为要排序的数组，heap_size 为堆元素个数，k 为新加入元素的位置*****/
{
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int largest = k;
	if (left < heap_size && data[left] > data[k])
		//判断结点 k 与其左孩子结点的大小
	{
		largest = left;
	}
	if (right < heap_size && data[right] > data[largest])
		//判断结点 k 与其右孩子结点的大小
		largest = right;
	if (largest != k)
	{
		exchange(&data[k], &data[largest]);
		keepHeap(data, heap_size, largest);
		//对移动到新位置上的结点 k 递归进行保持堆性质操作
	}
}
/*****************************建堆函数****************************/
template <class T> void buildHeap(T data[], int heap_size)
{
	int i = heap_size / 2 - 1;
	while (i >= 0)
	{
		keepHeap(data, heap_size, i); //对每个结点递归调用 keepHeap 建堆
		i--;
	}
}
/**********************堆排序函数******************************/
template<class T> void heapSort(T data[], int n)
{
	int heap_size = n;
	buildHeap(data, heap_size);
	for (int i = heap_size - 1; i > 0; i--)
	{
		exchange(&data[0], &data[i]);
		heap_size = heap_size - 1;
		keepHeap(data, heap_size, 0);
	}
}
/***************************交换函数***************************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//案例
//用堆排序算法{64,56,34,58,97,76,99,25}排序，并输出结果
#include <iostream> 
using namespace std;
template<class T> void keepHeap(T data[], int heap_size, int k)
/*******data 为要排序的数组，heap_size 为堆元素个数，k 为新加入元素的位置*******/
{
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int largest = k;
	if (left < heap_size && data[left] > data[k])
		//判断结点 k 与其左孩子结点的大小
	{
		largest = left;
	}
	if (right < heap_size && data[right] > data[largest])
		//判断结点 k 与其右孩子结点的大小
		largest = right;
	if (largest != k)
	{
		exchange(&data[k], &data[largest]);
		keepHeap(data, heap_size, largest);
		//对移动到新位置上的结点 k 递归进行保持堆性质操作
	}
}
/**************************建堆函数*******************************/
template <class T> void buildHeap(T data[], int heap_size)
{
	int i = heap_size / 2 - 1;
	while (i >= 0)
	{
		keepHeap(data, heap_size, i); //对每个结点递归调用 keepHeap 建堆
		i--;
	}
}
/***********************堆排序函数*********************************/
template<class T> void heapSort(T data[], int n)
{
	int heap_size = n;
	buildHeap(data, heap_size);
	for (int i = heap_size - 1; i > 0; i--)
	{
		exchange(&data[0], &data[i]);
		heap_size = heap_size - 1;
		keepHeap(data, heap_size, 0);
	}
}
/************************交换函数**************************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int data[] = { 64,56,34,58,97,76,99,25 };
	cout << "排序前的数据：" << endl;
	for (int i = 0; i < 8; i++)
		cout << data[i] << " ";
	cout << endl;
	heapSort(data, 8);
	cout << "排序后的数据：" << endl;
	for (int i = 0; i < 8; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

//设计一个函数，判断一个数组是否具有堆性质
#include <iostream> 
using namespace std;
/********************判断一个数组是不是大根堆******************/
template <typename T> bool isHeap(T* data, int n)
{
	int i = 0;
	int parent;
	for (i = 0; i <= n / 2 - 1; i++)
		//根据二叉完全树的性质，根结点只存在于数组的前一半中
	{
		parent = i;
		if (data[parent] < data[parent * 2]
			|| data[parent] < data[parent * 2 + 1])
			//判断根结点与孩子结点的大小
		{
			return false;
		}
	}
	return true;
}
/****************建堆函数*******************/
template <class T> void buildHeap(T data[], int heap_size)
{
	int i = heap_size / 2 - 1;
	while (i >= 0) //从数组中间的数开始向前依次调整使每个元素保持堆特性
	{
		keepHeap(data, heap_size, i);
		i--;
	}
}
int main()
{
	int data[] = { 64,56,34,58,97,76,99,25 };
	cout << "判断数组是不是大根堆:" << endl;
	cout << "建堆前：" << endl;
	if (isHeap(data, 8))
		cout << "数组是大根堆" << endl;
	else
		cout << "数组不是大根堆" << endl;
	cout << "建堆后:" << endl;
	buildHeap(data, 8);
	if (isHeap(data, 8))
		cout << "数组是大根堆" << endl;
	else
		cout << "数组不是大根堆" << endl;
	return 0;
}
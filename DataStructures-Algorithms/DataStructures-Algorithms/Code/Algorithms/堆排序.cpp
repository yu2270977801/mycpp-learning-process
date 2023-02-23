//Ҫ���ж������㷨�� 3 �������Ĳ����������ѡ����ֶ����ʺ�Ԫ�ؽ���
/***************************���ֶ����Ժ���***********************/
template<class T> void keepHeap(T data[], int heap_size, int k)
/******data ΪҪ��������飬heap_size Ϊ��Ԫ�ظ�����k Ϊ�¼���Ԫ�ص�λ��*****/
{
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int largest = k;
	if (left < heap_size && data[left] > data[k])
		//�жϽ�� k �������ӽ��Ĵ�С
	{
		largest = left;
	}
	if (right < heap_size && data[right] > data[largest])
		//�жϽ�� k �����Һ��ӽ��Ĵ�С
		largest = right;
	if (largest != k)
	{
		exchange(&data[k], &data[largest]);
		keepHeap(data, heap_size, largest);
		//���ƶ�����λ���ϵĽ�� k �ݹ���б��ֶ����ʲ���
	}
}
/*****************************���Ѻ���****************************/
template <class T> void buildHeap(T data[], int heap_size)
{
	int i = heap_size / 2 - 1;
	while (i >= 0)
	{
		keepHeap(data, heap_size, i); //��ÿ�����ݹ���� keepHeap ����
		i--;
	}
}
/**********************��������******************************/
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
/***************************��������***************************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//����
//�ö������㷨{64,56,34,58,97,76,99,25}���򣬲�������
#include <iostream> 
using namespace std;
template<class T> void keepHeap(T data[], int heap_size, int k)
/*******data ΪҪ��������飬heap_size Ϊ��Ԫ�ظ�����k Ϊ�¼���Ԫ�ص�λ��*******/
{
	int left = 2 * k + 1;
	int right = 2 * k + 2;
	int largest = k;
	if (left < heap_size && data[left] > data[k])
		//�жϽ�� k �������ӽ��Ĵ�С
	{
		largest = left;
	}
	if (right < heap_size && data[right] > data[largest])
		//�жϽ�� k �����Һ��ӽ��Ĵ�С
		largest = right;
	if (largest != k)
	{
		exchange(&data[k], &data[largest]);
		keepHeap(data, heap_size, largest);
		//���ƶ�����λ���ϵĽ�� k �ݹ���б��ֶ����ʲ���
	}
}
/**************************���Ѻ���*******************************/
template <class T> void buildHeap(T data[], int heap_size)
{
	int i = heap_size / 2 - 1;
	while (i >= 0)
	{
		keepHeap(data, heap_size, i); //��ÿ�����ݹ���� keepHeap ����
		i--;
	}
}
/***********************��������*********************************/
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
/************************��������**************************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int data[] = { 64,56,34,58,97,76,99,25 };
	cout << "����ǰ�����ݣ�" << endl;
	for (int i = 0; i < 8; i++)
		cout << data[i] << " ";
	cout << endl;
	heapSort(data, 8);
	cout << "���������ݣ�" << endl;
	for (int i = 0; i < 8; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

//���һ���������ж�һ�������Ƿ���ж�����
#include <iostream> 
using namespace std;
/********************�ж�һ�������ǲ��Ǵ����******************/
template <typename T> bool isHeap(T* data, int n)
{
	int i = 0;
	int parent;
	for (i = 0; i <= n / 2 - 1; i++)
		//���ݶ�����ȫ�������ʣ������ֻ�����������ǰһ����
	{
		parent = i;
		if (data[parent] < data[parent * 2]
			|| data[parent] < data[parent * 2 + 1])
			//�жϸ�����뺢�ӽ��Ĵ�С
		{
			return false;
		}
	}
	return true;
}
/****************���Ѻ���*******************/
template <class T> void buildHeap(T data[], int heap_size)
{
	int i = heap_size / 2 - 1;
	while (i >= 0) //�������м������ʼ��ǰ���ε���ʹÿ��Ԫ�ر��ֶ�����
	{
		keepHeap(data, heap_size, i);
		i--;
	}
}
int main()
{
	int data[] = { 64,56,34,58,97,76,99,25 };
	cout << "�ж������ǲ��Ǵ����:" << endl;
	cout << "����ǰ��" << endl;
	if (isHeap(data, 8))
		cout << "�����Ǵ����" << endl;
	else
		cout << "���鲻�Ǵ����" << endl;
	cout << "���Ѻ�:" << endl;
	buildHeap(data, 8);
	if (isHeap(data, 8))
		cout << "�����Ǵ����" << endl;
	else
		cout << "���鲻�Ǵ����" << endl;
	return 0;
}
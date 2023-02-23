//����������һ�����÷���˼����㷨
/************���������㷨***********************/
template <class T>
void quickSort(T data[], int p, int r)
{
	int position = 0;
	if (p < r)
	{
		position = partition(data, p, r); //���ػ���Ԫ�ص�����λ��
		quickSort(data, p, position - 1); //�Ի��ֵ������н��еݹ����
		quickSort(data, position + 1, r);
	}
}
/*************���л��ֺ���**********************/
template<class T> int partition(T data[], int p, int r)
{
	Int position;
	T temp = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (data[j] <= temp) //����С�ڻ���Ԫ�صļ�ֵʱ
		{ //����Ԫ�� i+1 ��Ԫ�� j ��ֵ
			i += 1;
			exchange(&data[i], &data[j]);
		}

	}
	exchange(&data[i + 1], &data[r]);
	return i + 1;
}
/**************Ԫ��ֵ��������*******************/
template <class T> void exchange(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

//����
//��һ�����飨23,56,44,32,78,2,10�����ÿ��������㷨�������򣬲��������������
/************���������㷨***********************/
template <class T>
void quickSort(T data[], int p, int r)
{
	int position = 0;
	if (p < r)
	{
		position = partition(data, p, r); //���ػ���Ԫ�ص�����λ��
		quickSort(data, p, position - 1); //�Ի��ֵ������н��еݹ����
		quickSort(data, p + 1, r);
	}
}
/*************���л��ֺ���**********************/
template<class T> int partition(T data[], int p, int r)
{
	Int position;
	T temp = data[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (data[j] <= temp) //����С�ڻ���Ԫ�صļ�ֵʱ
		{ //����Ԫ�� i+1 ��Ԫ�� j ��ֵ
			i += 1;
			exchange(&data[i], &data[j]);
		}

	}
	exchange(&data[i + 1], &data[r]);
	return i + 1;
}
/**************Ԫ��ֵ��������*******************/
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

//��дһ�� C++���򣬽�����{2,5,7,8,3,6,11,24,0,1}���Ӵ�С��˳������
#include <iostream> 
#include "quicksort.h"
using namespace std;
/***********����ֻ�г��Ķ��ĺ������֣�δ�Ķ��Ĳ��ֲμ�����***************/
/*************�Ľ������л��ֺ���**********************/
template<class T> int partition(T data[], int p, int r)
{
	int position;
	T temp = data[p];
	int i = r + 1;
	for (int j = r; j > p; j--)
	{
		if (data[j] <= temp) //����С�ڻ���Ԫ�صļ�ֵʱ
		{ //����Ԫ�� i+1 ��Ԫ�� j ��ֵ
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
	quickSort(data, 0, 9); //������βԪ�ص����
	for (int i = 0; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

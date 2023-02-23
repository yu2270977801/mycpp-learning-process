/************************ϣ������***********************/
template <typename T> void shellsort(T data[], int n)
{
	int i, j, flag, counter = 1, gap = n;
	T temp;
	while (gap > 1)
	{
		gap = gap / 2; //���� shell ����ȡ����ÿ����������
		do {
			flag = 0; //�������������ð������
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
/********************��������*************************/
template<typename T> void exchange(T* a, T* b)
{
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//����
//�����ݼ�{32,26,15,89,87,100,654,54,33,26}����ϣ�����򣬲���������
#include <iostream> 
#include "shellsort.h" 
using namespace std;
/************************ϣ������***********************/
template <typename T> void shellsort(T data[], int n)
{
	int i, j, flag, counter = 1, gap = n;
	T temp;
	while (gap > 1)
	{
		gap = gap / 2; //���� shell ����ȡ����ÿ����������
		do {
			flag = 0; //�������������ð������
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
/**************************ֵ��������**************************/
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
	cout << "����ǰ���ݣ�" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	shellsort(data, 10);
	cout << "��������ݣ�" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
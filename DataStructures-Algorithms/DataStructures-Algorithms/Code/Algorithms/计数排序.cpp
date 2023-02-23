/****************************��������***************************/
template <class T> void countingSort(T* ar, int n)
{
	int i, //ѭ������
		k, //���� B �ĳ���
		dx = 0; //�������Ŀ������ʱ��λ�ñ�ʶ
	T max = ar[0], //���������е����ֵ
		mini = ar[0]; //���������е���Сֵ
	for (i = 1; i < n; i++) //�ҳ����������е������Сֵ
	{
		if (ar[i] > max)
			max = ar[i];
		else if (ar[i] < mini)
			mini = ar[i];
	}
	k = max - mini + 1; //���������Сֵ���� k 
	int* b = (int*)malloc(k * sizeof(int)); //�������� B 
	for (i = 0; i < k; i++) //��ʼ������ B 
	{
		b[i] = 0;
	}
	for (i = 0; i < n; i++) //ͳ��ÿ��Ԫ�صĸ���
	{
		b[ar[i] - mini]++;
	}
	for (i = 0; i < k; i++) //�������Ŀ������
	{
		while ((b[i]--) > 0)
		{
			ar[idx++] = i + mini;
		}
	}
	free(b); //�ͷ����� b 
}

//����
//���ü�����������ݼ�{30,54,87,98,86,34,25,55,41,67,45,32,26,22}����
#include <cstdlib> 
#include <iostream> 
using namespace std;
template <class T> void countingSort(T* ar, int n)
{
	int i, //ѭ������
		k, //���� B �ĳ���
		dx = 0; //�������Ŀ������ʱ��λ�ñ�ʶ
	T max = ar[0], //���������е����ֵ
		mini = ar[0]; //���������е���Сֵ
	for (i = 1; i < n; i++) //�ҳ����������е������Сֵ
	{
		if (ar[i] > max)
			max = ar[i];
		else if (ar[i] < mini)
			mini = ar[i];
	}
	k = max - mini + 1; //���������Сֵ���� k 
	int* b = (int*)malloc(k * sizeof(int)); //�������� B 
	for (i = 0; i < k; i++) //��ʼ������ B 
	{
		b[i] = 0;
	}
	for (i = 0; i < n; i++) //ͳ��ÿ��Ԫ�صĸ���
	{
		b[ar[i] - mini]++;
	}
	for (i = 0; i < k; i++) //�������Ŀ������
	{
		while ((b[i]--) > 0)
		{
			ar[idx++] = i + mini;
		}
	}
	free(b); //�ͷ����� b 
}
int main()
{
	int data[] = { 30,54,87,98,86,34,25,55,41,67,45,32,26,22 };
	cout << "����ǰ���ݣ�" << endl;
	for (int i = 0; i < 14; i++)
		cout << data[i] << " ";
	cout << endl;
	countingSort(data, 14);
	cout << "��������ݣ�" << endl;
	for (int i = 0; i < 14; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
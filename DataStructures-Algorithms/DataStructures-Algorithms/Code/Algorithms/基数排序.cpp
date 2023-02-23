//������������ð�������㷨�ķ�ʽ
#include <cmath> 
using namespace std;
/**************************���������㷨******************************/
template <class T> void radixSort(T data[], int n, int d)
/********���� 3 ��������data Ϊ���������飬n Ϊ����Ԫ�ظ�����d Ϊ����Ԫ�ص����λ��
***********/
{
	int weight = 10; //���û���Ȩֵ
	int i = 1;
	int flag = 1; //���ñ�־λ
	while (i <= d)
	{
		int j = 1;
		int currentWeight = static_cast<int>(pow(weight, i));
		int diviceWeight = static_cast<int>(pow(weight, i - 1));
		//��ȡԪ�صĵ� k λֵ����Ҫ data[j]�� weight �� i �η���ģ�ٳ��� weight �� i-1 �η�
		/*********��ÿһλ���������������ǲ���ð�������㷨*********/
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

//Ϊ���Ż�����ʱ�䣬Ҳ���Բ��ÿռ任ʱ��Ĳ��ԣ�����ʹ���ǲ�������ṹʵ�ֵ��㷨
void radixSort(int data[], int n, int d, int w)
/*****data Ϊ���������飬n ΪԪ�ظ�����d ΪԪ�����λ��********/
{
	int* temp = new int[n]; //��ʱ����洢ÿ��������м�����
	int* count = new int[w];
	//�洢ÿһλ��ͬԪ�ظ�������ʱ���飬weight ��ʾ���ݵ�Ȩ������
	int i, j, k;
	int degree = 1;
	//��ʼ���򣬹����� d ��
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < w; j++) //����¼Ԫ��ÿλֵͬ���������ʼ��
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++) //ͳ��ÿһλ����ֵͬ��Ԫ�ظ���
		{
			k = (data[j] / degree) % 10; //���λ�ϵ�ֵ
			count[k]++;
		}
		for (j = 1; j < w; j++)//����ͬλֵ������������ԭ�����и���ֵ�Ľ���λ��
		{
			count[j] = count[j] + count[j - 1];
		}
		for (j = n - 1; j >= 0; j--) //�Ӻ���ǰ���ν������ֵ������ʱ������
		{
			k = data[j] / degree % 10;
			count[k]--;
			temp[count[k]] = data[j];
		}
		for (j = 0; j < n; j++) //�����鸴�Ƶ�ԭ������
			data[j] = temp[j];
		degree = degree * 10; //������ǰ�����Ȩֵ����������λ
	}
	delete[] temp; //�ͷ���ʱ�����ڴ�
	delete[] count;
}

//����
//�û������������{35,64,88,87,896,354,15,64,1}����
#include<iostream> 
#include "radixsort.h" 
using namespace std;
void radixSort(int data[], int n, int d, int w)
{
	int* temp = new int[n];
	int* count = new int[w];
	//�洢ÿһλ��ͬԪ�ظ�������ʱ���飬weight ��ʾ���ݵ�Ȩ������
	int i, j, k;
	int degree = 1;
	//��ʼ���򣬹����� d ��
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < w; j++)
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++)
		{
			k = (data[j] / degree) % 10; //���λ�ϵ�ֵ
			count[k]++;
		}
		for (j = 1; j < w; j++)
			//����ͬλֵ������������ԭ�����и���ֵ�Ľ���λ��
		{
			count[j] = count[j] + count[j - 1];
		}
		for (j = n - 1; j >= 0; j--) //�Ӻ���ǰ���ν������ֵ������ʱ������
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
	cout << "����ǰ�����ݣ�" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	radixSort(data, 9, 3, 10);
	cout << "���������ݣ�" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
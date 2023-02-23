/********�ϲ�����************/
template <class T>
void merge(T A[], T B[], T C[], int lengthA, int lengthB)
//lengthA �� lengthB �ֱ��ʾ A �� B �ĳ���
{
	int i = 0, j = 0, counter = 0; //i��j �� counter �ֱ�Ϊ���� A��B �� C ���α�
	while (counter < lengthA + lengthB)
	{
		if (A[i] < B[j]) //�ж� A �� B ����ӦԪ�صĴ�С
		{
			C[counter] = A[i]; //����С��Ԫ���ȷ��� C ��
			i++;
			counter++;
		}
		else {
			C[counter] = B[j];
			j++;
			counter++;
		}
		if (i == lengthA) //�ж����� A �Ƿ������ɣ��α��Ƿ� A ��ĩβ
		{
			while (j < lengthB) //��� A ��������� B δ���
			{
				C[counter] = B[j]; //�� B ��ʣ���Ԫ�����δ��� C ��ʣ�µ�λ��
				j++;
				counter++;
			}
		}
		else if (j == lengthB)
			//��� B ��ɶ� A δ��ɣ��� A ��ʣ�µ�Ԫ�����δ��� C ��ʣ�µ�λ��
		{
			while (i < lengthA)
			{
				C[counter] = A[i];
				i++;
				counter++;
			}
		}
	}
}
/*****************�鲢�����㷨****************/
template<class T>
void mergeSort(T A[], int n)
{
	if (n > 1)
	{
		int i = n / 2;
		int j = n - n / 2;
		T B[n / 2];
		T C[n - n / 2];
		for (int k = 0; k < i; k++) //�� n>1 ʱ��������ֻ���������
			B[k] = A[k];
		for (int k = 0; k < j; k++)
			C[k] = A[k + i];
		mergeSort(B, i); //��ÿ�������еݹ���й鲢����
		mergeSort(C, j);
		merge(B, C, A, i, j); //�ϲ������������
	}
}

//����
//�� C++���Ա�дһ�����򣬽�����{23,25,48,73,12,82,75,30,16}��С�������򣬲�������
#include <iostream> 
#include "mergesort.h" 
using namespace std;
/********�ϲ�����************/
template <class T>
void merge(T A[], T B[], T C[], int lengthA, int lengthB)
//lengthA �� lengthB �ֱ��ʾ A �� B �ĳ���
{
	int i = 0, j = 0, counter = 0; //i��j �� counter �ֱ�Ϊ���� A��B �� C ���α�
	while (counter < lengthA + lengthB)
	{
		if (A[i] < B[j]) //�ж� A �� B ����ӦԪ�صĴ�С
		{ //����С��Ԫ���ȷ��� C ��
			C[counter] = A[i];
			i++;
			counter++;
		}
		else {
			C[counter] = B[j];
			j++;
			counter++;
		}
		if (i == lengthA) //�ж����� A �Ƿ������ɣ��α��Ƿ� A ��ĩβ
		{
			while (j < lengthB) //��� A ��������� B δ���
			{ //�� B ��ʣ���Ԫ�����δ��� C ��ʣ�µ�λ��
				C[counter] = B[j];
				j++;
				counter++;
			}
		}
		else if (j == lengthB)
		{
			while (i < lengthA)
				//��� B ��ɶ� A δ��ɣ��� A ��ʣ�µ�Ԫ�����δ��� C ��ʣ�µ�λ��
			{
				C[counter] = A[i];
				i++;
				counter++;
			}
		}
	}
}
/*****************�鲢�����㷨****************/
template<class T>
void mergeSort(T A[], int n)
{
	if (n > 1)
	{
		int i = n / 2;
		int j = n - n / 2;
		T B[n / 2];
		T C[n - n / 2];
		for (int k = 0; k < i; k++) //�� n>1 ʱ��������ֻ���������
			B[k] = A[k];
		for (int k = 0; k < j; k++)
			C[k] = A[k + i];
		mergeSort(B, i); //��ÿ�������еݹ���й鲢����
		mergeSort(C, j);
		merge(B, C, A, i, j); //�ϲ������������
	}
}
int main()
{
	int data[9] = { 23,25,48,73,12,82,75,30,16 };
	cout << "����ǰ�������У�" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	mergeSort(data, 9);
	cout << "���������" << endl;
	for (int i = 0; i < 9; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
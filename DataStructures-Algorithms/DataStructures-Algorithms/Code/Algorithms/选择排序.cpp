/**********************ѡ������*****************************/
template <class T> void selectionsort(T data[], int n)
{
	int i = 1, j; //i ��ʾ���������
	int max; //��¼ÿ�����������Ԫ�ص�λ��
	T temp;
	while (i <= n - 1)
	{
		max = n - i; //�� max ��ʼ��Ϊ����Ԫ�ص���ĩλ��
		for (j = 0; j < n - i + 1; j++)
		{
			if (data[j] > data[max]) //Ѱ�Ҵ���Ԫ�������Ԫ�ص�λ��
				max = j;
		}
		if (max != n - i) //�����Ԫ�ؽ���������Ԫ�ص�ĩβ 
		{
			temp = data[max];
			data[max] = data[n - i];
			data[n - i] = temp;
		}
		i++;
	}
}

//����
//����ѡ�������㷨����ĸ E��X��A��M��P��L��E ����ĸ������
#include <iostream> 
using namespace std;
template <class T> void selectionsort(T data[], int n)
{
	int i = 1, j;
	int max; //��¼ÿ�����������Ԫ�ص�λ��
	T temp;
	while (i <= n - 1)
	{
		max = n - i; //�� max ��ʼ��Ϊ����Ԫ�ص���ĩλ��
		for (j = 0; j < n - i + 1; j++)
		{
			if (data[j] > data[max]) //Ѱ�Ҵ���Ԫ�������Ԫ�ص�λ��
				max = j;
		}
		if (max != n - i) //�����Ԫ�ؽ���������Ԫ�ص�ĩβ 
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
	cout << "����ǰ���ݣ�" << endl;
	for (int i = 0; i < 7; i++)
		cout << data[i] << " ";
	cout << endl;
	selectionsort(data, 7);
	cout << "��������ݣ�" << endl;
	for (int i = 0; i < 7; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}

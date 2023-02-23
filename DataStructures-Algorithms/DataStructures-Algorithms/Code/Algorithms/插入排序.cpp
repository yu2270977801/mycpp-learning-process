//����������һ���ȶ������㷨�������ݼ���ģ���������£����������㷨���нϺõ�Ч�ʡ�
//���������ʱ�临�Ӷ��� O(n2)
template<typename DataType>
void insertSort(DataType D[], int length)
{
	DataType key;
	for (int j = 2; j < length; i++)
	{
		key = D[j]; //��������Ԫ�� D[j]������ʱ���� key ��
		int i = j - 1;
		while (i > 0 && key < D[i]) //ѭ��Ѱ�Ҵ�����Ԫ�ص���ȷλ��
		{
			D[i + 1] = D[i]; //�����ڴ�����Ԫ�ص�ֵ�����λ
			i = i - 1; //���α������ 1 
		}
		D[i + 1] = key; //��������Ԫ�ز��� i+1 ��λ��
	}
}

//����
//��һ������{43,35,1,87,99,67,78,100}����дһ�� C++����ʵ�ֶԸ�����Ĳ������򣬲��������������Ԫ�ء�
#include <iostream> 
using namespace std;
void insertSort(int[], int);
int main()
{
	int data[9] = { 0,43,35,1,87,99,67,78,100 };
	//���������������飬�����С��ʵ�����ݸ����� 1��data[0]Ϊ�ڱ�Ԫ�أ��� 0 ��� 9 
	int length = 9; //�洢�������ݵ����鳤��
	cout << "The oraginal array is:" << endl;
	for (int i = 1; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	insertSort(data, length); //���ò��������㷨
	cout << "The result of insertion sorting is:" << endl;
	for (int i = 1; i < length; i++) //��ӡ������������飬������ڱ�Ԫ�ص�ֵ
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
void insertSort(int d[], int n) //���������㷨
{
	int i, j;
	for (int j = 2; j < n; j++)
	{
		d[0] = d[j];
		i = j - 1;
		while (i > 0 && d[i] > d[0])
		{
			d[i + 1] = d[i];
			i--;
		}
		d[i + 1] = d[0];
	}
}

//��дһ�������û���������� 10 ���������ò������򷨶��� 10 �������򣬲���������Ľ��
#include <iostream> 
using namespace std;
void insertSort(int a[], int n)
{
	int key = 0, i = 1, j = 0;
	while (i < n)
	{
		key = a[i]; //ѡȡ�������Ԫ��
		j = i - 1;
		while (j >= 0 && key < a[j]) //�ж�����Ԫ������ǰ��λ�õ�Ԫ�ش�С
		{
			a[j + 1] = a[j]; //�����ڴ�����Ԫ�ص�Ԫ��������λ
			j = j - 1;
		}
		a[j + 1] = key; //��������Ԫ�ط��õ���һ��С������Ԫ�غ���
		i++;
	}
}
int main()
{
	int data[10];
	int i;
	cout << "������ 10 ��������" << endl;
	for (i = 0; i < 10; i++)
		cin >> data[i];
	cout << "�������ֵΪ��" << endl;
	for (i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	insertSort(data, 10);
	cout << "������Ԫ��˳��Ϊ��" << endl;
	for (i = 0; i < 10; i++)
		cout << data[i] << " ";
	return 0;
}
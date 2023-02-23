//ð��������Ҫ˼���ǣ�ɨ���������ݣ������Ƚϣ�����Υ����������������֮��ԭ�������������λ�ã����������³����������ϸ���
/******����Ԫ�ؽ�������********/
template<typename keytype>
void swap(keytype* a, keytype* b)
{
	keytype temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/******ð�������㷨************/
template <typename keytype>
void bubbleSort(keytype data[], int n)
{
	int flag; //���ý�����־
	int i = 1, j;
	do { //��ʼ����־ֵΪ 0 
		for (j = 0; j + 1 < n; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]); //��������Ԫ�ص�ֵ
				flag = 1; //����־ֵ��Ϊ 1���������������з�����Ԫ�ؽ�������
			}
		}
		i++;
	} while (i < n && flag == 1); //�� i<n �ұ���������������ݽ�����ʱ��ż���ѭ��
}

//����
//��һ������������{23,43,23,19,87,65,78,90,7,10}��ʵ��һ�� C++������ð�������㷨�Ը��������򣬲���������
#include <iostream> 
using namespace std;
void bubbleSort(int[], int);
void swap(int*, int*);
int main()
{
	int data[10] = { 23,43,23,19,87,65,78,90,7,10 };
	cout << "����ǰ������Ϊ��" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	bubbleSort(data, 10);
	cout << "����������Ϊ��" << endl;
	for (int i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
/*****************��������********************/
/*************����������ֵ****************/
void swap(int* a, int* b)
{
	/*********************���ݶ��� a = a^b^b*****************************/
	/*****************���ð�λ�����㽻��������ֵ��ʡȥ�м����***************/
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
/**************************ð�������㷨����*************************/
void bubbleSort(int data[], int n)
{
	int flag;
	int i = 1, j;
	do
	{
		flag = 0;
		for (j = 0; j + 1 < n; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(data[j], data[j + 1]);
				flag = 1;
			}
		}
		i++;
	} while (i < n && flag == 1);
}


//���Ӵ�С��˳������{25,30,16,87,89,102,1,23}����������
#include <iostream> 
using namespace std;
template<typename T> void bubbleSort(T[], int n); //����ð�������㷨����
int main()
{
	int d[8] = { 25,30,16,87,89,102,1,23 };
	cout << "ԭ�����Ԫ��ֵΪ��" << endl;
	for (int i = 0; i < 8; i++)
		cout << d[i] << " ";
	cout << endl;
	bubbleSort2(d, 8);
	cout << "����������Ԫ��ֵΪ��" << endl;
	for (int i = 0; i < 8; i++)
		cout << d[i] << " ";
	cout << endl;
	return 0;
}
/*************************ð�������㷨***********************/
template <typename T> void bubbleSort(T data[], int n)
{
	int flag = 1;
	int i = n - 1, j = 0;
	T temp;
	while (i > 0 && flag == 1)
	{
		flag = 0;
		for (j = 0; j + 1 <= i; j++)
		{
			if (data[j] < data[j + 1]) //��ֵ�ϴ��Ԫ����ǰ�ƣ�ʵ�ִӴ�С������
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				flag = 1;
			}
		}
		i--;
	}
}









/******************���ֲ���****************************/
template<class DataType> binSearch(DataType[] key, int n, DataType k)
{
	int low = 0, high = n - 1; //���������α�������α�
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2; //�����м�λ��
		if (k == key[mid]) //���м�λ��Ԫ�رȽϣ�����������ҳɹ�
		{
			return mid; //����λ��
		}
		else if (k > key[mid]) //��С���ҷ�Χ����벿��
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1; //��С��Χ��ǰ�벿��
		}
	}
	return NULL; //����ʧ��
}

//����
//��һ���������水����˳��洢�� 10 ������{12,23,24,34,45,56,67,78,89,99}�����ҳ�����������ֵ�λ��
#include <iostream> 
using namespace std;
template<class DataType> int binSearch(DataType key[], int n, DataType k)
{
	int low = 0, high = n - 1; //���������α�������α�
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2; //�����м�λ��
		if (k == key[mid]) //���м�λ��Ԫ�رȽϣ�����������ҳɹ�
		{
			return mid; //����λ��
		}
		else if (k > key[mid]) //��С���ҷ�Χ����벿��
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1; //��С��Χ��ǰ�벿��
		}
	}
	return NULL; //����ʧ��
}
int main()
{
	int data[] = { 12,23,24,34,45,56,67,78,89,99 };
	int key;
	cout << "������Ҫ���ҵ����֣�";
	cin >> key;
	cout << endl;
	int result = binSearch(data, 10, key);
	cout << "���������������" << key << ",����λ���ǣ�" << result << endl;
	return 0;
}
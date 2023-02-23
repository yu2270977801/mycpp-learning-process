/********************˳�����****************************/
template<class DataType> seqSearch(DataType[] key, int n, DataType k)
{
	for (int i = 1; i <= n; i++)
	{
		if (key[i] == k) //�ӵ�һ����¼��ʼ�Ƚ�
		{
			return i; //����ҵ��� k ��ȵļ�¼������λ��
		}
	}
	return 0; //δ�ҵ���Ӧ��¼������ 0 
}

//����
//��һ���� 23,65,98,45,64,25,11�����һ����������˳����ҷ��ҳ��ؼ��� 98���������λ�á�
#include <iostream> 
#include "search.h" 
using namespace std;
int main()
{
	int data[] = { 23,65,98,45,64,25,11 };
	for (int i = 1; i <= 7; i++)
	{
		if (data[i] == 98) //�ӵ�һ����¼��ʼ�Ƚ�
		{
			return i; //����ҵ��� k ��ȵļ�¼������λ��
		}
	}
	return 0; //δ�ҵ���Ӧ��¼������ 0 
}
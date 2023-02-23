/*Ͱ�е�Ԫ������*/
typedef template<class T> struct entry {
	T element;
	struct entry* next;
}ENTRY;
/*ά��ÿ��Ͱ��Ԫ�ص���Ŀ������ָ���һ��Ԫ��*/
typedef struct buc {
	int size;
	ENTRY* head;
}BUCKET;
void template<class T> bucketSort(T* data, int n)
{
	//��������ʼ��Ͱ��ͷ���
	BUCKET* buckets = (BUCKET*)malloc(sizeof(BUCKET) * n);
	for (int i = 0; i < n; i++)
	{
		buckets[i].size = 0;
		buckets[i].head = NULL;
	}
	//��Ͱ�з�����
	createBucket(buckets, n, data);
	//��Ͱ���ź�������ݷ������뵽������
	reverseEvaluation(buckets, data, n);
}
//Ͱ������ʹ�ò�������
void template<class T> insertSort(BUCKET& bucket, const T& element)
{
	ENTRY* tmp = bucket.head;
	ENTRY* en = (ENTRY*)malloc(sizeof(ENTRY));
	en->element = element;
	en->next = NULL;
	if ((tmp == NULL) || (tmp->element > en->element))
	{
		en->next = tmp;
		bucket.head = en;
		bucket.size++;
	}
	else
	{
		while (tmp != NULL)
		{
			if ((tmp->next == NULL && tmp->element <= en->element) ||
				(tmp->element <= en->element && tmp->next->element > en->element))
			{
				en->next = tmp->next;
				tmp->next = en;
				bucket.size++;
				break;
			}
			tmp = tmp->next;
		}
	}
}
//ʹ�ò����������ݷֱ�����Ӧ��Ͱ��
void template<class T> createBucket(BUCKET* buckets, T* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		int num = hash(data[i]);
		insertSort(buckets[num], data[i]);
	}
}
//�����������ݷ������뵽������
void template<class T> reverseEvaluation(BUCKET* buckets, T* data, int n)
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (buckets[i].size != 0)
		{
			ENTRY* en = buckets[i].head;
			while (en != NULL)
			{
				data[idx++] = en->element;
				en = en->next;
			}
		}
	}
}

//����
//ĳ�๲ 72 ��ѧ������������ĩ��ѧ�ɼ�������������� 100 �֣���� 0�֣�û��С�������ó���ʵ�ֳɼ�������
#include<stdio.h> 
#include <iostream> 
#include <fstream> 
using namespace std;
/*Ͱ�е�Ԫ������*/
typedef struct entry {
	int element;
	struct entry* next;
}ENTRY;
/*ά��ÿ��Ͱ��Ԫ�ص���Ŀ������ָ���һ��Ԫ��*/
typedef struct buc {
	int size;
	ENTRY* head;
}BUCKET;
int hash(int data); //��ϣ�������������ݷ�Ͱ
void insertSort(BUCKET& bucket, const int& element);//������������Ͱ������
void createBucket(BUCKET* buckets, int n, int* data); //����Ͱ
void reverseEvaluation(BUCKET* buckets, int* data, int n);
//���ź���������������
int readScore(int* score); //���ļ��н����ݶ�������
void bucketSort(int* score, int n); //Ͱ����
void main()
{
	int score[100];
	int num;
	num = readScore(score); //���ļ��е����ݶ������� score ��
	bucketSort(score, num); //�� score �е����ݽ���Ͱ����
}
void bucketSort(int* score, int num)
{
	//��������ʼ��Ͱ
	BUCKET* buckets = (BUCKET*)malloc(sizeof(BUCKET) * 11);
	for (int i = 0; i < 11; i++)
	{
		buckets[i].size = 0;
		buckets[i].head = NULL;
	}
	//��Ͱ���������ݲ�����Ͱ������
	createBucket(buckets, num, score);
	//������õ�������� score ����
	reverseEvaluation(buckets, score, 11);
	//��ӡ��������
	for (int j = 1; j <= num; j++)
	{
		cout << score[j - 1] << " ";
		if (j % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	//�ͷſռ�
	free(buckets);
}
int hash(int data)
{
	return data / 10;
}
void insertSort(BUCKET& bucket, const int& element)
{
	ENTRY* tmp = bucket.head;
	ENTRY* en = (ENTRY*)malloc(sizeof(ENTRY));
	en->element = element;
	en->next = NULL;
	if ((tmp == NULL) || (tmp->element > en->element))
	{
		en->next = tmp;
		bucket.head = en;
		bucket.size++;
	}
	else
	{
		while (tmp != NULL)
		{
			if ((tmp->next == NULL && tmp->element <= en->element) || (tmp
				->element <= en->element && tmp->next->element > en->element))
			{
				en->next = tmp->next;
				tmp->next = en;
				bucket.size++;
				break;
			}
			tmp = tmp->next;
		}
	}
}
void createBucket(BUCKET* buckets, int n, int* data)
{
	for (int i = 0; i < n; i++)
	{
		int num = hash(data[i]);
		insertSort(buckets[num], data[i]);
	}
}
void reverseEvaluation(BUCKET* buckets, int* data, int n)
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (buckets[i].size != 0)
		{
			ENTRY* en = buckets[i].head;
			while (en != NULL)
			{
				data[idx++] = en->element;
				en = en->next;
			}
		}
	}
}
int readScore(int* score)
{
	int idx = 0;
	ifstream fin("F: \\score.txt"); //�����ݼ��ļ�
	if (!fin)
	{
		return 0;
	}
	int num;
	while (!fin.eof())
	{
		fin >> num;
		score[idx++] = num;
	}
	--idx;
	return idx;
}

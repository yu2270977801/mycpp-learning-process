/*桶中的元素链表*/
typedef template<class T> struct entry {
	T element;
	struct entry* next;
}ENTRY;
/*维护每个桶中元素的数目，并且指向第一个元素*/
typedef struct buc {
	int size;
	ENTRY* head;
}BUCKET;
void template<class T> bucketSort(T* data, int n)
{
	//创建并初始化桶的头结点
	BUCKET* buckets = (BUCKET*)malloc(sizeof(BUCKET) * n);
	for (int i = 0; i < n; i++)
	{
		buckets[i].size = 0;
		buckets[i].head = NULL;
	}
	//向桶中放数据
	createBucket(buckets, n, data);
	//将桶中排好序的数据反向输入到数组中
	reverseEvaluation(buckets, data, n);
}
//桶内数据使用插入排序
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
//使用插入排序将数据分别插入对应的桶中
void template<class T> createBucket(BUCKET* buckets, T* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		int num = hash(data[i]);
		insertSort(buckets[num], data[i]);
	}
}
//将已排序数据反向输入到数组中
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

//案例
//某班共 72 名学生，将班里期末数学成绩排名，分数最高 100 分，最低 0分，没有小数，请用程序实现成绩的排序
#include<stdio.h> 
#include <iostream> 
#include <fstream> 
using namespace std;
/*桶中的元素链表*/
typedef struct entry {
	int element;
	struct entry* next;
}ENTRY;
/*维护每个桶中元素的数目，并且指向第一个元素*/
typedef struct buc {
	int size;
	ENTRY* head;
}BUCKET;
int hash(int data); //哈希函数用来将数据分桶
void insertSort(BUCKET& bucket, const int& element);//插入排序，用于桶内排序
void createBucket(BUCKET* buckets, int n, int* data); //创建桶
void reverseEvaluation(BUCKET* buckets, int* data, int n);
//将排好序的数据输回数组
int readScore(int* score); //从文件中将数据读入数组
void bucketSort(int* score, int n); //桶排序
void main()
{
	int score[100];
	int num;
	num = readScore(score); //将文件中的数据读入数组 score 中
	bucketSort(score, num); //对 score 中的数据进行桶排序
}
void bucketSort(int* score, int num)
{
	//创建并初始化桶
	BUCKET* buckets = (BUCKET*)malloc(sizeof(BUCKET) * 11);
	for (int i = 0; i < 11; i++)
	{
		buckets[i].size = 0;
		buckets[i].head = NULL;
	}
	//向桶内输入数据并进行桶内排序
	createBucket(buckets, num, score);
	//将排序好的数据输回 score 数组
	reverseEvaluation(buckets, score, 11);
	//打印已排数组
	for (int j = 1; j <= num; j++)
	{
		cout << score[j - 1] << " ";
		if (j % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
	//释放空间
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
	ifstream fin("F: \\score.txt"); //打开数据集文件
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

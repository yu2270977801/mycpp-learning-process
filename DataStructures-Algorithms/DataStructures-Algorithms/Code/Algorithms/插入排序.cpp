//插入排序是一种稳定排序算法。在数据及规模不大的情况下，插入排序算法具有较好的效率。
//插入排序的时间复杂度是 O(n2)
template<typename DataType>
void insertSort(DataType D[], int length)
{
	DataType key;
	for (int j = 2; j < length; i++)
	{
		key = D[j]; //将待排序元素 D[j]存入临时变量 key 中
		int i = j - 1;
		while (i > 0 && key < D[i]) //循环寻找待排序元素的正确位置
		{
			D[i + 1] = D[i]; //将大于待排序元素的值向后移位
			i = i - 1; //将游标变量减 1 
		}
		D[i + 1] = key; //将待排序元素插入 i+1 的位置
	}
}

//案例
//有一个数组{43,35,1,87,99,67,78,100}，编写一个 C++程序实现对该数组的插入排序，并输出排序后的数组元素。
#include <iostream> 
using namespace std;
void insertSort(int[], int);
int main()
{
	int data[9] = { 0,43,35,1,87,99,67,78,100 };
	//遍历输入数据数组，数组大小比实际数据个数大 1，data[0]为哨兵元素，用 0 填充 9 
	int length = 9; //存储输入数据的数组长度
	cout << "The oraginal array is:" << endl;
	for (int i = 1; i < length; i++)
		cout << data[i] << " ";
	cout << endl;
	insertSort(data, length); //调用插入排序算法
	cout << "The result of insertion sorting is:" << endl;
	for (int i = 1; i < length; i++) //打印输出排序后的数组，不输出哨兵元素的值
		cout << data[i] << " ";
	cout << endl;
	return 0;
}
void insertSort(int d[], int n) //插入排序算法
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

//编写一个程序，用户输入任意的 10 个整数，用插入排序法对这 10 个数排序，并输出排序后的结果
#include <iostream> 
using namespace std;
void insertSort(int a[], int n)
{
	int key = 0, i = 1, j = 0;
	while (i < n)
	{
		key = a[i]; //选取待排序的元素
		j = i - 1;
		while (j >= 0 && key < a[j]) //判断排序元素与其前面位置的元素大小
		{
			a[j + 1] = a[j]; //将大于待排序元素的元素往后移位
			j = j - 1;
		}
		a[j + 1] = key; //将待排序元素放置到第一个小于它的元素后面
		i++;
	}
}
int main()
{
	int data[10];
	int i;
	cout << "请输入 10 个整数：" << endl;
	for (i = 0; i < 10; i++)
		cin >> data[i];
	cout << "您输入的值为：" << endl;
	for (i = 0; i < 10; i++)
		cout << data[i] << " ";
	cout << endl;
	insertSort(data, 10);
	cout << "排序后的元素顺序为：" << endl;
	for (i = 0; i < 10; i++)
		cout << data[i] << " ";
	return 0;
}
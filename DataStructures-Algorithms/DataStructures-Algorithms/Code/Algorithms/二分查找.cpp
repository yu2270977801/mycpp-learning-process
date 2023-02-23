/******************二分查找****************************/
template<class DataType> binSearch(DataType[] key, int n, DataType k)
{
	int low = 0, high = n - 1; //设置下限游标和上线游标
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2; //计算中间位置
		if (k == key[mid]) //与中间位置元素比较，如果相等则查找成功
		{
			return mid; //返回位置
		}
		else if (k > key[mid]) //缩小查找范围到后半部分
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1; //缩小范围到前半部分
		}
	}
	return NULL; //查找失败
}

//案例
//有一个数组里面按递增顺序存储了 10 个数，{12,23,24,34,45,56,67,78,89,99}，请找出所输入的数字的位置
#include <iostream> 
using namespace std;
template<class DataType> int binSearch(DataType key[], int n, DataType k)
{
	int low = 0, high = n - 1; //设置下限游标和上线游标
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2; //计算中间位置
		if (k == key[mid]) //与中间位置元素比较，如果相等则查找成功
		{
			return mid; //返回位置
		}
		else if (k > key[mid]) //缩小查找范围到后半部分
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1; //缩小范围到前半部分
		}
	}
	return NULL; //查找失败
}
int main()
{
	int data[] = { 12,23,24,34,45,56,67,78,89,99 };
	int key;
	cout << "请输入要查找的数字：";
	cin >> key;
	cout << endl;
	int result = binSearch(data, 10, key);
	cout << "您所输入的数字是" << key << ",它的位置是：" << result << endl;
	return 0;
}
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
/*****************************二叉查找树定义******************/
template<typename DataType> class SBT
{
public:
	/******************构造函数********************/
	SBT()
	{
		root = new SBT<DataType>();
	}
	SBT(DataType data)
	{
		root = new SBT<DataType>(data);
	}

private:
	SBTNode<DataType>* root; //根结点指针
};

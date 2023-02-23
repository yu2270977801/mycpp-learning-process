////散列表
//定义
/********************散列表定义，利用开放定址法处理冲突****************/
template<typename DataType> class HashTable
{
public:
	HashTable(int size)
	{
		maxSize = size; //初始化最大存储空间
		count = 0;
		elements = new DataType[size]; //分配数据空间
		if (elements == NULL) //判断存储空间是否分配成功
			exit(1);
		for (int i = 0; i < size; i++) //初始化每个存储空间的值
			elements[i] = NULL;
	}
	~HashTable()
	{
		delete[] elements;
	}
	//散列函数——除留取余，p 为根据关键字集合设定的值
	int hash(DataType value, int p);
	//查找函数，返回所查找元素的地址
	int searchHash(DataType value);
private:
	int maxSize; //最大容量
	int count; //当前元素数
	DataType* elements; //数据域
};
/***********************hash 函数***********************/
template<typename DataType> int HashTable<DataType>::hash(DataType
	value, int p)
{
	return value % p; //采用除留余法计算散列地址
}
/**********************查找算法***********************/
template<typename DataType> int HashTable<DataType>::searchHash(DataType
	value)
{
	int p = hash(value); //计算地址
	if (elements[p] == value) //如果相等，没有发生冲突，返回 p 
	{
		return p;
	}
	int rp = (p + 1) % maxSize; //线性探测法处理冲突，选取 d=1 
	while (rp != p) //rp==p 时说明没有找到所需元素
	{
		if (elements[rp] == value) //如果新地址的值与 value 相等，返回新地址
			return rp;
		if (elements[rp] == NULL) //找到空白地址
			break;
		rp = (rp + 1) % maxSize; //循环使用线性探测法找空白地址
	}
	if (rp == p) //查找失败
		return -1;
	else
	{
		elements[rp] = value; //在空白地址上插入此元素并返回地址
		return rp;
	}

}

//实例
//用 C++语言实现散列表的插入和查找操作，并将数据{66,32,98,478,11,23}插入到表中
#include<iostream> 
Using namespace std;
/********************散列表定义，利用开放定址法处理冲突****************/
template<typename DataType> class HashTable
{
public:
	HashTable(int size)
	{
		maxSize = size; //初始化最大存储空间
		count = 0;
		elements = new DataType[size]; //分配数据空间
		if (elements == NULL) //判断存储空间是否分配成功
			exit(1);
		for (int i = 0; i < size; i++) //初始化每个存储空间的值
			elements[i] = NULL;
	}
	~HashTable()
	{
		delete[] elements;
	}
	//散列函数
	int hash(DataType value);
	//查找函数，返回所查找元素的地址
	int searchHash(DataType value);
	//获取散列表的第 i 个元素的值
	DataType getData(int i)
	{
		if (i <= 0)
		{
			std::cout << "索引值错误！必须为正整数" << endl;
		}
		return elements[i - 1];
	}
	//插入操作
	bool insertHash(DataType value);
private:
	int maxSize; //最大容量
	int count; //当前元素数
	DataType* elements; //数据域
};
/***********************hash 函数***********************/
template<typename DataType> int HashTable<DataType>::hash(DataType value)
{
	return value % 13; //采用除留余法计算散列地址
}
/**********************查找算法***********************/
template<typename DataType> int HashTable<DataType>::searchHash(DataType
	value)
{
	int p = hash(value); //计算地址
	if (elements[p] == value) //如果相等，没有发生冲突，返回 p 
	{
		return p;
	}
	int rp = (p + 1) % maxSize; //线性探测法处理冲突，选取 d=1 
	while (rp != p) //rp==p 时说明没有找到所需元素
	{
		if (elements[rp] == value) //如果新地址的值与 value 相等，返回新地址
			return rp;
		if (elements[rp] == NULL) //找到空白地址
			break;
		rp = (rp + 1) % maxSize; //循环使用线性探测法找空白地址
	}
	if (rp == p) //查找失败
		return -2;
	else
	{
		//elements[rp] = value; //在空白地址上插入此元素并返回地址
		return rp;
	}

}
/************************插入操作**************************/
template<typename DataType> bool HashTable<DataType>::insertHash(DataType
	value)
{
	int pos = searchHash(value); //查找指定元素，看看散列表中是否已经存在
	if (pos < 0) //查找失败且表满
	{
		return false;
	}
	else if (elements[pos] == value)//有重复元素
	{
		cout << "重复的元素！" << endl;
		return false;
	}
	else
	{
		elements[pos] = value; //在空白地址插入元素
		return true;
	}
}
int main()
{
	HashTable<int> hashtable = HashTable<int>(13); //构建散列表
	//依次插入元素
	hashtable.insertHash(66);
	hashtable.insertHash(32);
	hashtable.insertHash(98);
	hashtable.insertHash(478);
	hashtable.insertHash(11);
	hashtable.insertHash(23);
	hashtable.insertHash(43);
	hashtable.insertHash(55);
	hashtable.insertHash(67);
	hashtable.insertHash(108);
	hashtable.insertHash(230);
	hashtable.insertHash(223);
	hashtable.insertHash(10);
	//输出元素
	cout << "表中的元素为：";
	for (int i = 1; i <= 13; i++)
		cout << hashtable.getData(i) << " ";
	cout << endl;
	//查找元素 55 
	cout << "元素 55 的位置：" << hashtable.searchHash(55) << endl;
	return 0;
}
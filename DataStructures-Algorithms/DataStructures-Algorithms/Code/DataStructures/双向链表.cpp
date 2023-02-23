#include <iostream> 
template <typename DataType> class DoubleList;
/***************双向链表结点定义****************/
template <typename DataType> class DoubleListNode
{
private:
	friend class DoubleList<DataType>; //声明链表类为友元类
	DoubleListNode() :m_pprior(NULL), m_pnext(NULL) {}
	//无参数构造函数，将指针初始化为 NULL 
	//带参数构造函数初始化数据域和指针域
	DoubleListNode(const DataType item, DoubleListNode<DataType>* prior = NULL, DoubleListNode<DataType>* next = NULL):m_data(item), m_pprior(prior), m_pnext(next) {}
	//析构函数
	~DoubleListNode() {
		m_pprior = NULL;
		m_pnext = NULL;
	}
	DataType m_data; //数据域
	DoubleListNode* m_pprior; //指向前驱结点的指针域
	DoubleListNode* m_pnext; //指向后继结点的指针域
public:
	DataType getData(); //获取结点内的数据值
};
//获取结点中的数据
template<typename DataType> DataType DoubleListNode<DataType>::getData() {
	return this->m_data;
}
/***********************双向链表定义**********************/
template<typename DataType> class DoubleList {
public:
	DoubleList()
	{
		head = new DoubleListNode<DataType>();
	}
	~DoubleList()
	{
		cleanDoubleLink();
		delete head;
	}
public:
	void cleanDoubleLink(); //清空双向链表
	int getLength(); //获取链表长度
	DoubleListNode<DataType> *findNode(int i = 0); //寻找第 i 个结点
	DoubleListNode<DataType> *findData(DataType item);
	//寻找具有给定值数据的结点
	bool insertNode(DataType item, int i = 0); //在第 i 个结点后插入新结点
	bool removeNode(int i = 0); //删除第 i 个结点
	DataType getData(int i = 0); //获取第 i 个结点的数据

private:
	DoubleListNode<DataType> *head; //头指针
};
/*********************清空链表*****************/
template<typename DataType> void DoubleList<DataType>::cleanDoubleLink() {
	DoubleListNode<DataType>* pmove = head->m_pnext, * pdel;
	while (pmove != NULL) { //一次删除头指针后面的结点
		pdel = pmove;
		pmove = pdel->m_pnext;
		delete pdel;
	}
	head->m_pnext = NULL;

}
/*******************获取链表长度********************/
template<typename DataType> int DoubleList<DataType>::getLength() {
	int count = 0;
	DoubleListNode<DataType>* pmove = head->m_pnext;
	//遍历链表，计算结点数
	while (pmove != NULL)
	{
		pmove = pmove->m_pnext;
		count++;
	}
	return count;
}
/***************************获取第 i 个结点***********************/
template<typename DataType> DoubleListNode<DataType>* DoubleList<DataType>::findNode(int n = 1) {
	if (n < 1) { //判断位置是否有效
		cout << "非有效位置" << endl;
		return NULL;
	}
	DoubleListNode<DataType>* pmove = head->m_pnext;
	for (int i = 1; i < n; i++) { //查找指定位置的结点
		pmove = pmove->m_pnext;
		if (pmove == NULL) { //判断结点是否存在
			cout << "不存在指定结点" << endl;
			return NULL;
		}
	}
	return pmove;
}
/**********************在第 i 个结点之后插入新结点****************/
template<typename DataType> bool DoubleList<DataType>::insertNode(DataType item, int n) {
	int i;
	if (n < 1) { //判断所插入的位置是否有效
		cout << "插入位置无效" << endl;
		return 0;
	}
	//创建新结点，设置游标指针
	DoubleListNode<DataType>* newnode = new DoubleListNode<DataType>(item),
	*pmove = head;

	if (newnode == NULL) {
		cout << "内存分配失败，新结点无法创建！" << endl;
		exit(1);
	}
	for (i = 1; i < n; i++) { //找到插入的位置
		pmove = pmove->m_pnext;
		if (pmove == NULL && i < n - 1) {
			cout << "超出链表长度，插入位置无效！" << endl;
			return 0;
		}
	}
	//插入新结点
	newnode->m_pnext = pmove->m_pnext;
	if (pmove->m_pnext != NULL) //判断是否在链表尾部添加结点
	{
		pmove->m_pnext->m_pprior = newnode;
	}
	newnode->m_pprior = pmove;
	pmove->m_pnext = newnode;

	return 1;
}
/*********************删除第 i 个结点**********************/
template<typename DataType> bool DoubleList<DataType>::removeNode(int n = 1) {
	if(n<1 || n>getLength()) { //判断位置是否有效
		cout << "位置不合法" << endl;
		return false;
	}
	DoubleListNode<DataType>* pmove = head->m_pnext, *pdel;
	for (int i = 1; i < n; i++) { //查找删除结点的位置
		pmove = pmove->m_pnext;
		if (pmove == NULL) {
			cout << "超出了链表范围" << endl;
			return false;
		}
	}
	//删除结点
	pdel = pmove;
	pmove->m_pprior->m_pnext = pdel->m_pnext;
	pmove->m_pnext->m_pprior = pdel->m_pprior;
	delete pdel;
	return true;
}
/************************获取第 n 个元素的数据*******************/
template<typename DataType> DataType DoubleList<DataType>::getData(int n = 1) {
	if (n<1 || n>getLength()) { //验证所选的位置是否合法
		cout << "指定位置无效" << endl;
		exit(1);
	}
	DoubleListNode<DataType> *pmove = head->m_pnext; //设置游标指针
	for (int i = 1; i < n; i++) {
		pmove = pmove->m_pnext;
		if (pmove == NULL) {
			cout << "指定结点不存在！" << endl;
			exit(1);
		}
	}
	if (pmove == NULL)
	{
		cout << "结点不存在！" << endl;
		return NULL;
	}
	return pmove->m_data; //返回所找到的元素的数据
}
/******************************获取具有指定值数据的结点************************/
template<typename DataType> DoubleListNode<DataType>* DoubleList<DataType>::findData(DataType item) {
	DoubleListNode<DataType> *pmove = head->m_pnext; //设置游标指针
	if (pmove == NULL) //判断空表
	{
		cout << "链表是空表！" << endl;
		exit(1);
	}
	while (pmove->getData() != item) //循环查找符合条件的结点
	{
		pmove = pmove->m_pnext;
		if (pmove == NULL)
		{
			cout << "没有所查找的结点" << endl;
			exit(1);
		}
	}
	return pmove;
}

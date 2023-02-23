//////////////链表
//定义
template <typename DataType> class LinkList
{
public:
	//无参数构造函数
	LinkList()
	{
		head = new ListNode();
	}
	//有参数构造函数
	LinkList(ListNode* node)
	{
		head = node;
	}
	//析构函数
	~LinkList()
	{
		delete head;
	}
	bool insertNode(ListNode* q, DataType newData); //插入结点

	bool removeNode(ListNode* q); //删除结点
	ListNode* findNode(DataType value); //查找指定值的结点并返回地址
	bool cleanLink(); //清空链表

	DataType getNodeData(ListNode* p); //获取结点数据
private:
	ListNode* head; //头结点
};
/*************定义链表结点****************/
template <typename DataType> class ListNode
{
public:
	ListNode()
	{
		next = NULL;
	}
	ListNode(DataType item, ListNode<DataType>* nextNode = NULL)
	{
		data = item;
		next = nextNode;
	}
	~ListNode()
	{
		next = NULL;
	}
	//获取结点内的数据
	DataType getData()
	{
		return data;
	}
	//获取指针域
	ListNode* getNext()
	{
		return next;
	}
private:
	friend typename LinkList<DataType>; //将 LinkList 设为友元类，方便其对 node 的成员数据和方法的访问
	DataType* next; //指向下一个结点的指针
	DataType data; //结点中的数据
};

//链表的基本操作
//插入结点
//*************在链表的第 i 个结点后插入新结点***************/ 
template<typename DataType> bool LinkList<DataType>::insertNode(int i, DataType newData)
{
	ListNode<DataType> *p = head; //设置游标指针，初始化为头结点地址
	int j;
	for (j = 1; j <= i - 1; j++) //查找第 i 个结点，指针需要移动 i-1 次
	{
		p = p->next;
		if (p == NULL) //如果指针为空，则不存在该结点，或已到表尾
		{
			break;
		}

	}
	if (p == NULL && j < (i - 1)) //指针为空且没有到第 i 个位置，说明不存在第 i 个结点
	{
		std::cout << "插入位置无效！" << endl;
		return false;
	}
	ListNode<DataType>* node = new ListNode<DataType>(newData); //建立新结点 node 

	node->next = p->next; //将 node 的 next 指针赋值为 p 的后继结点地址
	p->next = node; //p 的后继指针指向 node 
	return true;
}


/***********************在单链表表尾添加新结点*****************************/
template<typename DataType> bool LinkList<DataType>::insertNode(DataType newData)
{
	ListNode<DataType>* p = head; //设置游标指针
	ListNode<DataType>* node = new ListNode<DataType>(newData); //创建新结点
	if (node == NULL) //如果新结点内存分配失败，返回 false 
	{
		return false;
	}
	while (p->next != NULL) //遍历单链表，找到尾结点
	{
		p = p->next;
	}
	p->next = node; //将尾结点 next 指针指向新结点
	return true;
}

//删除结点
/*******************删除指定结点*******************/
template<typename DataType> bool LinkList<DataType>::removeNode(ListNode <DataType>* q)
{
	if (q == NULL) //判断待删除结点是否存在
	{
		std::cout << "待删除结点不存在！" << std::endl;
		return false;
	}
	ListNode<DataType>* tempPointer = head; //设置游标指针，初始化为头结点
	while (tempPointer->next != q) //遍历单链表，找到 q 所指向结点的前驱结点
	{
		tempPointer = tempPointer->next;
	}
	tempPointer->next = q->next; //将 q 结点的后继结点地址赋值给其前驱结点的 next 指针
	
	delete q; //回收结点 q 的空间
	return true;
}

//查找特定值的结点
/*********************查找指定值的结点***************/
template<typename DataType> ListNode<DataType>* LinkList<DataType>::
findNode(DataType value)
{
	ListNode<DataType>* currentPointer = head; //设置游标指针
	//判定游标指针所指结点的值是否与 value 相等
	while (currentPointer != NULL && currentPointer->data != value)
	{
		currentPointer = currentPointer->next;
	}
	if (currentPointer == NULL) //判定所找结点是否存在
	{
		std::cout << "没有找到该结点！程序异常退出！" << endl;
		exit(1);
	}
	else
	{
		return currentPointer; //返回所找到的结点的指针
	}
}

//清空链表
/********************清空链表***********************/
template<typename DataType> void LinkList<DataType>::cleanLink()
{
	ListNode<DataType>* current = head; //设置游标指针
	while (head->next != NULL) //判断 head 的后继结点是否为 NULL 
	{
		current = head->next; //将 current 指向 head 的后继结点
		head->next = current->next;//将 current 的后继地址赋值给 head 的 next 域
		delete current; //回收 current 结点所占的空间
	}
}
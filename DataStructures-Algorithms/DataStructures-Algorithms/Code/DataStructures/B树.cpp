//B树
//定义
/************************B 树的定义***********************/
template<typename DataType> class BTree
{
public:
	BTree()
	{
		root = NULL;
	}
	~BTree()
	{
		//clear(); //清除 B 树
	}
private:
	static const int t = 2; //B 树的最小度数
	static const int Key_Max = 2 * t - 1; //结点中包含的关键字的最大个数
	static const int Key_Min = t - 1; //结点中包含的关键字的最小个数
	static const int Child_Max = Key_Max + 1; //孩子结点的最大个数
	static const int Child_Min = Key_Min + 1; //孩子结点的最小个数
	template<class DataType> struct Node
	{
		bool isLeaf;
		int Key_Num; //结点包含的关键字的个数
		DataType keyArray[Key_Max]; //关键字数组
		Node<DataType>* pChild[Child_Max]; //子树指针数组
		Node<DataType>(bool b = true, int n = 0) :isLeaf(b), Key_Num(n) {}
		//默认初始化结点函数
	};
	Node<DataType>* root; //B 树根结点
public:
	/*******************B 树的搜索**********************/
	template<class DataType> struct SearchResult
		//搜索操作返回关键字所在结点和序列
	{
		Node<DataType>* nodeIndex; //所在的结点
		int index; //在结点中的关键字序列号
	};
	typedef struct SearchResult<DataType> SearchResult<DataType>;
	SearchResult<DataType>* searchNode(Node<DataType>* node, DataType key);
};

//搜索B树
/*******************B 树的搜索**********************/
/*如果搜索成功，返回所找到的关键字所在的结点地址和关键字序列的有序对*/
/*****用结构体 SearchResult 表示****************/
template<typename DataType> SearchResult<DataType>* BTree<DataType>::searchNode(Node<DataType>* node,
	DataType key)
{
	SearchResult<DataType>* srP; //声明结构体
	int i = 0;
	while (i < node->Key_Num && key > node->keyArray[i])
		//在结点中循环比较关键字
	{
		i++;
	}
	if (i < node->Key_Num && key == node->keyArray[i])
		//如果 key 在该结点中，则返回结点指针和关键字序列
	{
		srP = (SearchResult*)malloc(sizeof(struct SearchResult));
		srP->nodeIndex = node;
		srP->index = i;
		return srP;
	}
	if (node->isLeaf) //如果 key 不在该结点中，且结点为叶子结点则返回 NULL 
	{
		return NULL;
	}
	else
	{
		return searchNode(pChild[i], key); //否则递归访问子结点
	}
}
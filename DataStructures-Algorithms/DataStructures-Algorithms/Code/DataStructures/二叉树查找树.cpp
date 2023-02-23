//二叉树查找树
//定义
/*********************二叉查找树结点定义************************/
template<typename DataType> class SBTNode
{
public:
	/****************构造函数*******************/
	SBTNode()
	{
		lChild = rChild = parent = NULL;
		data = NULL;
	}
	SBTNode(DataType d)
	{
		data = d;
		lChild = rChild = parent = NULL;
	}
	/*********************析构函数*******************/
	~SBTNode()
	{
		lChild = rChild = parent = NULL;
		delete this;
	}
private:
	SBTNode<DataType>* lChild, * rChild, * parent; //声明左孩子、右孩子和父结点指针
	DataType data; //数据域
};
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

/////基本操作
//二叉查找树排序
/****************有序输出***********************/
template<typename DataType> void SBT<DataType>::inSort(SBTNode<DataType> *node)
{
	if (node != NULL)
	{
		inSort(node->lChild); //递归遍历左孩子结点
		std::cout << node->data << std::endl; //输出结点数据
		inSort(node->rChild); //递归调用右孩子结点
	}
}
//二叉查找树的插入操作
/******************插入操作**********************/
template<typename DataType> void SBT<DataType>::insert(SBTNode<DataType> *node)
{
	SBTNode<DataType>* cur, * temp = NULL; //设置两个中间指针
	cur = root;
	while (cur != NULL) //遍历二叉树
	{
		temp = cur;
		if (node->data < cur->data) //比较待插入结点与当前结点的值
		{
			cur = cur->lChild; //如果小于，则遍历左子树
		}
		else
		{
			cur = cur->rChild; //否则遍历右子树
		}
	}
	node->parent = temp; //将最后一个有效结点设置为待插入结点的父结点
	if (temp == NULL)
	{
		root = node; //如果根结点为空，则待插入结点为根结点
		count++;
	}
	else
	{
		if (node->data < temp->data) //比较大小
		{
			temp->lChild = node; //如果小于，则插入为左孩子
			count++；
		}
		else
		{
			temp->rChild = node; //否则为右孩子
			count++;
		}
	}
}

//二叉查找树的删除结点操作
/******************删除结点***********************/
template<typename DataType> void SBT<DataType>::deleteNode(SBTNode
	<DataType>* node)
{
	SBTNode<DataType>* p; //声明待删除结点的父结点指针
	p = node->parent;
	if (node->lChild == NULL && node->rChild == NULL)
		//如果该结点是叶子结点则直接删除
	{
		delete node;
		count--; //二叉查找树结点数目减 1 
	}
	else if (node->lChild == NULL && node->rChild != NULL)
		//如果结点只有左子树
	{
		if (p == NULL) //判断结点是否为根结点
		{
			root = node->rChild;
			count--;
		}
		else
		{
			node->rChild->parent = p; //如不是根结点，则右孩子结点的父结
			点指针指向 node 的父结点
				if (p->lChild == node) //判断待删除结点是父结点的左孩子还是右孩子
					p->lChild = node->rChild;
				else
					p->rChild = node->rChild;
			delete node;
			count--;
		}
	}
	else if (node->lChild != NULL && node->rChild == NULL) //如果结点没有右子树
	{
		if (p == NULL)
		{
			root = node->lChild;
			count--;
		}
		else
		{
			node->lChild->parent = p;
			if (p->lChild == node)
				p->lChild = node->lChild;
			else
				p->rChild = node->lChild;
			delete node;
			count--;
		}
	}
	else
	{
		//如果结点的左右孩子均存在，用 node 的右子树中最小的结点替换 node 
		SBTNode<DataType>* left, * curP; //left 指针指向 node 的右孩子
		left = node->rChild;
		while (left != NULL) //遍历 node 右孩子结点左子树
		{
			curP = left;
			left = left->lChild;
		}
		if (curP->rChild != NULL)
		{
			if (curP->lChild == curP)
				curP->parent->lChild = curP->rChild;
			else
				curP->parent->rChild = curP->rChild;
		}
		else
		{
			curP->parent->lChild = NULL; //替换结点
		}
		curP->parent = p;
		curP->lChild = node->lChild;
		curP->rChild = node->rChild;
		if (p->lChild == node)
		{
			p->lChild = curP;
		}
		else
		{
			p->rChild = curP;
		}
		delete node;
		count--;
	}
}

//二叉查找树的查询
/********************查询结点*******************/
template<typename DataType> SBTNode<DataType>* SBT<DataType>::search(DataType k)
{
	SBTNode<DataType>* node = root; //设置移动指针指向根结点
	while (node != NULL)
	{
		if (k < node->data) //如果 K 小于结点值，则继续查找左子树
			node = node->lChild;
		else if (k > node->data) //如果 K 大于结点值，则继续查找右子树
			node = node->rChild;
		else
			break; //如果相等，则退出循环
	}
	return node; //返回结点指针
}
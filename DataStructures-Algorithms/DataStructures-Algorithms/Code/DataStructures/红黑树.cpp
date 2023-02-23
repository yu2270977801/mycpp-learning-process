//红黑树
//定义
/*********************红黑树结点定义************************/
template<typename DataType> class RBTNode
{
	friend class RBT<DataType>;
public:
	/****************构造函数*******************/
	RBTNode() //构造 nil 结点
	{
		lChild = rChild = parent = NULL;
		color = 0; //颜色为黑色
		data = NULL;
	}
	RBTNode(DataType d, int color) //构造内结点
	{
		data = d;
		lChild = rChild = parent = NULL;
		this->color = color;
	}
	/*********************析构函数*******************/
	~RBTNode()
	{
		lChild = rChild = parent = NULL;
		delete this;
	}
private:
	SBTNode<DataType>* lChild, * rChild, * parent; //声明左孩子、右孩子和父结点指针
	DataType data; //数据域
	int color; //颜色域，0 表示黑，1 表示红
};
/*****************************红黑树定义******************/
template<typename DataType> class RBT
{
public:
	/******************构造函数********************/
	RBT()
	{
		root = NULL;
		nil = new RBTNode<DataType>();
		count = 0;
	}
	RBT(DataType data)
	{
		root = new RBTNode<DataType>(data，0); //构建根结点，根结点为黑色
		nil = new RBTNode<DataType>();
		count = 1;
	}
	/*********************左旋转**********************/
	void leftRotated(RBTNode<DataType>* node);
private:
	RBTNode<DataType>* root; //根结点指针
	RBTNode<DataType>* nil; //哨兵叶子结点
	int count; //结点数目
};

////基本操作
//旋转操作
/*********************左旋转**********************/
template<typename DataType> void RBT<DataType>::leftRotated(RBTNode<DataType>* node)
{
	if (node->rChild != nil) //判断 node 结点的右孩子是否为 nil 
	{
		RBTNode<DataType>* y = node->rChild;//设置结点 y 为 node 的右孩子结点
		node->rChild = y->lChild; //左旋之后 y 结点的左孩子成为 node 的右孩子
		if (y->lChild != nil)
			y->lChild->parent = node;//如果 y 的左孩子不为空，则将其父结点设为 node 
		y->parent = node->parent; //将 y 的父结点设为 node 的父结点
		if (node->parent == nil)
			root = y;
		else if (node->parent->lChild == node) //判断 node 是父结点的左孩子还是右孩子，更改为 y
		{
		node->parent->lChild = y;
		}
		else
		{
			node->parent->rChild = y;
		}
		y->lChild = node; //y 结点的左孩子更改为 node 
		node->parent = y; //node 的父结点更改为 y 
	}
}

//插入结点
/**********************插入结点操作***************/
template<typename DataType> void RBT<DataType>::insert(RBTNode<DataType>
	* node)
{
	SBTNode<DataType>* cur, * temp = nil; //设置两个中间指针
	cur = root;
	while (cur != nil) //遍历二叉树
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
	if (temp == nil)
	{
		root = node; //如果根结点为空，待插入结点为根结点
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
	node->lChild = nil; //让新结点的左右孩子指向 nil 结点
	node->rChild = nil;
	node->color = 1; //颜色为红色
	insertKeppRB(node); //调用 keepRB()函数恢复红黑性质 
}


//
	/*********************保持红黑性质***************/
	template<typename DataType> void RBT<DataType>::insertKeepRB(RBTNode
		<DataType>* node)
	{
		RBTNode<DataType>* y;
		while (node->parent->color == 1)
		{
			/**********node 结点的父结点是左孩子的情况****************/
			if (node->parent->parent->lChild == node->parent)
			{
				y = node->parent->parent->rChild; //设置 y 为 node 的叔叔结点
				if (y->color == 1) //情况（a）的解决
				{
					node->parent->color = 0; //更改父结点和叔结点的颜色为黑色
					y->color = 0;
					node->parent->parent->color = 1; //更改祖结点的颜色为红色
					node = node->parent->parent; //node 指向祖结点递归向上更改
				}
				else if (node->parent->lChild == node) //情况（b）
				{
					node->parent->color = 0; //更改父结点为黑
					node->parent->parent->color = 1; //更改祖结点为红
					rightRotated(node->parent->parent);//右旋祖结点
				}
				else if (node->parent->rChild == node) //情况（c）
				{
					node = node->parent;
					leftRotated(node); //先左旋父结点，变成情况（b）
					node->parent->color = 0;
					node->parent->parent->color = 1; //更改左旋后父结点和祖结
					点颜色分别为黑和红
						rightRotated(node->parent->parent);//右旋祖结点
				}
			}
			/**********node 结点的父结点是右孩子的情况****************/
			/*****操作和算法与父结点是左孩子时对称，将用到左右的地方交换***/
			else
			{
				y = node->parent->parent->lChild;
				if (y->color == 1)
				{
					node->parent->color = 0;
					y->color = 0;
					node->parent->parent->color = 1;
					node = node->parent->parent;
				}
				else if (node->parent->rChild == node)
				{
					node->parent->color = 0;
					node->parent->parent->color = 1;
					leftRotated(node->parent->parent);
				}
				else if (node->parent->lChild == node)
				{
					node = node->parent;
					rightRotated(node);
					node->parent->color = 0;
					node->parent->parent->color = 1;
					leftRotated(node->parent->parent);
				}
			}
		}
		root->color = 0; //将根结点设置为黑色，可能导致所有路径黑高度都加 1 
	}


//删除结点操作
/***********************删除结点操作**************/
	template<typename DataType> void RBT<DataType>::deleteNode(RBTNode<Data
		Type>* node)
	{
		RBTNode<DataType>* y, * x; //设置两个游标结点指针
		if (node->rChild == nil || node->lChild == nil)
			//如果 node 只有一个孩子或没有孩子结点
		{
			y = node; //则 y 指向 node 本身
		}
		else
		{
			y = succNode(node); //如果 node 有两个孩子结点，则 y 指向 node 的后继结点
		}
		if (y->lChild != nil) //y 左孩子不为空则 x 为其左孩子
		{
			x = y->lChild;
		}
		else
		{
			x = y->rChild; //否则为其右孩子
		}
		x->parent = y->parent; //设置 x 的父结点为 y 的父结点
		if (y->parent == nil)
		{
			root = x;
		}
		else if (y == y->parent - lChild) //确定 x 在 y 的父结点的位置
		{
			y->parent->lChild = x;
		}
		else
		{
			y->parent->rChild = x;
		}
		if (y != node) //如果 y 不是指向 node 的，则将 y 的数据和颜色复制到 node 的结点中
		{
			node->data = y->data;
			node->color = y->color;
		}
		if (y->color == 0)
			deleteKeepRB(x); //如果 y 的颜色为黑色则进行红黑性质调整
		delete y; //删除结点 y 
		count--;
	}
	/******************寻找后继结点*****************/
	template<typename DataType> void RBT<DataType>::succNode(RBTNode<Data
		Type>* node)
	{
		if (node->rChild != NULL) //如果 node 的右子树不为空，则返回右子树中最小的值
		{
			RBTNode<DataType>* left = node->rChild;
			while (left->lChild != NULL)
			{
				left = left->lChild;
			}
			return left;
		}
		RBTNode<DataType>* p = node->parent;
		while (p != nil && node == p->rChild) //如果 node 的右子树为空，返回的结点 p 
		{ //满足 p 是 node 的最低祖先结点，且 p 的左孩子也是 node 的祖先结点
			node = p;
			p = p->parent;
		}
		return p;
	}

//
	/*************************删除保持红黑性质*******************/
	template<typename DataType> void RBT<DataType>::deleteKeepRB(RBTNode
		<DataType>* x)
	{
		RBTNode<DataType>* w; //设置兄弟结点指针
		while (x != root && x->color == 0) //当 x 递归为 root 时停止循环
		{
			if (x == x->parent->lChild) //x 为左孩子时的情况
			{
				w = x->parent->rChild;
				if (w->color == 1) //情况 1 
				{
					w->color = 0;
					x->parent->color = 1;
					leftRotated(x->parent); //对 x 父结点左旋
					w = x->parent->rChild; //设置新的兄弟结点
				}
				if (w->lChild->color == 0 && w->rChild->color == 0) //情况 2 
				{
					w->color = 1;
					x = x->parent;
				}
				else if (w->rChild->color == 0) //情况 3 
				{
					w->lChild->color = 0;
					w->color = 1;
					rightRotated(w); //对兄弟结点进行右旋
					w = x->parent->rChild;
				}
				else
				{
					w->color = x->parent->color; //情况 4 
					x->parent->color = 0;
					w->rChild->color = 0;
					leftRotated(x->parent); //左旋父结点
					x = root; //标记循环停止，将 x 设为根结点
				}
			}
			else
			{
				/******x 为右孩子时的情况，与左孩子时对称，只需更改左右标记******/
				w = x->parent->lChild;
				if (w->color == 1)
				{
					w->color = 0;
					x->parent->color = 1;
					rightRotated(x->parent);
					w = x->parent->lChild;
				}
				if (w->lChild->color == 0 && w->rChild->color == 0)
				{
					w->color = 1;
					x = x->parent;
				}
				else if (w->lChild->color == 0)
				{
					w->rChild->color = 0;
					w->color = 1;
					leftRotated(w);
					w = x->parent->lChild;
				}
				else
				{
					w->color = x->parent->color;
					x->parent->color = 0;
					w->lChild->color = 0;
					rightRotated(x->parent);
					x = root;
				}
			}
		}
		x->color = 0; //x 确保为黑色
	}

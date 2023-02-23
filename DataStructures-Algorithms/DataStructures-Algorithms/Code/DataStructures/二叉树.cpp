//树

//二叉树
//定义
/***********二叉树结点定义*************/
template <class DataType> class BinaryTreeNode
{
public:
	/**********构建空结点*********/
	BinaryTreeNode()
	{
		data = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	/*************构建一个指定数据域的结点*************/
	BinaryTreeNode(DataType newData)
	{
		data = newData;
		lChild = rChild = NULL;
	}
private:
	DataType data; //数据域
	BinaryTreeNode* lChild; //左子树指针
	BinaryTreeNode* rChild; //右子树指针
};


//二叉树的顺序存储结构
/*******************二叉树的线性表示*******************/
template<typename DataType> class SeqBT
{
public:
	SeqBT(int nodes) //用参数设置顺序结构的数组大小
	{
		if (nodes > 0)
		{
			maxNode = nodes; //设置最多结点个数
			data = new DataType[maxNode]; //分配数组空间
		}
	}
	~SeqBT()
	{
		delete[] data;
	}
private:
	int maxNode; //二叉树作为完全二叉树时的结点个数
	DataType* data; //声明成员数组用以存储结点信息
};


//二叉树的链式存储结构
/***********二叉树结点定义*************/
template <class DataType> class BinaryTreeNode
{
public:
	/**********构建空结点*********/
	BinaryTreeNode()
	{
		data = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	/*************构建一个指定数据域的结点*************/
	BinaryTreeNode(DataType newData)
	{
		data = newData;
		lChild = rChild = NULL;
	}
private:
	DataType data; //数据域
	BinaryTreeNode* lChild; //左子树指针
	BinaryTreeNode* rChild; //右子树指针
};
/************二叉树定义****************************/
template<typename DataType> class BinaryTree
{
public:
	BinaryTree()
	{
		root = new BinaryTreeNode<DataType>(); //初始化根结点
	}
private:
	BinaryTreeNode<DataType>* root; //根结点
};

////二叉树基本操作
///二叉树遍历
/****************先序遍历************************/
template<typename DataType> void BinaryTree<DataType>::preOrder(Binare
	TreeNode<DataType>* node)
{
	if (node != NULL)
	{
		std::cout << node->getData() << std::endl; //输出指定结点信息
		preOrder(node->getLeftNode()); //递归调用先序遍历函数 
		preOrder(node->getRightNode());
	}
}

/*****************中序遍历********************/
template<typename DataType> void BinaryTree<DataType>::inOrder(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL) //判断起始结点是否为空，若为空递归停止
	{
		inOrder(node->getLeftNode()); //递归遍历左子树
		std::cout << node->getData() << std::endl; //输出结点信息
		inOrder(node->getRightNode()); //递归遍历右子树
	}
}

/***************后序遍历*********************/
template<typename DataType> void BinaryTree<DataType>::postOrder(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL) //判断指定结点是否为空
	{
		postOrder(node->getLeftNode()); //递归遍历左子树
		postOrder(node->getRightNode()); //递归遍历右子树
		std::cout << node->getData() << std::endl; //输出指定结点
	}
}

/**********************层序遍历****************/
//层序遍历————广度优先遍历（从根结点开始按层遍历，根结点为第 1 层，它的子结点为第 2 层，依次从上到下，从左到右遍历。）
template<typename DataType> void BinaryTree<DataType>::layOrder(Binary
	TreeNode<DataType>* node)
{
	int max = 50; //队列大小，在不知道树的大小之前尽量设置大一点
	int front, rear; //设置队首队尾
	BinaryTreeNode<DataType>* current; //设置指向当前结点的指针
	int count = 0; //队列中的元素个数 
	if (node != NULL) //判断初始结点是否为空
	{
		DataType[] * queue = new DataType[max]; //为队列申请空间
		front = rear = 0; //初始化队列指针
		queue[rear] = node; //将初始根结点入队
		rear++; //队尾指针后移
		count++; //元素个数加 1 
		while (count != 0) //判断队列元素是否完全出队
		{
			current = queue[front]; //队首元素出队，设置为当前结点
			std::cout << current->getData() << std::endl; //输出队首元素的值
			if (current->getLeftNode() != NULL)
				//判断出队元素的左子结点是否为空，若不为空，则入队
			{
				queue[rear] = current->getLeftNode();
				rear = (rear + 1) % max;
				count++;
			}
			if (current->getRightNode() != NULL)
				//判断出队元素的右子结点是否为空，若不为空，则入队
			{
				queue[rear] = current->getRightNode();
				rear = (rear + 1) % max;
				count++;
			}
			front = (front + 1) % max; //出队操作后重新设置队首指针
			count--; //队列中元素个数减 1 
		}
	}
}

//构建一颗二叉树
template<class DataType> class BinaryTree;
/***********二叉树结点定义*************/
template <class DataType> class BinaryTreeNode
{
public:
	friend class BinaryTree<DataType>;
	/**********构建空结点*********/
	BinaryTreeNode()
	{
		data = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	/*************构建一个指定数据域的结点*************/
	BinaryTreeNode(DataType newData)
	{
		data = newData;
		lChild = rChild = NULL;
	}
	/***************获取数据域*****************/
	DataType getData()
	{
		if (data != NULL)
			return data;
		return NULL;

	}
	/*****************获取左子结点*************/
	BinaryTreeNode<DataType>* getLeftNode()
	{
		return lChild;
	}
	/*****************获取右子结点*************/
	BinaryTreeNode<DataType>* getRightNode()
	{
		return rChild;
	}

private:
	DataType data; //数据域
	BinaryTreeNode* lChild; //左子树指针
	BinaryTreeNode* rChild; //右子树指针
};
/************二叉树定义****************************/
template<typename DataType> class BinaryTree
{
public:
	BinaryTree()
	{
		root = new BinaryTreeNode<DataType>(); //初始化根结点
	}
	BinaryTree(DataType rootData)
	{
		root = new BinaryTreeNode<DataType>(DataType rootData);
		//建立有数据的根结点
		root->lChild = NULL;
		root->rChild = NULL;
	}
	~BinaryTree()
	{
		delete root;
	}

private:
	BinaryTreeNode<DataType>* root; //根结点
};

//求一个结点的父结点
/******************寻找父结点**********************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::parentNode(BinaryTreeNode<DataType>* node)
{
	if (node == NULL || node == root)
		return NULL;
	int max = 50; //队列大小，在不知道树的大小之前尽量设置大一点
	int front, rear; //设置队首队尾
	BinaryTreeNode<DataType>* current, * child; //设置指向当前结点的指针
	和指向孩子结点的指针
		int count = 0; //队列中的元素个数 
	if (node != NULL) //判断初始结点是否为空
	{
		DataType[] * queue = new DataType[max]; //为队列申请空间
		front = rear = 0; //初始化队列指针
		queue[rear] = node; //将初始根结点入队
		rear++; //队尾指针后移
		count++; //元素个数加 1 
		while (count != 0) //判断队列元素是否完全出队
		{
			current = queue[front]; //队首元素出队，设置为当前结点

			if (current->getLeftNode() != NULL)
				//判断出队元素的左子结点是否为空，若不为空，则入队
			{
				child = current->getLeftNode();
				if (child == node) //比较出队结点的左孩子结点与指定结点
					return current; //若相等，则返回出队结点
				queue[rear] = child;
				rear = (rear + 1) % max;
				count++;
			}

			if (current->getRightNode() != NULL)
				//判断出队元素的右子结点是否为空，若不为空，则入队
			{
				child = current->getRightNode();
				if (child == node) //比较出队结点的右孩子结点与指定结点
					return current; //若相等，则返回出队结点
				queue[rear] = child;
				rear = (rear + 1) % max;
				count++;
			}
			front = (front + 1) % max; //出队操作后重新设置队首指针
			count--; //队列中元素个数减 1 
		}
		return NULL;
	}
}

//求指定结点i的子节点
/*******************返回指定结点的左孩子结点****************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::
getLChild(BinaryTreeNode<DataType>* node)
{
	if (node == NULL) //判断指定结点是否为空
		return NULL;
	return node->lChild; //返回指定结点的左孩子指针
}
/*******************返回指定结点的左孩子结点****************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::
getRChild(BinaryTreeNode<DataType>* node)
{
	if (node == NULL) //判断指定结点是否为空
		return NULL;
	return node->rChild; //返回指定结点的右孩子指针
}

//求结点的左兄弟结点或右兄弟结点
/************************求兄弟结点************************/
template<typename DataType> BinaryTreeNode<DataType>*
BinaryTree<DataType>::getBrotherNode(BinaryTreeNode<DataType>
	* node)
{
	if (node == NULL) //判断指定结点是否为空
		return NULL;
	BinaryTreeNode<DataType>* parent = BinaryTree<DataType>::parentNode
	(node); //获取指定结点的父结点
	if (parent == NULL)
		return NULL; //若父结点为空，说明是根结点，无兄弟结点，返回 NULL 
	if (parent->lChild == node) //判断指定结点是否父结点的左子结点
		return parent->rChild; //如指定结点是左孩子，则返回父结点的右孩子结点作为兄弟结点
		if (parent->rChild == node) //判断指定结点是否父结点的右孩子结点
			return parent->lChild; //如指定结点是左孩子，则返回父结点的右孩子结点作为兄弟结点
}

//求一颗二叉树的高度
/*************************求二叉树的高度************************/
/*******************参数是设计的栈的大小，一般设为二叉树的结点数*************/
template<typename DataType> int BinaryTree<DataType>::getDepth(int
	numberofNodes)
{
	BinaryTreeNode<DataType>* nodeStack = new BinaryTreeNode<DataType>[numberof
		Nodes]; //设置存储二叉树结点的栈
	int depthStack[numberofNodes]; //声明深度栈
	int currentDepth, maxDepth = 0; //currentDepth 表示当前的深度，
	maxDepth 表示最大深度
		int top = -1; //栈的游标指针初始值
	BinaryTreeNode<DataType>* node = root; //设置当前访问的结点指针并初始化为
	根结点
		if (node != NULL) //判断当前访问的结点是否为空
		{
			currentDepth = 1; //初始化当前深度为 1，根结点为第 1 层
			/*********循环遍历整棵树，将访问的结点入栈*********
			***********并不停反复查找最长的路径*****************/
			do {
				while (node != NULL)
				{
					nodeStatck[++top] = node; //将访问到的不为空的结点入栈，直至
					遇到空结点停止
						depthStack[top] = currentDepth; //将相应的深度入栈
					node = node->lChild; //继续访问当前结点的左孩子
					currentDepth++; //当前深度加 1 
				}
				node = nodeStack[top]; //一条路径走到尽头时，出栈栈顶元素
				尝试新路径
					currentDepth = depthStack[top--];
				if (node->lChild == NULL && node->rChild == NULL)
					//判断是否叶子结点
				{
					if (currentDepth > maxDepth) //如果该叶子结点的深度大于最大深度，
						更改最大深度
						maxDepth = currentDepth;
				}
				node = node->rChild; //开始访问出栈结点的右子树
				currentDepth++;
			} while (!(node == NULL && top == -1)); //访问结点为空且栈空时循环结束，此时的最大深度就是树的高度
		}
	return maxDepth;
}

//将一棵二叉树插入另一棵二叉树的结点i，作为i的左（右）子树
/********************插入子二叉树***********/
template<typename DataType> void BinaryTree<DataType>::insertSubBT(BinaryTree<DataType>* bt, BinaryTreeNode<DataType>* node)
{
	if (node == NULL) //判断待插入的子树和插入点是否为空
		return NULL;
	if (bt->root == NULL)
		return NULL;
	if (node->lChild == NULL) //如果待插入点左子树为空，则插入到左子树
		node->lChild = bt->root;
	else if (node->rChild == NULL) //如果右子树为空，则插入为右子树 
		node->rChild = bt->root;
	else
	{ //否则，插入到左子树，且将原来的左子树删除
		BinaryTreeNode<DataType>* p = node->lChild;
		node->lChild = bt->root;
		delete p;
	}
}

//删除结点i的左（右）子树
/****************************删除所有结点**********************/
template<typename DataType> void BinaryTree<DataType>::deleteNodes(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL)
	{
		deleteNodes(node->lChild); //递归遍历然后删除遍历的结点
		deleteNodes(node->rChild);
		delete node;
	}
}
/*************************删除子树****************************/
template<typename DataType> bool BinaryTree<DataType>::deleteSubTree(Binary
	TreeNode<DataType>* node, int i)
	/*******i 为选择数，1 表示删除左子树，2 表示删除右子树，3 表示两个子树都删除**********/
{
	if (node == NULL)
		return false;
	BinaryTreeNode<DataType>* p; //声明临时变量
	switch (i) //根据参数 i 判定是删除左子树还是删除右子树
	{
	case 1:
		p = node->lChild;
		deleteNodes(p); //调用删除所有结点函数
		node->lChild = NULL;
		return true;
	case 2:
		p = node->rChild;
		deleteNodes(p);
		node->rChild = NULL;
		return true;
	case 3:
		p = node->lChild;
		deleteNodes(p);
		node->lChild = NULL;
		p = node->rChild;
		deleteNodes(p);
		node->rChild = NULL;
		return true;
	}
	return false;
}

//销毁一颗二叉树
//方法一
/************************销毁二叉树*********************/
template<typename DataType> void BinaryTree<DataType>::destroyBT(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL) //判断结点是否为空
	{
		destroyBT(node->lChild); //后序遍历所有结点，并删除相应结点
		destroyBT(node->rChild);
		delete node;
	}
	root = NULL; //将根结点置为 NULL，形成空树
}
//方法二————销毁二叉树我们可以在 C++中作为析构函数的功能，所以我们常常将二叉树的析构函数定义为：
~BinaryTree()
{
	BinaryTreeNode<DataType>* node = root;
	if (node != NULL) //判断结点是否为空
	{
		destroyBT(node->lChild); //后序遍历所有结点，并删除相应结点
		destroyBT(node->rChild);
		delete node;
	}
	delete root; //删除根结点
}

//求结点i的深度
/*************************求结点 i 的深度**************************/
template<typename DataType> int BinaryTree<DataType>::getDepthofNode
(DataType i)
{
	int stackSize = 50;
	BinaryTreeNode<DataType>* nodeStack = new BinaryTreeNode<DataType>
		[stackSize]; //设置存储二叉树结点的栈
	int flagStack[stackSize]; //存储每个结点的状态
	int flag = 0; //flag 表示每个结点的访问状态，0 表示访问一次，1 表示访问两次
	int top = -1; //栈的游标指针初始值
	BinaryTreeNode<DataType>* node = root;//设置当前访问的结点指针并初始化为根
	结点

		/******循环后序遍历树，将访问的结点入栈************/
		/****检验是否访问的结点就是待求结点***************/
		do {
			while (node != NULL)
			{
				nodeStatck[++top] = node; //将访问到的不为空的结点入栈，直至
				遇到空结点停止
					flagStack[top] = 0; //将相应结点访问状态入栈，第一次访问状态为 0 
				node = node->lChild; //继续访问当前结点的左孩子 
			}
			node = nodeStack[top]; //一条路径走到尽头时，出栈栈顶元素尝试新路径
			flag = flagStack[top--]; //获取结点的访问状态
			if (flag == 0) //判断该结点是第几次访问
			{
				nodeStatck[++top] = node; //将第 1 次访问的结点再次入栈
				flagStack[top] = 1; //改变相应的访问状态
				node = node->rChild;
			}
			else
			{
				if (node->data == i) //如果结点第 2 次访问则判断其是否为我们需要寻找的结点
					return top + 2; //如果找到该结点，则其深度为栈中元素个数 + 1，即栈顶指针 + 2
					node = NULL; //如果不是该结点，则继续出栈
			}
		} while (!(node == NULL && top == -1)); //访问结点为空且栈空时循环结束

}

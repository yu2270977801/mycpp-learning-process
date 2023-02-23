//线索二叉树
//基本操作
#include <iostream> 
template<typename DataType> class ThreadBT;
template<typename DataType> class ThreadBTNode
{
public:
	friend class ThreadBT<DataType>;
	ThreadBTNode(DataType newData) //带数据构造函数
	{
		lFlag = rFlag = 0;
		this->data = newData;
		lChild = rChild = NULL;
	}
	ThreadBTNode() //空结点构造函数
	{
		lFlag = rFlag = 0;
		lChild = rChild = NULL;
	}
private:
	ThreadBTNode<DataType>* lChild, rChild; //左右指针域
	int lFlag, rFlag; //标志量
	DataType data; //数据域
};
template<typename DataType> class ThreadBT
{
public:
	ThreadBT()
	{
		root = NULL;
	}
	ThreadBT(DataType data)
	{
		root = new ThreadBTNode<DataType>(data);
	}
private:
	ThreadBTNode<DataType>* root; //根结点
};

//寻找结点 node 的前驱结点
/***********************寻找结点 node 的前驱结点*******************/
template<typename DataType> ThreadBTNode<DataType>* ThreadBT<DataType>::prior
(ThreadBTNode<DataType>* node)
{
	ThreadBTNode<DataType>* s; //设置访问结点指针
	s = node->lChild;
	if (node->lFlag == 1) //判断 s 是否线索，如果是线索则直接返回
	{
		while (s->rFlag == 1) //循环寻找结点的右子结点，找到 node 左子树中的最右结点
		{
			s = s->rChild;
		}
	}
	return s; //返回 node 的前驱
}

//寻找结点 node 的后继结点
/************************寻找结点的后继结点***********************/
template<typename DataType> ThreadBTNode<DataType>* ThreadBT<DataType>::succ
(ThreadBTNode<DataType>* node)
{
	ThreadBTNode<DataType>* s; //设置访问结点指针
	s = node->rChild;
	if (node->rFlag == 1) //判断 s 是否线索，如果是线索则直接返回
	{
		while (s->lFlag == 1) //循环寻找结点的左子结点，找到 node 右子树中的最左结点
		{
			s = s->lChild;
		}
	}
	return s; //返回 node 的前驱
}

//利用线索二叉树遍历二叉树
/************************中序遍历二叉树***********************/
template<typename DataType> void ThreadBT<DataType>::inOrder()
{
	if (root != NULL)
	{
		ThreadBTNode<DataType>* s;
		s = root;
		while (prior(s) != NULL) //找到起始结点
		{
			s = prior(s);
		}
		while (succ(s) != NULL) //从起始结点开始遍历后继结点
		{
			cout << s->data << endl;
			s = succ(s);
		}
	}
}

//线索二叉树的更新
/************************线索二叉树的更新***********************/
template<typename DataType> void ThreadBT<DataType>::update(ThreadBTNode
	<DataType>* s, ThreadBTNode<DataType>* p)
{
	ThreadBTNode<DataType>* next;
	next = root;
	p->rChild = s->rChild;
	p->rFlag = s->rFlag;
	/********如果 s 右子树为空，则 s 的直接后继就成为 p 的直接后继***
	*********如果 s 右子树不为空，则 s 右子树成为 p 的右子树******/
	p->lChild = s; //s 成为 pde 直接前驱
	p->lFlag = 0; //设置线索标志
	s->rChild = p; //p 成为 s 的右孩子
	s->rFlag = 1; //更改标志
	if (p->rFlag == 1)
	{
		next = succ(p); //找到 p 的后继结点
		next->lChild = p;
	}
}
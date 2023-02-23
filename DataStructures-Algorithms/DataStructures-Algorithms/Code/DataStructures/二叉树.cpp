//��

//������
//����
/***********��������㶨��*************/
template <class DataType> class BinaryTreeNode
{
public:
	/**********�����ս��*********/
	BinaryTreeNode()
	{
		data = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	/*************����һ��ָ��������Ľ��*************/
	BinaryTreeNode(DataType newData)
	{
		data = newData;
		lChild = rChild = NULL;
	}
private:
	DataType data; //������
	BinaryTreeNode* lChild; //������ָ��
	BinaryTreeNode* rChild; //������ָ��
};


//��������˳��洢�ṹ
/*******************�����������Ա�ʾ*******************/
template<typename DataType> class SeqBT
{
public:
	SeqBT(int nodes) //�ò�������˳��ṹ�������С
	{
		if (nodes > 0)
		{
			maxNode = nodes; //������������
			data = new DataType[maxNode]; //��������ռ�
		}
	}
	~SeqBT()
	{
		delete[] data;
	}
private:
	int maxNode; //��������Ϊ��ȫ������ʱ�Ľ�����
	DataType* data; //������Ա�������Դ洢�����Ϣ
};


//����������ʽ�洢�ṹ
/***********��������㶨��*************/
template <class DataType> class BinaryTreeNode
{
public:
	/**********�����ս��*********/
	BinaryTreeNode()
	{
		data = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	/*************����һ��ָ��������Ľ��*************/
	BinaryTreeNode(DataType newData)
	{
		data = newData;
		lChild = rChild = NULL;
	}
private:
	DataType data; //������
	BinaryTreeNode* lChild; //������ָ��
	BinaryTreeNode* rChild; //������ָ��
};
/************����������****************************/
template<typename DataType> class BinaryTree
{
public:
	BinaryTree()
	{
		root = new BinaryTreeNode<DataType>(); //��ʼ�������
	}
private:
	BinaryTreeNode<DataType>* root; //�����
};

////��������������
///����������
/****************�������************************/
template<typename DataType> void BinaryTree<DataType>::preOrder(Binare
	TreeNode<DataType>* node)
{
	if (node != NULL)
	{
		std::cout << node->getData() << std::endl; //���ָ�������Ϣ
		preOrder(node->getLeftNode()); //�ݹ��������������� 
		preOrder(node->getRightNode());
	}
}

/*****************�������********************/
template<typename DataType> void BinaryTree<DataType>::inOrder(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL) //�ж���ʼ����Ƿ�Ϊ�գ���Ϊ�յݹ�ֹͣ
	{
		inOrder(node->getLeftNode()); //�ݹ����������
		std::cout << node->getData() << std::endl; //��������Ϣ
		inOrder(node->getRightNode()); //�ݹ����������
	}
}

/***************�������*********************/
template<typename DataType> void BinaryTree<DataType>::postOrder(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL) //�ж�ָ������Ƿ�Ϊ��
	{
		postOrder(node->getLeftNode()); //�ݹ����������
		postOrder(node->getRightNode()); //�ݹ����������
		std::cout << node->getData() << std::endl; //���ָ�����
	}
}

/**********************�������****************/
//���������������������ȱ������Ӹ���㿪ʼ��������������Ϊ�� 1 �㣬�����ӽ��Ϊ�� 2 �㣬���δ��ϵ��£������ұ�������
template<typename DataType> void BinaryTree<DataType>::layOrder(Binary
	TreeNode<DataType>* node)
{
	int max = 50; //���д�С���ڲ�֪�����Ĵ�С֮ǰ�������ô�һ��
	int front, rear; //���ö��׶�β
	BinaryTreeNode<DataType>* current; //����ָ��ǰ����ָ��
	int count = 0; //�����е�Ԫ�ظ��� 
	if (node != NULL) //�жϳ�ʼ����Ƿ�Ϊ��
	{
		DataType[] * queue = new DataType[max]; //Ϊ��������ռ�
		front = rear = 0; //��ʼ������ָ��
		queue[rear] = node; //����ʼ��������
		rear++; //��βָ�����
		count++; //Ԫ�ظ����� 1 
		while (count != 0) //�ж϶���Ԫ���Ƿ���ȫ����
		{
			current = queue[front]; //����Ԫ�س��ӣ�����Ϊ��ǰ���
			std::cout << current->getData() << std::endl; //�������Ԫ�ص�ֵ
			if (current->getLeftNode() != NULL)
				//�жϳ���Ԫ�ص����ӽ���Ƿ�Ϊ�գ�����Ϊ�գ������
			{
				queue[rear] = current->getLeftNode();
				rear = (rear + 1) % max;
				count++;
			}
			if (current->getRightNode() != NULL)
				//�жϳ���Ԫ�ص����ӽ���Ƿ�Ϊ�գ�����Ϊ�գ������
			{
				queue[rear] = current->getRightNode();
				rear = (rear + 1) % max;
				count++;
			}
			front = (front + 1) % max; //���Ӳ������������ö���ָ��
			count--; //������Ԫ�ظ����� 1 
		}
	}
}

//����һ�Ŷ�����
template<class DataType> class BinaryTree;
/***********��������㶨��*************/
template <class DataType> class BinaryTreeNode
{
public:
	friend class BinaryTree<DataType>;
	/**********�����ս��*********/
	BinaryTreeNode()
	{
		data = NULL;
		lChild = NULL;
		rChild = NULL;
	}
	/*************����һ��ָ��������Ľ��*************/
	BinaryTreeNode(DataType newData)
	{
		data = newData;
		lChild = rChild = NULL;
	}
	/***************��ȡ������*****************/
	DataType getData()
	{
		if (data != NULL)
			return data;
		return NULL;

	}
	/*****************��ȡ���ӽ��*************/
	BinaryTreeNode<DataType>* getLeftNode()
	{
		return lChild;
	}
	/*****************��ȡ���ӽ��*************/
	BinaryTreeNode<DataType>* getRightNode()
	{
		return rChild;
	}

private:
	DataType data; //������
	BinaryTreeNode* lChild; //������ָ��
	BinaryTreeNode* rChild; //������ָ��
};
/************����������****************************/
template<typename DataType> class BinaryTree
{
public:
	BinaryTree()
	{
		root = new BinaryTreeNode<DataType>(); //��ʼ�������
	}
	BinaryTree(DataType rootData)
	{
		root = new BinaryTreeNode<DataType>(DataType rootData);
		//���������ݵĸ����
		root->lChild = NULL;
		root->rChild = NULL;
	}
	~BinaryTree()
	{
		delete root;
	}

private:
	BinaryTreeNode<DataType>* root; //�����
};

//��һ�����ĸ����
/******************Ѱ�Ҹ����**********************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::parentNode(BinaryTreeNode<DataType>* node)
{
	if (node == NULL || node == root)
		return NULL;
	int max = 50; //���д�С���ڲ�֪�����Ĵ�С֮ǰ�������ô�һ��
	int front, rear; //���ö��׶�β
	BinaryTreeNode<DataType>* current, * child; //����ָ��ǰ����ָ��
	��ָ���ӽ���ָ��
		int count = 0; //�����е�Ԫ�ظ��� 
	if (node != NULL) //�жϳ�ʼ����Ƿ�Ϊ��
	{
		DataType[] * queue = new DataType[max]; //Ϊ��������ռ�
		front = rear = 0; //��ʼ������ָ��
		queue[rear] = node; //����ʼ��������
		rear++; //��βָ�����
		count++; //Ԫ�ظ����� 1 
		while (count != 0) //�ж϶���Ԫ���Ƿ���ȫ����
		{
			current = queue[front]; //����Ԫ�س��ӣ�����Ϊ��ǰ���

			if (current->getLeftNode() != NULL)
				//�жϳ���Ԫ�ص����ӽ���Ƿ�Ϊ�գ�����Ϊ�գ������
			{
				child = current->getLeftNode();
				if (child == node) //�Ƚϳ��ӽ������ӽ����ָ�����
					return current; //����ȣ��򷵻س��ӽ��
				queue[rear] = child;
				rear = (rear + 1) % max;
				count++;
			}

			if (current->getRightNode() != NULL)
				//�жϳ���Ԫ�ص����ӽ���Ƿ�Ϊ�գ�����Ϊ�գ������
			{
				child = current->getRightNode();
				if (child == node) //�Ƚϳ��ӽ����Һ��ӽ����ָ�����
					return current; //����ȣ��򷵻س��ӽ��
				queue[rear] = child;
				rear = (rear + 1) % max;
				count++;
			}
			front = (front + 1) % max; //���Ӳ������������ö���ָ��
			count--; //������Ԫ�ظ����� 1 
		}
		return NULL;
	}
}

//��ָ�����i���ӽڵ�
/*******************����ָ���������ӽ��****************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::
getLChild(BinaryTreeNode<DataType>* node)
{
	if (node == NULL) //�ж�ָ������Ƿ�Ϊ��
		return NULL;
	return node->lChild; //����ָ����������ָ��
}
/*******************����ָ���������ӽ��****************/
template<typename DataType> BinaryTreeNode<DataType>* BinaryTree<DataType>::
getRChild(BinaryTreeNode<DataType>* node)
{
	if (node == NULL) //�ж�ָ������Ƿ�Ϊ��
		return NULL;
	return node->rChild; //����ָ�������Һ���ָ��
}

//��������ֵܽ������ֵܽ��
/************************���ֵܽ��************************/
template<typename DataType> BinaryTreeNode<DataType>*
BinaryTree<DataType>::getBrotherNode(BinaryTreeNode<DataType>
	* node)
{
	if (node == NULL) //�ж�ָ������Ƿ�Ϊ��
		return NULL;
	BinaryTreeNode<DataType>* parent = BinaryTree<DataType>::parentNode
	(node); //��ȡָ�����ĸ����
	if (parent == NULL)
		return NULL; //�������Ϊ�գ�˵���Ǹ���㣬���ֵܽ�㣬���� NULL 
	if (parent->lChild == node) //�ж�ָ������Ƿ񸸽������ӽ��
		return parent->rChild; //��ָ����������ӣ��򷵻ظ������Һ��ӽ����Ϊ�ֵܽ��
		if (parent->rChild == node) //�ж�ָ������Ƿ񸸽����Һ��ӽ��
			return parent->lChild; //��ָ����������ӣ��򷵻ظ������Һ��ӽ����Ϊ�ֵܽ��
}

//��һ�Ŷ������ĸ߶�
/*************************��������ĸ߶�************************/
/*******************��������Ƶ�ջ�Ĵ�С��һ����Ϊ�������Ľ����*************/
template<typename DataType> int BinaryTree<DataType>::getDepth(int
	numberofNodes)
{
	BinaryTreeNode<DataType>* nodeStack = new BinaryTreeNode<DataType>[numberof
		Nodes]; //���ô洢����������ջ
	int depthStack[numberofNodes]; //�������ջ
	int currentDepth, maxDepth = 0; //currentDepth ��ʾ��ǰ����ȣ�
	maxDepth ��ʾ������
		int top = -1; //ջ���α�ָ���ʼֵ
	BinaryTreeNode<DataType>* node = root; //���õ�ǰ���ʵĽ��ָ�벢��ʼ��Ϊ
	�����
		if (node != NULL) //�жϵ�ǰ���ʵĽ���Ƿ�Ϊ��
		{
			currentDepth = 1; //��ʼ����ǰ���Ϊ 1�������Ϊ�� 1 ��
			/*********ѭ�������������������ʵĽ����ջ*********
			***********����ͣ�����������·��*****************/
			do {
				while (node != NULL)
				{
					nodeStatck[++top] = node; //�����ʵ��Ĳ�Ϊ�յĽ����ջ��ֱ��
					�����ս��ֹͣ
						depthStack[top] = currentDepth; //����Ӧ�������ջ
					node = node->lChild; //�������ʵ�ǰ��������
					currentDepth++; //��ǰ��ȼ� 1 
				}
				node = nodeStack[top]; //һ��·���ߵ���ͷʱ����ջջ��Ԫ��
				������·��
					currentDepth = depthStack[top--];
				if (node->lChild == NULL && node->rChild == NULL)
					//�ж��Ƿ�Ҷ�ӽ��
				{
					if (currentDepth > maxDepth) //�����Ҷ�ӽ�����ȴ��������ȣ�
						����������
						maxDepth = currentDepth;
				}
				node = node->rChild; //��ʼ���ʳ�ջ����������
				currentDepth++;
			} while (!(node == NULL && top == -1)); //���ʽ��Ϊ����ջ��ʱѭ����������ʱ�������Ⱦ������ĸ߶�
		}
	return maxDepth;
}

//��һ�ö�����������һ�ö������Ľ��i����Ϊi�����ң�����
/********************�����Ӷ�����***********/
template<typename DataType> void BinaryTree<DataType>::insertSubBT(BinaryTree<DataType>* bt, BinaryTreeNode<DataType>* node)
{
	if (node == NULL) //�жϴ�����������Ͳ�����Ƿ�Ϊ��
		return NULL;
	if (bt->root == NULL)
		return NULL;
	if (node->lChild == NULL) //����������������Ϊ�գ�����뵽������
		node->lChild = bt->root;
	else if (node->rChild == NULL) //���������Ϊ�գ������Ϊ������ 
		node->rChild = bt->root;
	else
	{ //���򣬲��뵽���������ҽ�ԭ����������ɾ��
		BinaryTreeNode<DataType>* p = node->lChild;
		node->lChild = bt->root;
		delete p;
	}
}

//ɾ�����i�����ң�����
/****************************ɾ�����н��**********************/
template<typename DataType> void BinaryTree<DataType>::deleteNodes(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL)
	{
		deleteNodes(node->lChild); //�ݹ����Ȼ��ɾ�������Ľ��
		deleteNodes(node->rChild);
		delete node;
	}
}
/*************************ɾ������****************************/
template<typename DataType> bool BinaryTree<DataType>::deleteSubTree(Binary
	TreeNode<DataType>* node, int i)
	/*******i Ϊѡ������1 ��ʾɾ����������2 ��ʾɾ����������3 ��ʾ����������ɾ��**********/
{
	if (node == NULL)
		return false;
	BinaryTreeNode<DataType>* p; //������ʱ����
	switch (i) //���ݲ��� i �ж���ɾ������������ɾ��������
	{
	case 1:
		p = node->lChild;
		deleteNodes(p); //����ɾ�����н�㺯��
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

//����һ�Ŷ�����
//����һ
/************************���ٶ�����*********************/
template<typename DataType> void BinaryTree<DataType>::destroyBT(Binary
	TreeNode<DataType>* node)
{
	if (node != NULL) //�жϽ���Ƿ�Ϊ��
	{
		destroyBT(node->lChild); //����������н�㣬��ɾ����Ӧ���
		destroyBT(node->rChild);
		delete node;
	}
	root = NULL; //���������Ϊ NULL���γɿ���
}
//�����������������ٶ��������ǿ����� C++����Ϊ���������Ĺ��ܣ��������ǳ�������������������������Ϊ��
~BinaryTree()
{
	BinaryTreeNode<DataType>* node = root;
	if (node != NULL) //�жϽ���Ƿ�Ϊ��
	{
		destroyBT(node->lChild); //����������н�㣬��ɾ����Ӧ���
		destroyBT(node->rChild);
		delete node;
	}
	delete root; //ɾ�������
}

//����i�����
/*************************���� i �����**************************/
template<typename DataType> int BinaryTree<DataType>::getDepthofNode
(DataType i)
{
	int stackSize = 50;
	BinaryTreeNode<DataType>* nodeStack = new BinaryTreeNode<DataType>
		[stackSize]; //���ô洢����������ջ
	int flagStack[stackSize]; //�洢ÿ������״̬
	int flag = 0; //flag ��ʾÿ�����ķ���״̬��0 ��ʾ����һ�Σ�1 ��ʾ��������
	int top = -1; //ջ���α�ָ���ʼֵ
	BinaryTreeNode<DataType>* node = root;//���õ�ǰ���ʵĽ��ָ�벢��ʼ��Ϊ��
	���

		/******ѭ������������������ʵĽ����ջ************/
		/****�����Ƿ���ʵĽ����Ǵ�����***************/
		do {
			while (node != NULL)
			{
				nodeStatck[++top] = node; //�����ʵ��Ĳ�Ϊ�յĽ����ջ��ֱ��
				�����ս��ֹͣ
					flagStack[top] = 0; //����Ӧ������״̬��ջ����һ�η���״̬Ϊ 0 
				node = node->lChild; //�������ʵ�ǰ�������� 
			}
			node = nodeStack[top]; //һ��·���ߵ���ͷʱ����ջջ��Ԫ�س�����·��
			flag = flagStack[top--]; //��ȡ���ķ���״̬
			if (flag == 0) //�жϸý���ǵڼ��η���
			{
				nodeStatck[++top] = node; //���� 1 �η��ʵĽ���ٴ���ջ
				flagStack[top] = 1; //�ı���Ӧ�ķ���״̬
				node = node->rChild;
			}
			else
			{
				if (node->data == i) //������� 2 �η������ж����Ƿ�Ϊ������ҪѰ�ҵĽ��
					return top + 2; //����ҵ��ý�㣬�������Ϊջ��Ԫ�ظ��� + 1����ջ��ָ�� + 2
					node = NULL; //������Ǹý�㣬�������ջ
			}
		} while (!(node == NULL && top == -1)); //���ʽ��Ϊ����ջ��ʱѭ������

}

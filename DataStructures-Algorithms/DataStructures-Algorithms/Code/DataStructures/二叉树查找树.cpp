//������������
//����
/*********************�����������㶨��************************/
template<typename DataType> class SBTNode
{
public:
	/****************���캯��*******************/
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
	/*********************��������*******************/
	~SBTNode()
	{
		lChild = rChild = parent = NULL;
		delete this;
	}
private:
	SBTNode<DataType>* lChild, * rChild, * parent; //�������ӡ��Һ��Ӻ͸����ָ��
	DataType data; //������
};
/*****************************�������������******************/
template<typename DataType> class SBT
{
public:
	/******************���캯��********************/
	SBT()
	{
		root = new SBT<DataType>();
	}
	SBT(DataType data)
	{
		root = new SBT<DataType>(data);
	}
private:
	SBTNode<DataType>* root; //�����ָ��
};

/////��������
//�������������
/****************�������***********************/
template<typename DataType> void SBT<DataType>::inSort(SBTNode<DataType> *node)
{
	if (node != NULL)
	{
		inSort(node->lChild); //�ݹ�������ӽ��
		std::cout << node->data << std::endl; //����������
		inSort(node->rChild); //�ݹ�����Һ��ӽ��
	}
}
//����������Ĳ������
/******************�������**********************/
template<typename DataType> void SBT<DataType>::insert(SBTNode<DataType> *node)
{
	SBTNode<DataType>* cur, * temp = NULL; //���������м�ָ��
	cur = root;
	while (cur != NULL) //����������
	{
		temp = cur;
		if (node->data < cur->data) //�Ƚϴ��������뵱ǰ����ֵ
		{
			cur = cur->lChild; //���С�ڣ������������
		}
		else
		{
			cur = cur->rChild; //�������������
		}
	}
	node->parent = temp; //�����һ����Ч�������Ϊ��������ĸ����
	if (temp == NULL)
	{
		root = node; //��������Ϊ�գ����������Ϊ�����
		count++;
	}
	else
	{
		if (node->data < temp->data) //�Ƚϴ�С
		{
			temp->lChild = node; //���С�ڣ������Ϊ����
			count++��
		}
		else
		{
			temp->rChild = node; //����Ϊ�Һ���
			count++;
		}
	}
}

//�����������ɾ��������
/******************ɾ�����***********************/
template<typename DataType> void SBT<DataType>::deleteNode(SBTNode
	<DataType>* node)
{
	SBTNode<DataType>* p; //������ɾ�����ĸ����ָ��
	p = node->parent;
	if (node->lChild == NULL && node->rChild == NULL)
		//����ý����Ҷ�ӽ����ֱ��ɾ��
	{
		delete node;
		count--; //��������������Ŀ�� 1 
	}
	else if (node->lChild == NULL && node->rChild != NULL)
		//������ֻ��������
	{
		if (p == NULL) //�жϽ���Ƿ�Ϊ�����
		{
			root = node->rChild;
			count--;
		}
		else
		{
			node->rChild->parent = p; //�粻�Ǹ���㣬���Һ��ӽ��ĸ���
			��ָ��ָ�� node �ĸ����
				if (p->lChild == node) //�жϴ�ɾ������Ǹ��������ӻ����Һ���
					p->lChild = node->rChild;
				else
					p->rChild = node->rChild;
			delete node;
			count--;
		}
	}
	else if (node->lChild != NULL && node->rChild == NULL) //������û��������
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
		//����������Һ��Ӿ����ڣ��� node ������������С�Ľ���滻 node 
		SBTNode<DataType>* left, * curP; //left ָ��ָ�� node ���Һ���
		left = node->rChild;
		while (left != NULL) //���� node �Һ��ӽ��������
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
			curP->parent->lChild = NULL; //�滻���
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

//����������Ĳ�ѯ
/********************��ѯ���*******************/
template<typename DataType> SBTNode<DataType>* SBT<DataType>::search(DataType k)
{
	SBTNode<DataType>* node = root; //�����ƶ�ָ��ָ������
	while (node != NULL)
	{
		if (k < node->data) //��� K С�ڽ��ֵ�����������������
			node = node->lChild;
		else if (k > node->data) //��� K ���ڽ��ֵ�����������������
			node = node->rChild;
		else
			break; //�����ȣ����˳�ѭ��
	}
	return node; //���ؽ��ָ��
}
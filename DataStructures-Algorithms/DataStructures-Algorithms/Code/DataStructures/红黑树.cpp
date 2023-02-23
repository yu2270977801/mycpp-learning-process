//�����
//����
/*********************�������㶨��************************/
template<typename DataType> class RBTNode
{
	friend class RBT<DataType>;
public:
	/****************���캯��*******************/
	RBTNode() //���� nil ���
	{
		lChild = rChild = parent = NULL;
		color = 0; //��ɫΪ��ɫ
		data = NULL;
	}
	RBTNode(DataType d, int color) //�����ڽ��
	{
		data = d;
		lChild = rChild = parent = NULL;
		this->color = color;
	}
	/*********************��������*******************/
	~RBTNode()
	{
		lChild = rChild = parent = NULL;
		delete this;
	}
private:
	SBTNode<DataType>* lChild, * rChild, * parent; //�������ӡ��Һ��Ӻ͸����ָ��
	DataType data; //������
	int color; //��ɫ��0 ��ʾ�ڣ�1 ��ʾ��
};
/*****************************���������******************/
template<typename DataType> class RBT
{
public:
	/******************���캯��********************/
	RBT()
	{
		root = NULL;
		nil = new RBTNode<DataType>();
		count = 0;
	}
	RBT(DataType data)
	{
		root = new RBTNode<DataType>(data��0); //��������㣬�����Ϊ��ɫ
		nil = new RBTNode<DataType>();
		count = 1;
	}
	/*********************����ת**********************/
	void leftRotated(RBTNode<DataType>* node);
private:
	RBTNode<DataType>* root; //�����ָ��
	RBTNode<DataType>* nil; //�ڱ�Ҷ�ӽ��
	int count; //�����Ŀ
};

////��������
//��ת����
/*********************����ת**********************/
template<typename DataType> void RBT<DataType>::leftRotated(RBTNode<DataType>* node)
{
	if (node->rChild != nil) //�ж� node �����Һ����Ƿ�Ϊ nil 
	{
		RBTNode<DataType>* y = node->rChild;//���ý�� y Ϊ node ���Һ��ӽ��
		node->rChild = y->lChild; //����֮�� y �������ӳ�Ϊ node ���Һ���
		if (y->lChild != nil)
			y->lChild->parent = node;//��� y �����Ӳ�Ϊ�գ����丸�����Ϊ node 
		y->parent = node->parent; //�� y �ĸ������Ϊ node �ĸ����
		if (node->parent == nil)
			root = y;
		else if (node->parent->lChild == node) //�ж� node �Ǹ��������ӻ����Һ��ӣ�����Ϊ y
		{
		node->parent->lChild = y;
		}
		else
		{
			node->parent->rChild = y;
		}
		y->lChild = node; //y �������Ӹ���Ϊ node 
		node->parent = y; //node �ĸ�������Ϊ y 
	}
}

//������
/**********************���������***************/
template<typename DataType> void RBT<DataType>::insert(RBTNode<DataType>
	* node)
{
	SBTNode<DataType>* cur, * temp = nil; //���������м�ָ��
	cur = root;
	while (cur != nil) //����������
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
	if (temp == nil)
	{
		root = node; //��������Ϊ�գ���������Ϊ�����
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
	node->lChild = nil; //���½������Һ���ָ�� nil ���
	node->rChild = nil;
	node->color = 1; //��ɫΪ��ɫ
	insertKeppRB(node); //���� keepRB()�����ָ�������� 
}


//
	/*********************���ֺ������***************/
	template<typename DataType> void RBT<DataType>::insertKeepRB(RBTNode
		<DataType>* node)
	{
		RBTNode<DataType>* y;
		while (node->parent->color == 1)
		{
			/**********node ���ĸ���������ӵ����****************/
			if (node->parent->parent->lChild == node->parent)
			{
				y = node->parent->parent->rChild; //���� y Ϊ node ��������
				if (y->color == 1) //�����a���Ľ��
				{
					node->parent->color = 0; //���ĸ������������ɫΪ��ɫ
					y->color = 0;
					node->parent->parent->color = 1; //�����������ɫΪ��ɫ
					node = node->parent->parent; //node ָ������ݹ����ϸ���
				}
				else if (node->parent->lChild == node) //�����b��
				{
					node->parent->color = 0; //���ĸ����Ϊ��
					node->parent->parent->color = 1; //��������Ϊ��
					rightRotated(node->parent->parent);//��������
				}
				else if (node->parent->rChild == node) //�����c��
				{
					node = node->parent;
					leftRotated(node); //����������㣬��������b��
					node->parent->color = 0;
					node->parent->parent->color = 1; //���������󸸽������
					����ɫ�ֱ�Ϊ�ںͺ�
						rightRotated(node->parent->parent);//��������
				}
			}
			/**********node ���ĸ�������Һ��ӵ����****************/
			/*****�������㷨�븸���������ʱ�Գƣ����õ����ҵĵط�����***/
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
		root->color = 0; //�����������Ϊ��ɫ�����ܵ�������·���ڸ߶ȶ��� 1 
	}


//ɾ��������
/***********************ɾ��������**************/
	template<typename DataType> void RBT<DataType>::deleteNode(RBTNode<Data
		Type>* node)
	{
		RBTNode<DataType>* y, * x; //���������α���ָ��
		if (node->rChild == nil || node->lChild == nil)
			//��� node ֻ��һ�����ӻ�û�к��ӽ��
		{
			y = node; //�� y ָ�� node ����
		}
		else
		{
			y = succNode(node); //��� node ���������ӽ�㣬�� y ָ�� node �ĺ�̽��
		}
		if (y->lChild != nil) //y ���Ӳ�Ϊ���� x Ϊ������
		{
			x = y->lChild;
		}
		else
		{
			x = y->rChild; //����Ϊ���Һ���
		}
		x->parent = y->parent; //���� x �ĸ����Ϊ y �ĸ����
		if (y->parent == nil)
		{
			root = x;
		}
		else if (y == y->parent - lChild) //ȷ�� x �� y �ĸ�����λ��
		{
			y->parent->lChild = x;
		}
		else
		{
			y->parent->rChild = x;
		}
		if (y != node) //��� y ����ָ�� node �ģ��� y �����ݺ���ɫ���Ƶ� node �Ľ����
		{
			node->data = y->data;
			node->color = y->color;
		}
		if (y->color == 0)
			deleteKeepRB(x); //��� y ����ɫΪ��ɫ����к�����ʵ���
		delete y; //ɾ����� y 
		count--;
	}
	/******************Ѱ�Һ�̽��*****************/
	template<typename DataType> void RBT<DataType>::succNode(RBTNode<Data
		Type>* node)
	{
		if (node->rChild != NULL) //��� node ����������Ϊ�գ��򷵻�����������С��ֵ
		{
			RBTNode<DataType>* left = node->rChild;
			while (left->lChild != NULL)
			{
				left = left->lChild;
			}
			return left;
		}
		RBTNode<DataType>* p = node->parent;
		while (p != nil && node == p->rChild) //��� node ��������Ϊ�գ����صĽ�� p 
		{ //���� p �� node ��������Ƚ�㣬�� p ������Ҳ�� node �����Ƚ��
			node = p;
			p = p->parent;
		}
		return p;
	}

//
	/*************************ɾ�����ֺ������*******************/
	template<typename DataType> void RBT<DataType>::deleteKeepRB(RBTNode
		<DataType>* x)
	{
		RBTNode<DataType>* w; //�����ֵܽ��ָ��
		while (x != root && x->color == 0) //�� x �ݹ�Ϊ root ʱֹͣѭ��
		{
			if (x == x->parent->lChild) //x Ϊ����ʱ�����
			{
				w = x->parent->rChild;
				if (w->color == 1) //��� 1 
				{
					w->color = 0;
					x->parent->color = 1;
					leftRotated(x->parent); //�� x ���������
					w = x->parent->rChild; //�����µ��ֵܽ��
				}
				if (w->lChild->color == 0 && w->rChild->color == 0) //��� 2 
				{
					w->color = 1;
					x = x->parent;
				}
				else if (w->rChild->color == 0) //��� 3 
				{
					w->lChild->color = 0;
					w->color = 1;
					rightRotated(w); //���ֵܽ���������
					w = x->parent->rChild;
				}
				else
				{
					w->color = x->parent->color; //��� 4 
					x->parent->color = 0;
					w->rChild->color = 0;
					leftRotated(x->parent); //���������
					x = root; //���ѭ��ֹͣ���� x ��Ϊ�����
				}
			}
			else
			{
				/******x Ϊ�Һ���ʱ�������������ʱ�Գƣ�ֻ��������ұ��******/
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
		x->color = 0; //x ȷ��Ϊ��ɫ
	}

/*****************ѭ�������㶨��********************/
template<typename DataType> class CircularListNode
{
public:
	friend class CircularList<DataType>;
	CircularListNode()
	{
		m_next = NULL;
	}
	CircularListNode(DataType data, CircularListNode *nextOne = NULL)
	{
		m_data = data;
		m_next = nextOne;
	}
	~CircularListNode()
	{
		m_next = NULL;
	}
private:
	CircularListNode *m_next; //ָ����һ������ָ��
	DataType m_data; //������
};
/**********************ѭ��������**********************/
template<typename DataType> class CircularList
{
public:
	CircularList()
	{
		head = new CircularListNode<DataType>();
		head->m_next = head;
	}
	~CircularList()
	{
		clearUp();
		delete head;
	}
	//���ѭ������
	void cleanUp();
	//��ȡѭ������ĳ���
	int getLength();
	//��ѯ���� value ֵ�ĵ� i ��Ԫ�أ���������ָ��
	CircularListNode<DataType>* findNode(int i, DataType value);
	//������β������Ԫ��
	bool insertNode(DataType data);
	//ɾ������ value ֵ������Ԫ��
	bool deleteNode(DataType value);
	//��ȡָ��Ԫ�ص�ֵ
	DataType getValue(CircularListNode<DataType> *node);
private:
	CircularListNode<DataType> *head;
};
/*******************�������*********************/
template<typename DataType> void CircularList<DataType>::cleanUp()
{
	CircularListNode* p; //����ָʾɾ������ָ��
	while (head->m_next != head)
	{
		p = head->m_next; //��ʼ��ָʾָ��
		head->m_next = p->m_next; //��ͷָ��ָ����һ��������һ�����
		delete p; //���տռ�
	}
}
/**********************��ȡ������********************/
template<typename DataType> int CircularList<DataType>::getLength()
{
	int length = 0;
	CircularListNode<DataType>* p = head; //�����α�ָ��
	while (p->m_next != head) //����ָ�룬ֱ��ָ��ͷָ��ʱ����
	{
		p = p->m_next;
		length++;
	}
	return length; //����������
}
/*********************��ѯ���� value ֵ�ĵ� i ��ָ��***************/
template<typename DataType> CircularListNode<DataType>* CircularList
<DataType>::findNode(int i, DataType value)
{
	int count = 0;
	CircularListNode<DataType>* p = head; //�α�ָ��
	while (count != i)
	{
		//��������Ѱ��ֵ�� value ��ȵĽ��
		p = p->m_next;
		if (p->m_data == value)
		{
			count++; //��¼���ǵڼ������������Ľ��
		}
		if (p == head) //������û�����������Ľ��
			return NULL;
	}
	return p;
}
/*************************������β��������***********************/
template<typename DataType> bool CircularList<DataType>::insertNode(DataType data)
{
	CircularListNode<DataType>* p = head; //�α�ָ��
	//�����½��
	CircularListNode<DataType>* node = new CircularListNode<DataType>(data, NULL);
	if (node == NULL) //�½��ռ����ʧ��
	{
		return false;
	}
	//Ѱ��β���
	while (p->m_next != head)
	{
		p = p->m_next;
	}
	node->m_next = p->m_next; //�����½��
	p->m_next = node;
	return true;
}
/*************************ɾ������ value ֵ������Ԫ��***********************/
template<typename DataType> bool CircularList<DataType>::deleteNode(DataType value)
{
	int count = 0; //ɾ���Ľ����
	CircularListNode<DataType>* p = head->m_next, *l = head; //�α�ָ��
	//��������
	while (p != head)
	{
		if (p->m_data == value) //������ֵ�� value ���
		{ //ɾ���ý�㲢����
			l->m_next = p->m_next;
			delete p;
			count++;
			p = l->m_next;
		}
		else
		{
			l = p; //��㲻����������ֱ���ƶ�ָ��
			p = p->m_next;
		}
	}
	if (count == 0) //���ɾ�������Ϊ 0��˵��û�з��������Ľ��
		return false;
	else
		return true;
}
/******************************��ȡָ��Ԫ�ص�ֵ*******************/
template<typename DataType> DataType CircularList<DataType>::getValue
(CircularListNode<DataType>* node)
{
	return node->m_data;
}
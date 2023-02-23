//////////////����
//����
template <typename DataType> class LinkList
{
public:
	//�޲������캯��
	LinkList()
	{
		head = new ListNode();
	}
	//�в������캯��
	LinkList(ListNode* node)
	{
		head = node;
	}
	//��������
	~LinkList()
	{
		delete head;
	}
	bool insertNode(ListNode* q, DataType newData); //������

	bool removeNode(ListNode* q); //ɾ�����
	ListNode* findNode(DataType value); //����ָ��ֵ�Ľ�㲢���ص�ַ
	bool cleanLink(); //�������

	DataType getNodeData(ListNode* p); //��ȡ�������
private:
	ListNode* head; //ͷ���
};
/*************����������****************/
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
	//��ȡ����ڵ�����
	DataType getData()
	{
		return data;
	}
	//��ȡָ����
	ListNode* getNext()
	{
		return next;
	}
private:
	friend typename LinkList<DataType>; //�� LinkList ��Ϊ��Ԫ�࣬������� node �ĳ�Ա���ݺͷ����ķ���
	DataType* next; //ָ����һ������ָ��
	DataType data; //����е�����
};

//����Ļ�������
//������
//*************������ĵ� i ����������½��***************/ 
template<typename DataType> bool LinkList<DataType>::insertNode(int i, DataType newData)
{
	ListNode<DataType> *p = head; //�����α�ָ�룬��ʼ��Ϊͷ����ַ
	int j;
	for (j = 1; j <= i - 1; j++) //���ҵ� i ����㣬ָ����Ҫ�ƶ� i-1 ��
	{
		p = p->next;
		if (p == NULL) //���ָ��Ϊ�գ��򲻴��ڸý�㣬���ѵ���β
		{
			break;
		}

	}
	if (p == NULL && j < (i - 1)) //ָ��Ϊ����û�е��� i ��λ�ã�˵�������ڵ� i �����
	{
		std::cout << "����λ����Ч��" << endl;
		return false;
	}
	ListNode<DataType>* node = new ListNode<DataType>(newData); //�����½�� node 

	node->next = p->next; //�� node �� next ָ�븳ֵΪ p �ĺ�̽���ַ
	p->next = node; //p �ĺ��ָ��ָ�� node 
	return true;
}


/***********************�ڵ������β����½��*****************************/
template<typename DataType> bool LinkList<DataType>::insertNode(DataType newData)
{
	ListNode<DataType>* p = head; //�����α�ָ��
	ListNode<DataType>* node = new ListNode<DataType>(newData); //�����½��
	if (node == NULL) //����½���ڴ����ʧ�ܣ����� false 
	{
		return false;
	}
	while (p->next != NULL) //�����������ҵ�β���
	{
		p = p->next;
	}
	p->next = node; //��β��� next ָ��ָ���½��
	return true;
}

//ɾ�����
/*******************ɾ��ָ�����*******************/
template<typename DataType> bool LinkList<DataType>::removeNode(ListNode <DataType>* q)
{
	if (q == NULL) //�жϴ�ɾ������Ƿ����
	{
		std::cout << "��ɾ����㲻���ڣ�" << std::endl;
		return false;
	}
	ListNode<DataType>* tempPointer = head; //�����α�ָ�룬��ʼ��Ϊͷ���
	while (tempPointer->next != q) //�����������ҵ� q ��ָ�����ǰ�����
	{
		tempPointer = tempPointer->next;
	}
	tempPointer->next = q->next; //�� q ���ĺ�̽���ַ��ֵ����ǰ������ next ָ��
	
	delete q; //���ս�� q �Ŀռ�
	return true;
}

//�����ض�ֵ�Ľ��
/*********************����ָ��ֵ�Ľ��***************/
template<typename DataType> ListNode<DataType>* LinkList<DataType>::
findNode(DataType value)
{
	ListNode<DataType>* currentPointer = head; //�����α�ָ��
	//�ж��α�ָ����ָ����ֵ�Ƿ��� value ���
	while (currentPointer != NULL && currentPointer->data != value)
	{
		currentPointer = currentPointer->next;
	}
	if (currentPointer == NULL) //�ж����ҽ���Ƿ����
	{
		std::cout << "û���ҵ��ý�㣡�����쳣�˳���" << endl;
		exit(1);
	}
	else
	{
		return currentPointer; //�������ҵ��Ľ���ָ��
	}
}

//�������
/********************�������***********************/
template<typename DataType> void LinkList<DataType>::cleanLink()
{
	ListNode<DataType>* current = head; //�����α�ָ��
	while (head->next != NULL) //�ж� head �ĺ�̽���Ƿ�Ϊ NULL 
	{
		current = head->next; //�� current ָ�� head �ĺ�̽��
		head->next = current->next;//�� current �ĺ�̵�ַ��ֵ�� head �� next ��
		delete current; //���� current �����ռ�Ŀռ�
	}
}
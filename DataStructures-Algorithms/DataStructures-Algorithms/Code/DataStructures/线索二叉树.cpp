//����������
//��������
#include <iostream> 
template<typename DataType> class ThreadBT;
template<typename DataType> class ThreadBTNode
{
public:
	friend class ThreadBT<DataType>;
	ThreadBTNode(DataType newData) //�����ݹ��캯��
	{
		lFlag = rFlag = 0;
		this->data = newData;
		lChild = rChild = NULL;
	}
	ThreadBTNode() //�ս�㹹�캯��
	{
		lFlag = rFlag = 0;
		lChild = rChild = NULL;
	}
private:
	ThreadBTNode<DataType>* lChild, rChild; //����ָ����
	int lFlag, rFlag; //��־��
	DataType data; //������
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
	ThreadBTNode<DataType>* root; //�����
};

//Ѱ�ҽ�� node ��ǰ�����
/***********************Ѱ�ҽ�� node ��ǰ�����*******************/
template<typename DataType> ThreadBTNode<DataType>* ThreadBT<DataType>::prior
(ThreadBTNode<DataType>* node)
{
	ThreadBTNode<DataType>* s; //���÷��ʽ��ָ��
	s = node->lChild;
	if (node->lFlag == 1) //�ж� s �Ƿ������������������ֱ�ӷ���
	{
		while (s->rFlag == 1) //ѭ��Ѱ�ҽ������ӽ�㣬�ҵ� node �������е����ҽ��
		{
			s = s->rChild;
		}
	}
	return s; //���� node ��ǰ��
}

//Ѱ�ҽ�� node �ĺ�̽��
/************************Ѱ�ҽ��ĺ�̽��***********************/
template<typename DataType> ThreadBTNode<DataType>* ThreadBT<DataType>::succ
(ThreadBTNode<DataType>* node)
{
	ThreadBTNode<DataType>* s; //���÷��ʽ��ָ��
	s = node->rChild;
	if (node->rFlag == 1) //�ж� s �Ƿ������������������ֱ�ӷ���
	{
		while (s->lFlag == 1) //ѭ��Ѱ�ҽ������ӽ�㣬�ҵ� node �������е�������
		{
			s = s->lChild;
		}
	}
	return s; //���� node ��ǰ��
}

//������������������������
/************************�������������***********************/
template<typename DataType> void ThreadBT<DataType>::inOrder()
{
	if (root != NULL)
	{
		ThreadBTNode<DataType>* s;
		s = root;
		while (prior(s) != NULL) //�ҵ���ʼ���
		{
			s = prior(s);
		}
		while (succ(s) != NULL) //����ʼ��㿪ʼ������̽��
		{
			cout << s->data << endl;
			s = succ(s);
		}
	}
}

//�����������ĸ���
/************************�����������ĸ���***********************/
template<typename DataType> void ThreadBT<DataType>::update(ThreadBTNode
	<DataType>* s, ThreadBTNode<DataType>* p)
{
	ThreadBTNode<DataType>* next;
	next = root;
	p->rChild = s->rChild;
	p->rFlag = s->rFlag;
	/********��� s ������Ϊ�գ��� s ��ֱ�Ӻ�̾ͳ�Ϊ p ��ֱ�Ӻ��***
	*********��� s ��������Ϊ�գ��� s ��������Ϊ p ��������******/
	p->lChild = s; //s ��Ϊ pde ֱ��ǰ��
	p->lFlag = 0; //����������־
	s->rChild = p; //p ��Ϊ s ���Һ���
	s->rFlag = 1; //���ı�־
	if (p->rFlag == 1)
	{
		next = succ(p); //�ҵ� p �ĺ�̽��
		next->lChild = p;
	}
}
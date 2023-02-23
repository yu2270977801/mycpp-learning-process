#include <iostream> 
template <typename DataType> class DoubleList;
/***************˫�������㶨��****************/
template <typename DataType> class DoubleListNode
{
private:
	friend class DoubleList<DataType>; //����������Ϊ��Ԫ��
	DoubleListNode() :m_pprior(NULL), m_pnext(NULL) {}
	//�޲������캯������ָ���ʼ��Ϊ NULL 
	//���������캯����ʼ���������ָ����
	DoubleListNode(const DataType item, DoubleListNode<DataType>* prior = NULL, DoubleListNode<DataType>* next = NULL):m_data(item), m_pprior(prior), m_pnext(next) {}
	//��������
	~DoubleListNode() {
		m_pprior = NULL;
		m_pnext = NULL;
	}
	DataType m_data; //������
	DoubleListNode* m_pprior; //ָ��ǰ������ָ����
	DoubleListNode* m_pnext; //ָ���̽���ָ����
public:
	DataType getData(); //��ȡ����ڵ�����ֵ
};
//��ȡ����е�����
template<typename DataType> DataType DoubleListNode<DataType>::getData() {
	return this->m_data;
}
/***********************˫��������**********************/
template<typename DataType> class DoubleList {
public:
	DoubleList()
	{
		head = new DoubleListNode<DataType>();
	}
	~DoubleList()
	{
		cleanDoubleLink();
		delete head;
	}
public:
	void cleanDoubleLink(); //���˫������
	int getLength(); //��ȡ������
	DoubleListNode<DataType> *findNode(int i = 0); //Ѱ�ҵ� i �����
	DoubleListNode<DataType> *findData(DataType item);
	//Ѱ�Ҿ��и���ֵ���ݵĽ��
	bool insertNode(DataType item, int i = 0); //�ڵ� i ����������½��
	bool removeNode(int i = 0); //ɾ���� i �����
	DataType getData(int i = 0); //��ȡ�� i ����������

private:
	DoubleListNode<DataType> *head; //ͷָ��
};
/*********************�������*****************/
template<typename DataType> void DoubleList<DataType>::cleanDoubleLink() {
	DoubleListNode<DataType>* pmove = head->m_pnext, * pdel;
	while (pmove != NULL) { //һ��ɾ��ͷָ�����Ľ��
		pdel = pmove;
		pmove = pdel->m_pnext;
		delete pdel;
	}
	head->m_pnext = NULL;

}
/*******************��ȡ������********************/
template<typename DataType> int DoubleList<DataType>::getLength() {
	int count = 0;
	DoubleListNode<DataType>* pmove = head->m_pnext;
	//����������������
	while (pmove != NULL)
	{
		pmove = pmove->m_pnext;
		count++;
	}
	return count;
}
/***************************��ȡ�� i �����***********************/
template<typename DataType> DoubleListNode<DataType>* DoubleList<DataType>::findNode(int n = 1) {
	if (n < 1) { //�ж�λ���Ƿ���Ч
		cout << "����Чλ��" << endl;
		return NULL;
	}
	DoubleListNode<DataType>* pmove = head->m_pnext;
	for (int i = 1; i < n; i++) { //����ָ��λ�õĽ��
		pmove = pmove->m_pnext;
		if (pmove == NULL) { //�жϽ���Ƿ����
			cout << "������ָ�����" << endl;
			return NULL;
		}
	}
	return pmove;
}
/**********************�ڵ� i �����֮������½��****************/
template<typename DataType> bool DoubleList<DataType>::insertNode(DataType item, int n) {
	int i;
	if (n < 1) { //�ж��������λ���Ƿ���Ч
		cout << "����λ����Ч" << endl;
		return 0;
	}
	//�����½�㣬�����α�ָ��
	DoubleListNode<DataType>* newnode = new DoubleListNode<DataType>(item),
	*pmove = head;

	if (newnode == NULL) {
		cout << "�ڴ����ʧ�ܣ��½���޷�������" << endl;
		exit(1);
	}
	for (i = 1; i < n; i++) { //�ҵ������λ��
		pmove = pmove->m_pnext;
		if (pmove == NULL && i < n - 1) {
			cout << "���������ȣ�����λ����Ч��" << endl;
			return 0;
		}
	}
	//�����½��
	newnode->m_pnext = pmove->m_pnext;
	if (pmove->m_pnext != NULL) //�ж��Ƿ�������β����ӽ��
	{
		pmove->m_pnext->m_pprior = newnode;
	}
	newnode->m_pprior = pmove;
	pmove->m_pnext = newnode;

	return 1;
}
/*********************ɾ���� i �����**********************/
template<typename DataType> bool DoubleList<DataType>::removeNode(int n = 1) {
	if(n<1 || n>getLength()) { //�ж�λ���Ƿ���Ч
		cout << "λ�ò��Ϸ�" << endl;
		return false;
	}
	DoubleListNode<DataType>* pmove = head->m_pnext, *pdel;
	for (int i = 1; i < n; i++) { //����ɾ������λ��
		pmove = pmove->m_pnext;
		if (pmove == NULL) {
			cout << "����������Χ" << endl;
			return false;
		}
	}
	//ɾ�����
	pdel = pmove;
	pmove->m_pprior->m_pnext = pdel->m_pnext;
	pmove->m_pnext->m_pprior = pdel->m_pprior;
	delete pdel;
	return true;
}
/************************��ȡ�� n ��Ԫ�ص�����*******************/
template<typename DataType> DataType DoubleList<DataType>::getData(int n = 1) {
	if (n<1 || n>getLength()) { //��֤��ѡ��λ���Ƿ�Ϸ�
		cout << "ָ��λ����Ч" << endl;
		exit(1);
	}
	DoubleListNode<DataType> *pmove = head->m_pnext; //�����α�ָ��
	for (int i = 1; i < n; i++) {
		pmove = pmove->m_pnext;
		if (pmove == NULL) {
			cout << "ָ����㲻���ڣ�" << endl;
			exit(1);
		}
	}
	if (pmove == NULL)
	{
		cout << "��㲻���ڣ�" << endl;
		return NULL;
	}
	return pmove->m_data; //�������ҵ���Ԫ�ص�����
}
/******************************��ȡ����ָ��ֵ���ݵĽ��************************/
template<typename DataType> DoubleListNode<DataType>* DoubleList<DataType>::findData(DataType item) {
	DoubleListNode<DataType> *pmove = head->m_pnext; //�����α�ָ��
	if (pmove == NULL) //�жϿձ�
	{
		cout << "�����ǿձ�" << endl;
		exit(1);
	}
	while (pmove->getData() != item) //ѭ�����ҷ��������Ľ��
	{
		pmove = pmove->m_pnext;
		if (pmove == NULL)
		{
			cout << "û�������ҵĽ��" << endl;
			exit(1);
		}
	}
	return pmove;
}

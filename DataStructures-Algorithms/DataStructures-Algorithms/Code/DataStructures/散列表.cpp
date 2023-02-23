////ɢ�б�
//����
/********************ɢ�б��壬���ÿ��Ŷ�ַ�������ͻ****************/
template<typename DataType> class HashTable
{
public:
	HashTable(int size)
	{
		maxSize = size; //��ʼ�����洢�ռ�
		count = 0;
		elements = new DataType[size]; //�������ݿռ�
		if (elements == NULL) //�жϴ洢�ռ��Ƿ����ɹ�
			exit(1);
		for (int i = 0; i < size; i++) //��ʼ��ÿ���洢�ռ��ֵ
			elements[i] = NULL;
	}
	~HashTable()
	{
		delete[] elements;
	}
	//ɢ�к�����������ȡ�࣬p Ϊ���ݹؼ��ּ����趨��ֵ
	int hash(DataType value, int p);
	//���Һ���������������Ԫ�صĵ�ַ
	int searchHash(DataType value);
private:
	int maxSize; //�������
	int count; //��ǰԪ����
	DataType* elements; //������
};
/***********************hash ����***********************/
template<typename DataType> int HashTable<DataType>::hash(DataType
	value, int p)
{
	return value % p; //���ó����෨����ɢ�е�ַ
}
/**********************�����㷨***********************/
template<typename DataType> int HashTable<DataType>::searchHash(DataType
	value)
{
	int p = hash(value); //�����ַ
	if (elements[p] == value) //�����ȣ�û�з�����ͻ������ p 
	{
		return p;
	}
	int rp = (p + 1) % maxSize; //����̽�ⷨ�����ͻ��ѡȡ d=1 
	while (rp != p) //rp==p ʱ˵��û���ҵ�����Ԫ��
	{
		if (elements[rp] == value) //����µ�ַ��ֵ�� value ��ȣ������µ�ַ
			return rp;
		if (elements[rp] == NULL) //�ҵ��հ׵�ַ
			break;
		rp = (rp + 1) % maxSize; //ѭ��ʹ������̽�ⷨ�ҿհ׵�ַ
	}
	if (rp == p) //����ʧ��
		return -1;
	else
	{
		elements[rp] = value; //�ڿհ׵�ַ�ϲ����Ԫ�ز����ص�ַ
		return rp;
	}

}

//ʵ��
//�� C++����ʵ��ɢ�б�Ĳ���Ͳ��Ҳ�������������{66,32,98,478,11,23}���뵽����
#include<iostream> 
Using namespace std;
/********************ɢ�б��壬���ÿ��Ŷ�ַ�������ͻ****************/
template<typename DataType> class HashTable
{
public:
	HashTable(int size)
	{
		maxSize = size; //��ʼ�����洢�ռ�
		count = 0;
		elements = new DataType[size]; //�������ݿռ�
		if (elements == NULL) //�жϴ洢�ռ��Ƿ����ɹ�
			exit(1);
		for (int i = 0; i < size; i++) //��ʼ��ÿ���洢�ռ��ֵ
			elements[i] = NULL;
	}
	~HashTable()
	{
		delete[] elements;
	}
	//ɢ�к���
	int hash(DataType value);
	//���Һ���������������Ԫ�صĵ�ַ
	int searchHash(DataType value);
	//��ȡɢ�б�ĵ� i ��Ԫ�ص�ֵ
	DataType getData(int i)
	{
		if (i <= 0)
		{
			std::cout << "����ֵ���󣡱���Ϊ������" << endl;
		}
		return elements[i - 1];
	}
	//�������
	bool insertHash(DataType value);
private:
	int maxSize; //�������
	int count; //��ǰԪ����
	DataType* elements; //������
};
/***********************hash ����***********************/
template<typename DataType> int HashTable<DataType>::hash(DataType value)
{
	return value % 13; //���ó����෨����ɢ�е�ַ
}
/**********************�����㷨***********************/
template<typename DataType> int HashTable<DataType>::searchHash(DataType
	value)
{
	int p = hash(value); //�����ַ
	if (elements[p] == value) //�����ȣ�û�з�����ͻ������ p 
	{
		return p;
	}
	int rp = (p + 1) % maxSize; //����̽�ⷨ�����ͻ��ѡȡ d=1 
	while (rp != p) //rp==p ʱ˵��û���ҵ�����Ԫ��
	{
		if (elements[rp] == value) //����µ�ַ��ֵ�� value ��ȣ������µ�ַ
			return rp;
		if (elements[rp] == NULL) //�ҵ��հ׵�ַ
			break;
		rp = (rp + 1) % maxSize; //ѭ��ʹ������̽�ⷨ�ҿհ׵�ַ
	}
	if (rp == p) //����ʧ��
		return -2;
	else
	{
		//elements[rp] = value; //�ڿհ׵�ַ�ϲ����Ԫ�ز����ص�ַ
		return rp;
	}

}
/************************�������**************************/
template<typename DataType> bool HashTable<DataType>::insertHash(DataType
	value)
{
	int pos = searchHash(value); //����ָ��Ԫ�أ�����ɢ�б����Ƿ��Ѿ�����
	if (pos < 0) //����ʧ���ұ���
	{
		return false;
	}
	else if (elements[pos] == value)//���ظ�Ԫ��
	{
		cout << "�ظ���Ԫ�أ�" << endl;
		return false;
	}
	else
	{
		elements[pos] = value; //�ڿհ׵�ַ����Ԫ��
		return true;
	}
}
int main()
{
	HashTable<int> hashtable = HashTable<int>(13); //����ɢ�б�
	//���β���Ԫ��
	hashtable.insertHash(66);
	hashtable.insertHash(32);
	hashtable.insertHash(98);
	hashtable.insertHash(478);
	hashtable.insertHash(11);
	hashtable.insertHash(23);
	hashtable.insertHash(43);
	hashtable.insertHash(55);
	hashtable.insertHash(67);
	hashtable.insertHash(108);
	hashtable.insertHash(230);
	hashtable.insertHash(223);
	hashtable.insertHash(10);
	//���Ԫ��
	cout << "���е�Ԫ��Ϊ��";
	for (int i = 1; i <= 13; i++)
		cout << hashtable.getData(i) << " ";
	cout << endl;
	//����Ԫ�� 55 
	cout << "Ԫ�� 55 ��λ�ã�" << hashtable.searchHash(55) << endl;
	return 0;
}
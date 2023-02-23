//B��
//����
/************************B ���Ķ���***********************/
template<typename DataType> class BTree
{
public:
	BTree()
	{
		root = NULL;
	}
	~BTree()
	{
		//clear(); //��� B ��
	}
private:
	static const int t = 2; //B ������С����
	static const int Key_Max = 2 * t - 1; //����а����Ĺؼ��ֵ�������
	static const int Key_Min = t - 1; //����а����Ĺؼ��ֵ���С����
	static const int Child_Max = Key_Max + 1; //���ӽ���������
	static const int Child_Min = Key_Min + 1; //���ӽ�����С����
	template<class DataType> struct Node
	{
		bool isLeaf;
		int Key_Num; //�������Ĺؼ��ֵĸ���
		DataType keyArray[Key_Max]; //�ؼ�������
		Node<DataType>* pChild[Child_Max]; //����ָ������
		Node<DataType>(bool b = true, int n = 0) :isLeaf(b), Key_Num(n) {}
		//Ĭ�ϳ�ʼ����㺯��
	};
	Node<DataType>* root; //B �������
public:
	/*******************B ��������**********************/
	template<class DataType> struct SearchResult
		//�����������عؼ������ڽ�������
	{
		Node<DataType>* nodeIndex; //���ڵĽ��
		int index; //�ڽ���еĹؼ������к�
	};
	typedef struct SearchResult<DataType> SearchResult<DataType>;
	SearchResult<DataType>* searchNode(Node<DataType>* node, DataType key);
};

//����B��
/*******************B ��������**********************/
/*��������ɹ����������ҵ��Ĺؼ������ڵĽ���ַ�͹ؼ������е������*/
/*****�ýṹ�� SearchResult ��ʾ****************/
template<typename DataType> SearchResult<DataType>* BTree<DataType>::searchNode(Node<DataType>* node,
	DataType key)
{
	SearchResult<DataType>* srP; //�����ṹ��
	int i = 0;
	while (i < node->Key_Num && key > node->keyArray[i])
		//�ڽ����ѭ���ȽϹؼ���
	{
		i++;
	}
	if (i < node->Key_Num && key == node->keyArray[i])
		//��� key �ڸý���У��򷵻ؽ��ָ��͹ؼ�������
	{
		srP = (SearchResult*)malloc(sizeof(struct SearchResult));
		srP->nodeIndex = node;
		srP->index = i;
		return srP;
	}
	if (node->isLeaf) //��� key ���ڸý���У��ҽ��ΪҶ�ӽ���򷵻� NULL 
	{
		return NULL;
	}
	else
	{
		return searchNode(pChild[i], key); //����ݹ�����ӽ��
	}
}
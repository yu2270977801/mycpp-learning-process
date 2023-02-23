///////////////ջ
//ջ�Ķ���
/************************ջ�Ķ���***********************/
template<typename DataType> class Stack
{
public:
	Stack(int size)
	{
		maxSize = size; //�����������
		top = -1; //��ʼ��Ϊ��ջ
		elements = new DataType[size]; //����ռ�
	}
	~Stack()
	{
		delete[] elements;
	}
	//��ջ����
	Bool push(DataType data);
	//��ջ����
	DataType pop();
private:
	DataType *elements; //������ָ��
	int top; //ջ��
	int maxSize; //ջ���������
};

//////////��������
//��ջ����������������Ҫ�ڱ�β����Ԫ��
/*****************��ջ����************************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if (top == maxSize) //�ж��Ƿ�ջ��
		return false;
	elements[++top] = data; //��ջ��ѹ��Ԫ��
	return true;
}
//��ջ����������������Ҫ�Ǵ�ջ������Ԫ��
/********************��ջ����*******************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if (pop == -1) //�ж��Ƿ�ջ��
	{
		exit(1);
	}
	return elements[top--]; //����ջ��Ԫ��
}


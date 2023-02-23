///////////////栈
//栈的定义
/************************栈的定义***********************/
template<typename DataType> class Stack
{
public:
	Stack(int size)
	{
		maxSize = size; //设置最大容量
		top = -1; //初始化为空栈
		elements = new DataType[size]; //分配空间
	}
	~Stack()
	{
		delete[] elements;
	}
	//入栈操作
	Bool push(DataType data);
	//出栈操作
	DataType pop();
private:
	DataType *elements; //数据域指针
	int top; //栈顶
	int maxSize; //栈的最大容量
};

//////////基本操作
//入栈操作—————主要在表尾插入元素
/*****************入栈操作************************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if (top == maxSize) //判断是否栈满
		return false;
	elements[++top] = data; //从栈顶压入元素
	return true;
}
//出栈操作—————主要是从栈顶弹出元素
/********************出栈操作*******************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if (pop == -1) //判断是否栈空
	{
		exit(1);
	}
	return elements[top--]; //返回栈顶元素
}


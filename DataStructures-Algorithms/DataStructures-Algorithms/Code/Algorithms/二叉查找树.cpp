}
 }
 return NULL; //����ʧ��
}
int main()
{
	int data[] = { 12,23,24,34,45,56,67,78,89,99 };
	int key;
	cout << "������Ҫ���ҵ����֣�";
	cin >> key;
	cout << endl;
	int result = binSearch(data, 10, key);
	cout << "���������������" << key << ",����λ���ǣ�" << result << endl;
	return 0;
}
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

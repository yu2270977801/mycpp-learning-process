//ͼ�Ĵ洢�ṹ
//�ڽӾ���洢
/************************��Ȩͼ���ڽӾ���洢�ṹ********************/
#include <iostream> 
using namespace std;
template<class DataType> class AdjacencyGraphic
{
public:
	AdjacencyGraphic(int Vertice = 10, DataType noEdge = 0); //���캯��
	~AdjacencyGraphic()
	{
		delete2DArray(a, v + 1); //ɾ����ά���飬���ڽӾ���
	}
	bool exist(int i, int j) const; //�ж�������Ƿ��б�
	int edges() const //����ͼ�ı���
	{
		return e;
	}
	int vertices() const //����ͼ�Ķ�����
	{
		return v;
	}
	AdjacencyGraphic<DataType>& add(int i, int j, const DataType& w);
	//��ӱ�
	AdjacencyGraphic<DataType>& deleteEdge(int i, int j);
	//ɾ�������ı�
	int outDegree(int i) const; //����һ������ĳ���
	int inDegree(int i) const; //����һ����������
	void make2DArray(DataType**& x, int rows, int cols);
	//������ά���󣬼��ڽӾ���
	void delete2DArray(DataType**& x, int rows); //ɾ���ڽӾ���
private:
	DataType NoEdge; //����û�бߴ��ڵ����
	int v; //������
	int e; //����
	DataType** a; //��ά����
};
template<class DataType> void AdjacencyGraphic<DataType>::make2DArray
(DataType**& x, int rows, int cols)
{
	x = new DataType * [rows]; //������ָ��
	for (int i = 0; i < rows; i++)
	{
		x[i] = new DataType[cols]; //�����пռ�
	}
}
template<class DataType> void AdjacencyGraphic<DataType>::delete2DArray
(DataType**& x, int rows)
{
	for (int i = 0; i < rows; i++) //ɾ��ÿ�еĿռ�
	{
		delete[] x[i];
	}
	delete[] x; //ɾ��ָ������
	x = 0; //x ָ���ÿ�
}
template<class DataType> AdjacencyGraphic<DataType>::AdjacencyGraphic(int
	Vertices, DataType noEdge)
{
	v = Vertices;
	e = 0;
	NoEdge = noEdge;
	make2DArray(a, n + 1, n + 1);
	//��ʼ��û�бߵ�ͼ
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = noEdge;
		}
	}
}

//�ڽӱ�洢
/*************************�ڽӱ�洢�ṹ**************************/
template<class DataType> class LinkedGraph
{
public:
	LinkedGraph(int Vertices = 10, int check = 1) //���캯��
	{
		v = Vertices; //������
		e = 0; //����
		Check = check; //1 ��ʾ����ͼ��0 ��ʾ����ͼ
		h = new LinkList<DataType>[v + 1]; //Ϊ�洢�������������ڴ�ռ�
	}
	~LinkedGraph()
	{
		delete[] h; //ɾ������ռ�
	}
	int edges() const; //����ͼ�ı���
	int vertices() const; //����ͼ�Ķ�����
	int outDgree(int i) const //����ĳ����ĳ���
	{
		if (i<1 || i>n)
		{
			throw OutOfBounds();
		}
		return h[i].getLength(); //ĳ�����������
	}
	int inDgree(int i) const; //�������
	bool exist(int i, int j) const; //����������Ƿ���ڱ�
	LinkedGraph<DataType>& add(int i, int j, const DataType& w); //��ӱ�
	LinkedGraph<DataType>& delete(int i, int j, int check); //ɾ����
private:
	int v; //������
	int e; //����
	LinkList<DataType>* h; //�洢���������
	int Check; //�ж��Ƿ�����ͼ��1 Ϊ����ͼ��0 Ϊ����ͼ
};

//////////////��������
//�ж�����֮���Ƿ��бߴ���
/*
*���ڽӾ���洢�ṹ�ϣ��ж���������֮���Ƿ��бߴ��ھ����ж��ھ����� a[i][j]�Ƿ�Ϊ noEdge��
*/
/*********************�ж�������֮���Ƿ��б�**********************/
template<class DataType> bool AdjacencyGraphic<DataType>::exist(int i, int
	j) const
{
	if (i<1 || j<1 || i>n || j>n || a[i][j] == NoEdge)
		//�ж�����ĵ��Ƿ������Ƿ��б�
	{
		return false;
	}
	return true;
}
/*
*��������ڽӱ�ṹ�ϣ�����ֻ��Ҫ������ʼ����Ϊͷ���ı�����鿴�Ƿ��иı���ս�㣬���������ڱߣ����û���򲻴��ڱ�
*/
/*****************�ڽӱ��ж�����֮���Ƿ��б�******************/
template<class DataType> bool LinkedGraph<DataType>::exist(int i, int j)
const
{
	if (i<1 || j>n) //��֤����ĵ��Ƿ�Խ��
	{
		throw OutOfBounds();
	}
	return (h[i].findNode(j)) ? true : false;
	//����������ҹ��ܲ��ұ߽�� j����������򷵻� true�����򷵻� false 
}

//��ӱ�
/*
* ���ڽӾ�������ӱߵĲ������Ǹ��ľ���Ԫ�� a[i][ j]��ֵ��ʹ�䲻���� noEdge������Ǽ�Ȩͼ���޸�Ϊ�ߵ�Ȩֵ��
*/
/***********************�ڽӾ�����ӱ�***********************/
template<class DataType> AdjacencyGraphic<DataType>& AdjacencyGraphic
<DataType>::add(int i, int j, const DataType& w)
{
	if (i<1 || j<1 || i>n || j>n || a[i][j] != NoEdge)
	{
		throw out_of_range(); //�������ĵ㲻���ڣ��׳�Խ���쳣
	}
	a[i][j] = w; //��ӱߵ�Ȩֵ
	e++;
	if (check == 0) //���������ͼ����Գ���ӱߣ��������������
	{
		a[j][i] = w;
	}
	return *this; //����ͼ�ĵ�ַ
}
/*
* ���ڽӱ�洢�Ľṹ�ϣ�ʵ����ӱߵĲ���ֻ��Ҫ����صĵ�ı�������ӽ�㡣
*/
/*********************�ڽӱ���ӱ�********************************/
template<class DataType> LinkedGraph<DataType>& add(int i, int j)
{

	h[i].insertNode(j); //Ϊ��������ӽ��
	if (Check == 0)
	{
		h[j].insertNode(i); //���������ͼ����ֻ��Ҫ�� j ���Ϊ���������ϵ� i �ı�
	}
	e++; //�������� 1 
	return *this;
}

//ɾ����
/*
* ���ڽӾ�����ɾ����ֻ��Ҫ�������е� a[i][j]�� a[j][i]����Ϊ NoEdge ��ֵ��
*/
/*************************�ڽӾ���ɾ����*************************/
template<class DataType> AdjacencyGraphic<DataType>& AdjacencyGraphic
<DataType>::deleteEdge(int i, int j)
{
	if (i<1 || i>n || j<1 || j>n || a[i][j] == NoEdge) //�жϵ��Ƿ�Խ��
	{
		throw out_of_range(); //������벻��Ҫ����ܳ�Խ���쳣
	}
	a[i][j] = this->NoEdge; //�������еıߵ�ֵ��Ϊ NoEdge 
	if (Check == 0)
	{
		a[j][i] = NoEdge;
	}
	e--; //������ 1 
	return *this;
}
/*
* ���ڽӱ�����Ҫ����ʼ����ı��������յ�����Ӧ�ı߽��ɾ����
*/
/*************************�ڽӱ�ɾ����**************************/
template<class DataType> LinkedGraph<DataType>& LinkedGraph<DataType>::deleteEdge(int i, int j)
	{
		if (i<1 || i>n || j<1 || j>n)
		{
			throw out_of_range(); //��֤����ĵ��Ƿ����
		}
		ListNode<int>* node = h[i].findNode(j); //�ҳ���Ҫɾ���ı߽��
		h[i].removeNode(node); //ɾ���߽��
		if (Check == 0)
		{
			h[j].removeNode(h[j].findNode(i)); //���������ͼ��Ҫɾ������
		}
		e--; //�������� 1 
		return *this;
}

//�����ĳ���
/*
* ���ڽӾ���ṹ�ϼ����ĳ��Ⱦ��Ǽ����ھ����� a[i]��һ���бߵ�Ԫ�ظ�����
*/
/*********************�ڽӾ���������***********************/
template<class DataType> int AdjacencyGraphic<DataType>::outDegree(int i) const
{
	if (i<1 || i>n)
	{
		throw out_of_range(); //�жϱ߽�
	}
	int sum = 0;
	for (int j = 0; j < v; j++)
	{
		if (a[i][j] != NoEdge) //�������
		{
			sum++;
		}
	}
	return sum;
}

/*
* �ڽӱ�ĳ��ȼ�����Ǽ�����ı�����ĳ��ȡ�
*/
int outDgree(int i) const //����ĳ����ĳ���
{
	if (i<1 || i>n)
	{
		throw out_of_range();
	}
	return h[i].getLength(); //ĳ�����������
}

//������ȱ���������DFS
/*********************��ȱ����ĸ�������*************************/
template<class DataType> int LinkedGraph<DataType>::getFirstADJ(int vertex)
//���ص�һ���ڽӵ���
{
	if (h[vertex].getNode(1)->getNext() != NULL)
	{
		return h[vertex].getNode(1)->getNext()->getData();
	}
	return -1; //���δ�ҵ��ͷ���-1 
}
template<class DataType> int LinkedGraph<DataType>::getNextADJ(int vertex)
//������һ���ڽӵ����
{
	for (int i = 0; i < h[vertex].getLength(); i++)
	{
		if (visited[h[vertex].getNode(i)->getData()] != 0)
		{
			return h[vertex].getNode(i)->getData();
		}
	}
	return -1;
}
/********************������ȱ�����ʵ��****************************/
template<class DataType> void LinkedGraph<DataType>::DFS(int vertex)
//��ȱ���������
{
	int[] visited = new int[v]; //���ʱ������
	for (int i = 0; i < this->v; i++) //��ʼ���������飬ÿ��������Ϊ 0����ʾδ����
	{
		visited[i] = 0;
	}
	dfs(vertex); //���� dfs ����
	delete[] visited; //ɾ�����ʱ������
}
/*********************������ȱ�����ʵ��ִ�д���**********************/
template<class DataType> void LinkedGraph<DataType>::dfs(int vertex)
//������ȱ���ʵ��ִ�д���
{
	int u;
	std::cout << h->getNodeData(vertex) << endl; //�������ֵ
	visited[vertex] = 1; //�����Ϊ�ѷ���
	u = getFirstADJ(vertex); //Ѱ�ҵ�һ���ڽӵ�
	while (u)
	{
		if (visited[u] == 0)
		{
			dfs(u); //�ݹ���� DFS 
		}
		u = getNextADJ(vertex); //Ѱ����һ���ڽӵ�
	}

}

//������ȱ���
/***********************������ȱ���**********************/
template<class DataType> void LinkedGraph<DataType>::BFS(int vertex)
{
	int u;
	cout << vertex << endl; //���������
	int[] visited = new int[v]; //���÷��ʱ������
	for (int i = 0; i < v; i++)
	{
		visited[i] = 0; //��ʼ��Ϊ 0����ʾδ����
	}
	visited[vertex] = 1;
	Queue<int> queue = new Queue<int>(v); //���ö��У���¼����˳��
	queue.insert(vertex);
	while (!queue.isEmpty()) //���в�Ϊ��ѭ������
	{
		vertex = queue.delElement(); //����
		u = getFirstADJ(v); //��ȡ��һ��Ԫ��
		while (w != 0)
		{
			if (visited[u] == 0) //���û���ʹ� u������ӣ����ı��Ϊ 1 
			{
				cout << u << endl;
				queue.insert(u);
				visited[u] = 1;
			}
			u = getNextADJ(v); //���� v ����һ���ڽӵ�
		}
	}
}

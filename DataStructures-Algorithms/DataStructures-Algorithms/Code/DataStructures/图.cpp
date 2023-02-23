//图的存储结构
//邻接矩阵存储
/************************加权图的邻接矩阵存储结构********************/
#include <iostream> 
using namespace std;
template<class DataType> class AdjacencyGraphic
{
public:
	AdjacencyGraphic(int Vertice = 10, DataType noEdge = 0); //构造函数
	~AdjacencyGraphic()
	{
		delete2DArray(a, v + 1); //删除二维数组，即邻接矩阵
	}
	bool exist(int i, int j) const; //判断两点间是否有边
	int edges() const //返回图的边数
	{
		return e;
	}
	int vertices() const //返回图的顶点数
	{
		return v;
	}
	AdjacencyGraphic<DataType>& add(int i, int j, const DataType& w);
	//添加边
	AdjacencyGraphic<DataType>& deleteEdge(int i, int j);
	//删除两点间的边
	int outDegree(int i) const; //计算一个顶点的出度
	int inDegree(int i) const; //计算一个顶点的入度
	void make2DArray(DataType**& x, int rows, int cols);
	//建立二维矩阵，即邻接矩阵
	void delete2DArray(DataType**& x, int rows); //删除邻接矩阵
private:
	DataType NoEdge; //用于没有边存在的情况
	int v; //顶点数
	int e; //边数
	DataType** a; //二维数组
};
template<class DataType> void AdjacencyGraphic<DataType>::make2DArray
(DataType**& x, int rows, int cols)
{
	x = new DataType * [rows]; //分配行指针
	for (int i = 0; i < rows; i++)
	{
		x[i] = new DataType[cols]; //分配行空间
	}
}
template<class DataType> void AdjacencyGraphic<DataType>::delete2DArray
(DataType**& x, int rows)
{
	for (int i = 0; i < rows; i++) //删除每行的空间
	{
		delete[] x[i];
	}
	delete[] x; //删除指针数组
	x = 0; //x 指针置空
}
template<class DataType> AdjacencyGraphic<DataType>::AdjacencyGraphic(int
	Vertices, DataType noEdge)
{
	v = Vertices;
	e = 0;
	NoEdge = noEdge;
	make2DArray(a, n + 1, n + 1);
	//初始化没有边的图
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = noEdge;
		}
	}
}

//邻接表存储
/*************************邻接表存储结构**************************/
template<class DataType> class LinkedGraph
{
public:
	LinkedGraph(int Vertices = 10, int check = 1) //构造函数
	{
		v = Vertices; //顶点数
		e = 0; //边数
		Check = check; //1 表示有向图，0 表示无向图
		h = new LinkList<DataType>[v + 1]; //为存储顶点的数组分配内存空间
	}
	~LinkedGraph()
	{
		delete[] h; //删除顶点空间
	}
	int edges() const; //计算图的边数
	int vertices() const; //计算图的顶点数
	int outDgree(int i) const //计算某个点的出度
	{
		if (i<1 || i>n)
		{
			throw OutOfBounds();
		}
		return h[i].getLength(); //某顶点的链表长度
	}
	int inDgree(int i) const; //计算入度
	bool exist(int i, int j) const; //检验连点间是否存在边
	LinkedGraph<DataType>& add(int i, int j, const DataType& w); //添加边
	LinkedGraph<DataType>& delete(int i, int j, int check); //删除边
private:
	int v; //顶点数
	int e; //边数
	LinkList<DataType>* h; //存储顶点的数组
	int Check; //判断是否有向图，1 为有向图，0 为无向图
};

//////////////基本操作
//判定顶点之间是否有边存在
/*
*在邻接矩阵存储结构上，判定两个顶点之间是否有边存在就是判定在矩阵中 a[i][j]是否为 noEdge。
*/
/*********************判定两个点之间是否有边**********************/
template<class DataType> bool AdjacencyGraphic<DataType>::exist(int i, int
	j) const
{
	if (i<1 || j<1 || i>n || j>n || a[i][j] == NoEdge)
		//判定输入的点是否出界和是否有边
	{
		return false;
	}
	return true;
}
/*
*如果是在邻接表结构上，我们只需要遍历起始顶点为头结点的边链表查看是否有改变的终结点，如果有则存在边，如果没有则不存在边
*/
/*****************邻接表判断两点之间是否有边******************/
template<class DataType> bool LinkedGraph<DataType>::exist(int i, int j)
const
{
	if (i<1 || j>n) //验证输入的点是否越界
	{
		throw OutOfBounds();
	}
	return (h[i].findNode(j)) ? true : false;
	//利用链表查找功能查找边结点 j，如果存在则返回 true，否则返回 false 
}

//添加边
/*
* 在邻接矩阵中添加边的操作就是更改矩阵元素 a[i][ j]的值，使其不等于 noEdge，如果是加权图则修改为边的权值。
*/
/***********************邻接矩阵添加边***********************/
template<class DataType> AdjacencyGraphic<DataType>& AdjacencyGraphic
<DataType>::add(int i, int j, const DataType& w)
{
	if (i<1 || j<1 || i>n || j>n || a[i][j] != NoEdge)
	{
		throw out_of_range(); //如果输入的点不存在，抛出越界异常
	}
	a[i][j] = w; //添加边的权值
	e++;
	if (check == 0) //如果是无向图，则对称添加边，但不计入边总数
	{
		a[j][i] = w;
	}
	return *this; //返回图的地址
}
/*
* 在邻接表存储的结构上，实现添加边的操作只需要给相关的点的边链表添加结点。
*/
/*********************邻接表添加边********************************/
template<class DataType> LinkedGraph<DataType>& add(int i, int j)
{

	h[i].insertNode(j); //为边链表添加结点
	if (Check == 0)
	{
		h[j].insertNode(i); //如果是无向图，则只需要在 j 结点为起点的链表上到 i 的边
	}
	e++; //边数增加 1 
	return *this;
}

//删除边
/*
* 在邻接矩阵上删除边只需要将矩阵中的 a[i][j]或 a[j][i]设置为 NoEdge 的值。
*/
/*************************邻接矩阵删除边*************************/
template<class DataType> AdjacencyGraphic<DataType>& AdjacencyGraphic
<DataType>::deleteEdge(int i, int j)
{
	if (i<1 || i>n || j<1 || j>n || a[i][j] == NoEdge) //判断点是否越界
	{
		throw out_of_range(); //如果输入不合要求就跑出越界异常
	}
	a[i][j] = this->NoEdge; //将矩阵中的边的值设为 NoEdge 
	if (Check == 0)
	{
		a[j][i] = NoEdge;
	}
	e--; //边数减 1 
	return *this;
}
/*
* 在邻接表上需要将起始顶点的边链表中终点结点相应的边结点删除。
*/
/*************************邻接表删除边**************************/
template<class DataType> LinkedGraph<DataType>& LinkedGraph<DataType>::deleteEdge(int i, int j)
	{
		if (i<1 || i>n || j<1 || j>n)
		{
			throw out_of_range(); //验证输入的点是否存在
		}
		ListNode<int>* node = h[i].findNode(j); //找出需要删除的边结点
		h[i].removeNode(node); //删除边结点
		if (Check == 0)
		{
			h[j].removeNode(h[j].findNode(i)); //如果是无向图需要删除两次
		}
		e--; //边数减少 1 
		return *this;
}

//计算点的出度
/*
* 在邻接矩阵结构上计算点的出度就是计算在矩阵中 a[i]这一行有边的元素个数。
*/
/*********************邻接矩阵计算出度***********************/
template<class DataType> int AdjacencyGraphic<DataType>::outDegree(int i) const
{
	if (i<1 || i>n)
	{
		throw out_of_range(); //判断边界
	}
	int sum = 0;
	for (int j = 0; j < v; j++)
	{
		if (a[i][j] != NoEdge) //计算出度
		{
			sum++;
		}
	}
	return sum;
}

/*
* 邻接表的出度计算就是计算结点的边链表的长度。
*/
int outDgree(int i) const //计算某个点的出度
{
	if (i<1 || i>n)
	{
		throw out_of_range();
	}
	return h[i].getLength(); //某顶点的链表长度
}

//深度优先遍历———DFS
/*********************深度遍历的辅助函数*************************/
template<class DataType> int LinkedGraph<DataType>::getFirstADJ(int vertex)
//返回第一个邻接点编号
{
	if (h[vertex].getNode(1)->getNext() != NULL)
	{
		return h[vertex].getNode(1)->getNext()->getData();
	}
	return -1; //如果未找到就返回-1 
}
template<class DataType> int LinkedGraph<DataType>::getNextADJ(int vertex)
//返回下一个邻接点序号
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
/********************深度优先遍历的实现****************************/
template<class DataType> void LinkedGraph<DataType>::DFS(int vertex)
//深度遍历主函数
{
	int[] visited = new int[v]; //访问标记数组
	for (int i = 0; i < this->v; i++) //初始化访问数组，每个点均标记为 0，表示未访问
	{
		visited[i] = 0;
	}
	dfs(vertex); //调用 dfs 函数
	delete[] visited; //删除访问标记数组
}
/*********************深度优先遍历的实际执行代码**********************/
template<class DataType> void LinkedGraph<DataType>::dfs(int vertex)
//深度优先遍历实际执行代码
{
	int u;
	std::cout << h->getNodeData(vertex) << endl; //输出结点的值
	visited[vertex] = 1; //结点标记为已访问
	u = getFirstADJ(vertex); //寻找第一个邻接点
	while (u)
	{
		if (visited[u] == 0)
		{
			dfs(u); //递归调用 DFS 
		}
		u = getNextADJ(vertex); //寻找下一个邻接点
	}

}

//广度优先遍历
/***********************广度优先遍历**********************/
template<class DataType> void LinkedGraph<DataType>::BFS(int vertex)
{
	int u;
	cout << vertex << endl; //输出顶点编号
	int[] visited = new int[v]; //设置访问标记数组
	for (int i = 0; i < v; i++)
	{
		visited[i] = 0; //初始化为 0，表示未访问
	}
	visited[vertex] = 1;
	Queue<int> queue = new Queue<int>(v); //设置队列，记录访问顺序
	queue.insert(vertex);
	while (!queue.isEmpty()) //队列不为空循环遍历
	{
		vertex = queue.delElement(); //出队
		u = getFirstADJ(v); //获取第一个元素
		while (w != 0)
		{
			if (visited[u] == 0) //如果没访问过 u，则入队，更改标记为 1 
			{
				cout << u << endl;
				queue.insert(u);
				visited[u] = 1;
			}
			u = getNextADJ(v); //访问 v 的下一个邻接点
		}
	}
}

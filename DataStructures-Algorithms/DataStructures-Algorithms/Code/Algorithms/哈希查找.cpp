//1.开放地址法解决冲突的哈希查找算法
/********************散列表定义，利用开放定址法处理冲突****************/ 
template<typename DataType> class HashTable 
{ 
public: 
    HashTable(int size) 
    { 
        maxSize = size; //初始化最大存储空间
        count = 0; 
        elements = new DataType[size]; //分配数据空间
        if(elements == NULL) //判断存储空间是否分配成功
            exit(1); 
        for(int i=0;i<size;i++) //初始化每个存储空间的值
            elements[i] = NULL; 
    } 
    ~HashTable()
    { 
        delete[] elements; 
    } 
    //散列函数
    int hash(DataType value); 
    //查找函数，返回所查找元素的地址
    int searchHash(DataType value); 
    //获取散列表的第 i 个元素的值
    DataType getData(int i) 
    { 
        if(i<=0) 
        { 
            std::cout<<"索引值错误！必须为正整数"<<endl; 
        } 
        return elements[i-1]; 
    } 
    //插入操作
    bool insertHash(DataType value); 
private: 
    int maxSize; //最大容量
    int count; //当前元素数
    DataType *elements; //数据域
}; 
/***********************hash 函数***********************/ 
template<typename DataType> int HashTable<DataType>::hash(DataType value) 
{ 
    return value % 13; //采用除留余法计算散列地址
} 
/**********************hash 查找算法,开放定址法解决冲突***************/ 
template<typename DataType> int HashTable<DataType>::searchHash(DataType 
value) 
{ 
    int p = hash(value); //计算地址
    if(elements[p] == value) //如果相等，没有发生冲突，返回 p 
    { 
        return p; 
    } 
    int rp = (p+1) % maxSize; //线性探测法处理冲突，选取 d=1 
    while(rp != p) //rp==p 时说明没有找到所需元素
    { 
        if(elements[rp] == value)//如果新地址的值与 value 相等，则返回新地址
            return rp; 
        if(elements[rp] == NULL) //找到空白地址
            break; 
        rp = (rp+1) % maxSize; //循环使用线性探测法找空白地址
    } 
    if(rp == p) //查找失败
        return -2; 
    else 
    { 
        //elements[rp] = value; //在空白地址上插入此元素并返回地址
        return rp; 
    } 
}

//2.链地址法查找
#include <iostream>
#define P 13 
using namespace std; 
/*****************定义同义词结点数据结构************/ 
typedef struct node{ 
    int key; //关键字值
    struct node *next; //链表指针
}ChainHash; 
ChainHash *h[P]; //设置链表指针数组
/************链地址法查找算法****************/ 
ChainHash* chHashSerch(int k){ 
    ChainHash *q; 
    int d; 
    d = k%P; //计算哈希地址
    q = h[d]; //找到确定的单链表入口
    /************扫描计算得出的单链表**************/ 
    while (q != NULL && q->key != k) 
    { 
        q = q->next; 
    } 
    return q; 
} 
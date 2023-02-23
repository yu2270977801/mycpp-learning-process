/////////////////////////顺序表的定义
//定义：
/***************线性表数据结构***************/
const int defaultSize = 10; //设置默认顺序表大小
template <typename DataType> class SeqList
{
public: //构造函数
    SeqList(int size = defaultSize) {
        if (size > 0) //检查赋予的顺序表大小，如果合法则分配相应大小的内存
        {
            maxSize = size;
            elements = new DataType[maxSize]; //分配内存大小
        }
    }
    //析构函数
    ~SeqList()
    {
        delete[] elements; //回收内存空间
    }
private:
    Datatype* elements;
    int maxSize; //顺序表最大大小
};






/****************线性表数据结构****************/
const int defaultSize = 10;  //设置默认顺序表大小
template <typename DataType> class SeqList
{
private:
    DataType *elements;
    int maxSize;  //顺序表最大大小
    int length;   //顺序表的有效长度
public:
    //构造函数
    SeqList(int size = defaultSize){
        if (size > 0)  //检查赋予的顺序表大小，如果合法则分配相应大小的内存
        {
            maxSize = size;
            elements = new  DataType[maxSize];  //分配内存大小
        }
        
    }
    //析构函数
    ~SeqList()
    {
        delete[] elements;  //回收内存空间
    }
    bool insertElement(DataType data);  //向表尾插入新元素
    bool deletElement(int location);  //删除指定位置的元素
    DataType getElement(int location);  //返回指定位置的元素
    bool changeElement(int location,DataType newData);  //修改指定位置的元素值
};

//顺序表的基本操作
/****************顺序表插入操作****************/
/*步骤：
*1.检查顺序表是否已满，如果已满则进行提示并拒绝执行插入操作。
*2.如果顺序表未满，则将新元素插入表尾空间中，并将顺序表的有效大小加 1。
*/
template <typename DataType> bool SeqList<DataType>::insertElement(DataType data)
{
    int  currentIndex = length;  //记录新元素的插入位置
    if (length >= maxSize)  //判断顺序表是否已满
    {
        return false;  //顺序表已满，返回false,插入不成功
    }
    else
    {
        elements[currentIndex] = data;  //将新元素插入顺序表表尾
        length++;  //顺序表有效长度加1
        return true;
    }
}
/****************删除指定位置的元素****************/
template <typename DataType> bool SeqList<DataType>::deletElement(int location) 
{ 
    if(location >= length || location < 0) //验证位置索引参数是否有效
    { 
        return false; 
    } 
    else 
    { 
        for(int i = location;i<length;i++) 
        { 
                elements[i] = elements[i+1];  //将指定位置之后的元素依次往前移动覆盖前一个元素
        } 
        length--;  //顺序表长度减 1 
        return true; 
    } 
}
/****************获取指定位置的元素****************/
template <typename DataType> DataType SeqList< DataType>::getElement(int location)
{
    if (location < 0 || location > length)  //判断位置索引是否合法
    {
        std::cout<<"参数无效"<<std::endl;
        return 0;
    }
    else
    {
        return elements[location];  //返回指定位置的元素
    }
}
/****************修改指定位置的元素值****************/
template <typename DataType> bool SeqList<DataType>::changeElement(int location,DataType newData)
{
    if (location < 0 || location >= length)  //验证位置索引参数是否有效
    {
        return false;
    }
    else
    {
        elements[location] = newData;  //将指定位置赋值给新元素
        return true;
    }
}

/////////////////////////实例
/*
*例：用 C++实现一个顺序表，使其可存储 10 个整型数据，并可实现插入、修改
*元素、删除元素和输出整个顺序表的功能
*/
#include <iostream> 
using namespace std;
/***************线性表数据结构***************/ 
template <typename DataType> class SeqList 
{ 
public: 
    //构造函数
    SeqList(int size=defaultSize){ 
        if(size >0) //检查赋予的顺序表大小，如果合法则分配相应大小的内存
        { 
            maxSize = size; 
            length = 0; 
            elements = new DataType[maxSize]; //分配内存大小
            for(int i = 0;i<maxSize;i++) 
            elements[i] = NULL; 
        } 
    } 
    //析构函数
    ~SeqList() 
    { 
        delete[] elements; //回收内存空间
    } 
    
    bool insertElement(DataType data); //向表尾插入新元素
    
    bool deleteElement(int location); //删除指定位置的元素
    
    DataType getElement(int location); //返回指定位置的元素
    
    bool changeElement(int location,DataType newData); //修改指定位置的元素值
    
    //获取顺序表长度
    int getLength() 
    { 
        return length; 
    } 
private: 
    static const int defaultSize = 10; 
    DataType *elements; 
    int maxSize; //顺序表最大大小
    int length; //顺序表的有效长度
}; 
/***************顺序表插入操作********************/ 
template <typename DataType> bool SeqList<DataType>::insertElement(DataType data) 
{ 
 
    int currentIndex = length; //记录新元素的插入位置
    if(length >= maxSize) //判断顺序表是否已满
    { 
        return false; //顺序表已满，返回 false，插入不成功
    } 
    else 
    { 
        elements[currentIndex] = data; //将新元素插入顺序表表尾
        length++; //顺序表有效长度加 1 
        return true; 
    } 
} 
/**************获取指定位置的元素*********************/ 
template <typename DataType> DataType SeqList<DataType>::getElement(int location) 
{ 
    if(location<0 || location>length) //判断位置索引是否合法
    { 
        std::cout<<"参数无效"<<std::endl; 
        return 0; 
    } 
    else 
    { 
        return elements[location]; //返回指定位置的元素
    } 
} 
/**************删除指定位置的元素********************/ 
template <typename DataType> bool SeqList<DataType>::deleteElement(int location) 
{ 
    if(location >= length || location < 0) //验证位置索引参数是否有效
    { 
        return false; 
    } 
    else 
    { 
        for(int i = location;i<length;i++) 
        { 
            elements[i] = elements[i+1];  //将指定位置之后的元素依次往前移动覆盖前一个元素
        } 
        length--; //顺序表长度减 1 
        return true; 
    } 
} 
/**************修改指定位置的元素值********************/ 
template<typename DataType> bool SeqList<DataType>::changeElement(int location,DataType newData) 
{ 
    if(location<0 || location >= length) //验证位置索引参数是否有效
    { 
        return false; 
    } 
    else 
    { 
        elements[location] = newData; //将指定位置赋值给新元素
        return true; 
    } 
} 
int main() 
{

    SeqList<int> list(10); //建立顺序表
    for(int i = 0;i<10;i++) 
    { 
        list.insertElement(i*10); //插入数据实现初始化
    } 
    for(int i = 0;i<list.getLength();i++)  //输出初始化后的顺序表
        cout<<list.getElement(i)<<" "; 
    cout<<endl; 
    list.deleteElement(3);  //删除索引为 3 的元素
    for(int i = 0;i<list.getLength();i++)  //输出删除元素后的顺序表
        cout<<list.getElement(i)<<" "; 
    cout<<endl; 
    list.changeElement(5,44);   //将顺序表索引为 5 的元素值修改为 44 
    for(int i = 0;i<list.getLength();i++)  //输出修改后的顺序表
        cout<<list.getElement(i)<<" "; 
    cout<<endl; 
    
    return 0; 
} 
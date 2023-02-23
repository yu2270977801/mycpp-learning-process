template<class DataType> SearchResult<DataType>* BTree<DataType>:: 
searchNode(Node<DataType>* node,DataType key) 
{ 
    int i = 0; 
    SearchResult<DataType>* result=NULL; //声明返回结果类
    while(i < (node->Key_Num) && key >= node->keyArray[i]) 
    //依次比较 key 与 node 中的关键字
    { 
        if (key == node->keyArray[i]) 
        //如果 key 等于关键字则返回关键字的结点指针和关键字序号
        { 
            result = (SearchResult<DataType>*)malloc(sizeof(SearchResult 
            <DataType>)); //为返回结果分配空间
            result->nodeIndex = node; 
            result->index = i; 
            return result; 
        } 
        i++; 
     } 
    if (i == node->Key_Num) 
    //如果 i 查出关键字个数，则进入最大子结点查询
    { 
        node=node->pChild[i+1]; 
    }else 
    { 
        node = node->pChild[i]; //在相应字数中查询
    } 
    searchNode(node,key); 
} 

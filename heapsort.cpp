#include <iostream>
using namespace std;

//堆排序
//整理节点time:O(lgn)

void printArray(int* arry, int size){
	for(int i = 0;i < size; ++i){
		cout<<arry[i]<<",";
	}
	cout<<endl;
}
void MinHeapify(int* arry,int size,int element)
{
int lchild=element*2+1,rchild=lchild+1;//左右子树
while(rchild<size)//子树均在范围内
{
if(arry[element]<=arry[lchild]&&arry[element]<=arry[rchild])//如果比左右子树都小，完成整理
{
return;
}
if(arry[lchild]<=arry[rchild])//如果左边最小
{
swap(arry[element],arry[lchild]);//把左面的提到上面
element=lchild;//循环时整理子树
}
else//否则右面最小
{
swap(arry[element],arry[rchild]);//同理
element=rchild;
}
lchild=element*2+1;
rchild=lchild+1;//重新计算子树位置
}
if(lchild<size&&arry[lchild]<arry[element])//只有左子树且子树小于自己
{
swap(arry[lchild],arry[element]);
}
return;
}

void HeapSort(int* arry,int size)
{
int i;
for(i=size-1;i>=0;i--)//从子树开始整理树
{
MinHeapify(arry,size,i);
printArray(arry, size);
}
while(size>0)//拆除树
{
swap(arry[size-1],arry[0]);//将根（最小）与数组最末交换
size--;//树大小减小
MinHeapify(arry,size,0);//整理树
}
return;
}

int main(){
	int a[8]={8,1,2,5,4,3,7,6};
	HeapSort(a, 8);
	//printArray(a, 8);
}
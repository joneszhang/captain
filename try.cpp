#include <iostream>
#include <vector>
#include <map>
using namespace std;

void swap(int& a, int& b){
  int tmp = a;
  a = b;
  b= tmp;
}

void quicksort(int list[], int s, int e){

  if(s >= e) return;

  int x = list[e];
  int i = s-1;
  for(int j = s;j < e; ++j){
    if(list[j] < x){
      ++i;
      swap(list[i],list[j]);
    }
  }
  swap(list[i+1], list[e]);

  if(e == s + 1) return;

  quicksort(list, s, i);
  quicksort(list, i+2, e);
}

void print(int a[], int n ,int i){  
    cout<<i <<":";  
    for(int j= 0; j<8; j++){  
        cout<<a[j] <<" ";  
    }  
    cout<<endl;  
}  


void InsertSort(int a[], int n)  
{  
    for(int i= 1; i<n; i++){  
        if(a[i] < a[i-1]){               //若第i个元素大于i-1元素，直接插入。小于的话，移动有序表后插入  
            int j= i-1;   
            int x = a[i];        //复制为哨兵，即存储待排序元素  
            a[i] = a[i-1];           //先后移一个元素  
            while(x < a[j]){  //查找在有序表的插入位置  
                a[j+1] = a[j];  
                j--;         //元素后移  
            }  
            a[j+1] = x;      //插入到正确位置  
        }
        print(a,n,i);  
    }  
} 


int main(){
  for(int i = 1;i <= 15; ++i){
    for(int j = i;j <=15; ++j){
      cout<<"A"<<i<<","<<j<<"->";
      for(int k = i;k <= j; ++k){
        cout<<"A"<<i<<","<<k<<"A"<<k<<","<<j;
        if(k < j) cout<<"|";
      }
      cout<<endl;
    }
  }
	return 0;
}
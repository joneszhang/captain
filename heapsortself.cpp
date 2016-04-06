#include <iostream>
using namespace std;

void printArray(int* arry, int size){
	for(int i = 0;i < size; ++i){
		cout<<arry[i]<<",";
	}
	cout<<endl;
}

void maxHeap(int* a, int size, int element){
	int node = element;
	int lleaf = node * 2 + 1;
	int rleaf = lleaf + 1;
	int mindex = 0;
	while(rleaf < size){
		if(a[lleaf] > a[node]) mindex = lleaf;
		else mindex = node;
		if(a[rleaf] > a[mindex]) mindex = rleaf;
		if(node != mindex){
			swap(a[node], a[mindex]);
			node = mindex;
			lleaf = node * 2 + 1;
			rleaf = lleaf + 1;
		}else return;
	}
	if(lleaf < size && a[node] < a[lleaf]){
		swap(a[node], a[lleaf]);
	}
}

void heapSort(int* a, int size){
	for(int i = size / 2 - 1; i >= 0; --i){
		maxHeap(a,size,i);
	}
	while(size > 0){
		swap(a[0], a[size - 1]);
		--size;
		maxHeap(a, size, 0);
	}
}

int main(){
	int a[8]={8,1,2,5,4,3,7,6};
	heapSort(a, 8);
	printArray(a,8);
	return 0;
}
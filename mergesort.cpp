#include <iostream>
using namespace std;

int min(int x, int y){
	return x < y? x : y;
}

void printArray(int* a, int size){
	for(int i = 0;i < size; ++i){
		cout<<a[i];
		if(i + 1 < size) cout<<",";
	}
	cout<<endl;
}

void mergeSort(int* array, int size){
	 int* a = array;
	 int* b = new int[size];
	 for(int seg = 1;seg < size; seg += seg){
	 	for(int start = 0;start < size; start += seg + seg){
	 		int low = start;
	 		int mid = min(start + seg, size);
	 		int end = min(start + 2 * seg, size);
	 		int start1 = low;
	 		int end1 = mid;
	 		int start2 = mid;
	 		int end2 = end;
	 		int k = low;
	 		while(start1 < end1 && start2 < end2)
	 			b[k++] = a[start1] < a[start2]? a[start1++] : a[start2++];
	 		while(start1 < end1){
	 			b[k++] = a[start1++];
	 		}
	 		while(start2 < end2){
	 			b[k++] = a[start2++];
	 		}
	 	}
	 	int* tmp = a;
	 	a = b;
	 	b = tmp;
	 }
	 if (a != array) {
		for (int i = 0; i < size; i++)
			b[i] = a[i];
		b = a;
	}
}

int main(){
	int a[10] = {8,7,9,4,2,3,6,5,1,0};
	int size = 10;
	mergeSort(a, 10);
	printArray(a, 10);

}

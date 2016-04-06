#include <iostream>
using namespace std;

template<typename T> //整數或浮點數皆可使用，若要使用物件（class）時必須設定大於（>）的運算子功能

void shell_sort(T arr[], int len) {
	int gap, i, j;
	T temp;
	for (gap = len >> 1; gap > 0; gap >>= 1)
		for (i = gap; i < len; i++) {
			temp = arr[i];
			for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				arr[j + gap] = arr[j];
			arr[j + gap] = temp;
		}
}

int main(int argc, char* argv[]){
	cout<<argv[1]<<endl;
	int a[5] = {3,1,2,5,4};
	shell_sort(a, 5);
}
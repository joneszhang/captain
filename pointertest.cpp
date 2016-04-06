#include <iostream>
using namespace std;

int main(){
	int a = 1928;
	int* p;
	int* p1 = NULL;
	p = &*&a;
	p1 = &a;
	cout<<p<<endl;
	cout<<p1<<endl;
	return 0;
}
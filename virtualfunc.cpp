#include <iostream>
using namespace std;

class X{
public:
	virtual void print(){
		cout<<"X"<<endl;
	}
};

class Y : public X{
public:
	virtual void print(){
		cout<<"Y"<<endl;
	}
};

class A : public Y{
public:
	virtual void print(){
		cout<<"A"<<endl;
	}
};

class B : public Y{
public:
	void print(){
		cout<<"B"<<endl;
	}
};

int main(int argv, char* argc[]){
	X* x = new A();
	x->print();

}



#include<iostream>
using namespace std;

int main(){
	int a= 10;
	int *ptr = &a;
	
	cout<<"The value of a (a) = "<<a<<endl;
	cout<<"The address of a (&a) = "<<&a<<endl;
	cout<<"The address on the ptr is (ptr) = "<<ptr<<endl;
	cout<<"The value on the ptr address is (*ptr) = "<<*ptr<<endl;
	cout<<"The address on the ptr is (&ptr) = "<<&ptr<<endl;
	
	
	
	return 0;
}
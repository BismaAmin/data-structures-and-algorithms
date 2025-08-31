#include<iostream>
using namespace std;

int main(){
	int a= 10;
	int b =20;
	int *p = &a;
	int *pp = &b;
	
	cout<<"Before swapping : "<<endl;
	cout<<"The value of a = "<<a<<endl;
	cout<<"the address of a = "<<&a<<endl;
	cout<<"The value of b = "<<b<<endl;
	cout<<"the address of a = "<<&b<<endl;
	
	int temp ;
	temp = *p;
	*p= *pp;
	*pp= temp;
	
	cout<<"After swapping : "<<endl;
	cout<<"The value of a = "<<a<<endl;
	cout<<"the address of a = "<<p<<endl;
	cout<<"The value of b = "<<b<<endl;
	cout<<"the address of a = "<<pp<<endl;
}
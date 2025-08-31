#include<iostream>
using namespace std;


void sawping (int x, int y){
	int temp = x;
	x=y;
	y= temp;
}
int main(){
	
	int a, b;
	cout<<"The value of a = ";
	cin>>a;
	cout<<"The value of b = ";
	cin>>b;
	
	cout<<"Now before swaping the value is = "<<endl;
	cout<<" a= "<<a<<endl;
	cout<< " b= "<<b<<endl;
	sawping (a, b);
	
	
	cout<<" after swapping the values are = "<<endl;
	cout<<" a= "<<a<<endl;
	cout<< " b= "<<b<<endl;
	
	return 0;
}

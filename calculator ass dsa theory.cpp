#include<iostream>
#include <cmath>
using namespace std;

class Calculator{
	private:
		Calculator(){
			cout<<"I will not be called";
		}
	public:
	static int operationCount;
	
	static float sum(float a, float b){
	    float sum = a+b;
	    operationCount++;
		return sum;
	}
	static float sub(float a, float b){
		float sub =a-b;
		operationCount++;
		return sub;
	}
	static float quotient (float a, float b){
		if(b==0.0){
			cout<<"The number is zero"<<endl;
			return 0;
		}
		float q = a/b;
		operationCount++;
		return q;
	}
	static float remainder(float a, float b){
		if(b==0.0){
			cout<<"The number is zero"<<endl;
			return 0;
		}
		float r = fmod(a,b);
		operationCount++;
		return r;
	}
	static float percentage(float a, float b){
		if(b==0.0){
			cout<<"The number is zero"<<endl;
			return 0;
		}
		float per = (a/b)*100;
		operationCount++;
		return per;
	}
};

int Calculator::operationCount =0;

int main(){
	//Calculator c;
	
	float x, y;
	cout<<"Enter a number = ";
	cin>>x;
	cout<<"Enter another number = ";
	cin>>y;

	cout<<"The addition of numbers are = "<<Calculator::sum(x,y)<<endl;
	cout<<"The subtraction of numbers are = "<<Calculator::sub(x,y)<<endl;
	cout<<"The qoutient of numbers are = "<<Calculator::quotient(x,y)<<endl;
	cout<<"The remainder of numbers are = "<<Calculator::remainder(x,y)<<endl;
	cout<<"The percentage of numbers are = "<<Calculator::percentage(x,y)<<endl;
			
	cout<<"The operation count = "<<Calculator::operationCount<<endl;
	return 0;
}
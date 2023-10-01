#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"Enter a Number : ";
	cin>>a;
	
	int b=a%2;
	if(b==0){
		cout<<endl<<"Even Number \n";
	}
	else{
		cout<<endl<<"Odd Number \n";
	}
}

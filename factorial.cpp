#include<iostream>
main()
{
	int a,b=0,c=1,i;
	std::cout<<"Enter The Number : "; 
	std::cin>>a;
	
	for(i=0;i<=a-1;i++)
	{
		b=b+1;
		c=c*b;
	}
	std::cout<<c;
}

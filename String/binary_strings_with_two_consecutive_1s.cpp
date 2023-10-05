// C++ program to count all distinct
// binary_strings_with_two_consecutive_1s
#include <iostream>
using namespace std;

// Gives count of n length binary
// strings with consecutive 1's
void countStrings(int n,int ind,string str,int &ans)
{
	if(ind==n){
		int count=0;
		int temp=0;
		for(int i=0;i<n;i++){
			if(str[i]=='1'){
				temp++;
			}else{
				temp=0;
			}
			count=max(count,temp);
		}
		if(count>=2){ans++;}
		return;
	}
	
	countStrings(n,ind+1,str+"0",ans);
	countStrings(n,ind+1,str+"1",ans);
}

// Driver code
int main()
{
	int ans=0;
	countStrings(5,0,"",ans) ;
	cout <<ans<< endl;
	return 0;
}

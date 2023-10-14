// Added solution to a codeforces problem (Div-3) ,this problem involves vector and sorting algorithm


// https://codeforces.com/problemset/problem/1872/B

#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      int d[n],s[n];
      for(int i=0;i<n;i++){
          cin>>d[i]>>s[i];
      }
      vector<int>v;
      for(int i=0;i<n;i++){
          v.push_back(d[i]+(s[i]-1)/2);
          
      }
      sort(v.begin(),v.end());
      cout<<v[0]<<endl;
    }
    
   
 
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    // TC->O(N*maxWeight) | SC->O(N*maxWeight) 
    int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
    {
        vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
        for(int i = weight[0]; i <= maxWeight; i++)
            dp[0][i] = value[0];
        
        for(int idx = 1; idx < n; idx++)
        {
            for(int wt = 0; wt <= maxWeight; wt++)
            {
                int not_take = 0 + dp[idx-1][wt];
                int take = INT_MIN;
                if(weight[idx] <= wt) 
                    take = value[idx] + dp[idx-1][wt-weight[idx]];

                dp[idx][wt] = max(take, not_take);
            }
        }
        return dp[n-1][maxWeight];
    }
   
int main()
 {
        int n, w;
        cin>>n>>w;
        
        vector<int> wt(n);
        vector<int> val(n);
        
        //inserting the values
        for(int i = 0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapsack(wt, val, n, w)<<endl;
        
        return 0;
} 


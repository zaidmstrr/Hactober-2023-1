class Solution {
public:
    int t[3][1001];          //matrix for memoization

    int solve(int e,int f)
    {
        if(f == 0 || f==1)  //base conditon
        {
            return f;
        }
        if(e==1)
        {
            return f;
        }

        if(t[e][f] !=-1)          //if element present in matrix, get from it
        {
            return t[e][f];
        }

        int mn = INT_MAX;          //for answer return 
        int low,high ;

        for(int k=1;k<=f;k++)        //floor 1 to Nth floor
        {
            if(t[e-1][k-1] != -1)           //upto that floor egg will break
            {
                 low = t[e-1][k-1];
            }
            else
            {
                low = solve(e-1,k-1);
                t[e-1][k-1] = low;
            }

            if(t[e][f-k] != -1)        //above the floors from the egg will break
            {
                 high = t[e][f-k];
            }
            else
            {
                high = solve(e,f-k);
                t[e][f-k] = high;
            }

            int temp = 1 + max(low,high);       // max for worst case 
            
            mn = min(mn,temp);      //return the minimun ans;
        }
        
        return t[e][f] = mn;
    }
    int twoEggDrop(int f) {
        memset(t,-1,sizeof(t));

        return solve(2,f);
    }
};

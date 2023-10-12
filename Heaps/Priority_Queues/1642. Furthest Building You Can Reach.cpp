class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int ans=0,sum=0,n=h.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=1;i<n;i++){
            int diff=h[i]-h[i-1];
            if(diff<=0){
                ans=i;
                continue;
            }
            pq.push(diff);
            if(pq.size()>ladders){
               sum+=pq.top();
               pq.pop();
               if(sum>bricks)break;
            }
            ans=i;
        }
        return ans;
    }
};
//link->https://leetcode.com/problems/furthest-building-you-can-reach/
class Solution {
public:
    #define pi pair<int,int>
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,pi>,vector<pair<int,pi>>,greater<pair<int,pi>> >pq;
        int n=mat.size(), m=mat[0].size();
        pq.push({mat[0][0],{0,0}});
        set<pi>vis;
        vis.insert({0,0});
        while(k>1){
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           if(row+1<n && vis.find({row+1,col})==vis.end()){
               pq.push({mat[row+1][col],{row+1,col}});
               vis.insert({row+1,col});
           }
           if(col+1<m && vis.find({row,col+1})==vis.end()){
               pq.push({mat[row][col+1],{row,col+1}});
               vis.insert({row,col+1});
           }
           k--;
        }
        return pq.top().first;
    }
};
//link->https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
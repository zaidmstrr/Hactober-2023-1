class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto itr:mp){
            pq.push({itr.second,itr.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;

    }
};
//link->https://leetcode.com/problems/top-k-frequent-elements/
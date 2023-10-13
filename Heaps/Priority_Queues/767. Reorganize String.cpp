class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto c:s)mp[c]++;
        priority_queue<pair<int,char>>pq;
        for(auto itr:mp)pq.push({itr.second,itr.first});
        auto temp1=pq.top();
        pq.pop();
        string ans="";
        ans+=temp1.second;
        temp1.first--;
        while(!pq.empty()){
            auto temp2=pq.top();
            pq.pop();
            ans+=temp2.second;
            temp2.first--;
            if(temp1.first>0)pq.push(temp1);
            temp1=temp2;
        }
        if(temp1.first>0)return "";
        return ans;
    }
};
//link->https://leetcode.com/problems/reorganize-string/
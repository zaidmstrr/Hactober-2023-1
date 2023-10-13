class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int>st;
        vector<int>v(k);
        int n=nums.size();
        int nums_to_be_removed=n-k;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums_to_be_removed>0 && st.top() > nums[i]){
                st.pop();
                nums_to_be_removed--;
            }
            st.push(nums[i]);
        }
        while(st.size()>k)st.pop();
        for(int i=k-1;i>=0;i--){
            v[i]=st.top();
            st.pop();
        }
        return v;
    }
};
//link->https://leetcode.com/problems/find-the-most-competitive-subsequence/
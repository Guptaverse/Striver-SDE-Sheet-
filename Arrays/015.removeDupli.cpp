// brute force : TC : O(n*logn) , SC : O(N) 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto x:nums) st.insert(x);
        int i =0;
        for(auto x:st){
            nums[i++]=x;
        }
        return st.size();
    }
};

//optimized : 


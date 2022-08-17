// brute force approach TC : O(n*log(n)) SC : O(1);

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());      
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums) m[x]++;
        for(auto x:m){
            if(x.second>nums.size()/2) return x.first;
        }
        return 0;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(auto x:nums) m[x]++;
        for(auto x:m){
            if(x.second>nums.size()/2) return x.first;
        }
        return 0;
    }
};
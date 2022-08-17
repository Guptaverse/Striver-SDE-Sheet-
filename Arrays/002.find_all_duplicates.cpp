// Naive approach !! TC : O(N) , SC : O(N)

// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         map<int,int>m;
//         for(auto x:nums) m[x]++;
//         vector<int>ans;
//         for(auto x:m){
//             if(x.second>1) ans.push_back(x.first);
//         }
//         return ans;
//     }
// };

// optimized approach !! TC : O(N) , SC : O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();++i){
            if(nums[abs(nums[i])-1]>=0)
                nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
            else
                ans.push_back(abs(nums[i])); 
        }
        return ans;
    }
};

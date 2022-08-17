// brute force : TC : O(N*N) , SC : O(1)

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
// 		//Brute Force Solution
//         int len=nums.size();
//         for(int i=0;i<len;i++){
// 			for(int j=i+1;j<len;j++){
//                if(nums[i]+nums[j]==target){
//                    return {i,j};
//                }
//            }
//        } 
//         return {}; 
// 	}
// };

// optimized : TC : O(N), SC : O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>m;
        vector<int> ans = {0};
        for(int i =0;i<nums.size();i++){
            m.insert({nums[i],i});
            if(m.count(target-nums[i]) and m.find(target-nums[i])->second!=i){
                ans = {i,m.find(target-nums[i])->second};
                return ans; 

            }
        }
        return ans;
	}
};
// // Approach 1 : (optimized) : TC O(N), SC : O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct =0,ans=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]) ct++;
            else{
                ans = max(ans,ct);
                ct =0;
            }            
        }
        return max(ans,ct);
    }
};


// Approach 2 : (optimized) : Sliding window : TC O(N), SC : O(1) 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int starting_idx = 0 , ending_idx = 0;
        int ans = 0;
        for(ending_idx = 0; ending_idx<nums.size(); ending_idx++){
            if(nums[ending_idx]==0){
                starting_idx = ending_idx+1;
            }
            else{
                ans = max(ans,ending_idx-starting_idx+1);
            }
        }
        return ans;
    }
};
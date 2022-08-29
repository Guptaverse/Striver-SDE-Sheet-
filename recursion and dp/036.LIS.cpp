/*

nums : 1 5 2 3 4 9 6 10
dp   : 1 2 2 3 4 5 5 6

dp[i] means length of longest increasing subsequence ending at i (including a[i])
j<i && a[j]<a[i] --> dp[i] = max(dp[j]...)+1
*/

//TC : O(N*N) : (standard)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        for(int i =0;i<n;i++){
            dp[i] = 1; // every element can end at length 1
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            
        }
        int ans =0;
        for(int i =0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
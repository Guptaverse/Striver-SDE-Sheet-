class Solution {
public:
    // int flag =0;
    // vector<int>dp(10010,-1);
    int dp[10010];
    int helper(vector<int>&coins,int n){
      if(n==0){
          // flag=1;
          // cout<<"Hi"<<endl;
          return 0;
      }
        //Look up
        if(dp[n]!=-1) return dp[n];
        int ans =INT_MAX;
        for(int x:coins){
            if(n-x>=0){
                // int subprob = helper(coins,n-coins[i],dp);
                ans = min(ans +0LL,helper(coins,n-x)+1LL);
            }
        }
        dp[n]=ans;
        return dp[n];
    }
    int coinChange(vector<int>& coins, int amount) {

        // cout<<flag<<endl;
        memset(dp,-1,sizeof(dp));
        int ans = helper(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};
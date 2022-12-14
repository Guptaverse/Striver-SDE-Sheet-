class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i = dp.size()-2;i>=0;i--){
            for(int j =dp[0].size()-2;j>=0;j--){
                char c1 = text1[i];
                char c2 = text2[j];
                
                if(c1 == c2){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        
    }
};
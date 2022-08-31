class Solution {
public:
    int dp[101][101][601];
    int ct(string s){
        int ans =0;
        for(auto x:s) 
            if(x=='0') ans++;
        return ans;
    }
    int helper(vector<string>&strs,int m,int n,int idx){
        if(idx == strs.size()) return 0;
        if(dp[m][n][idx]!=-1) return dp[m][n][idx];
        int ct0=ct(strs[idx]);
        int ct1 = strs[idx].size()-ct0;
        if(m-ct0>=0 && n-ct1>=0){
            return dp[m][n][idx] = max(1+helper(strs,m-ct0,n-ct1,idx+1),helper(strs,m,n,idx+1));
        }
        return dp[m][n][idx] = helper(strs,m,n,idx+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
         memset(dp,-1,sizeof(dp));
         return helper(strs,m,n,0);
    }
};
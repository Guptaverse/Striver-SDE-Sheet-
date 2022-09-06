#include<bits/stdc++.h>
using namespace std;


bool isSubset(vector<int>v,int n, int sum){

    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));

    for(int i =0;i<n+1;i++){
        dp[i][0]=true;
    }

    for(int i =1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1]>j) dp[i][j]=dp[i-1][j];
            else if(v[i-1]<=j) dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
        }
    }
    return dp[n][sum];
}

int main(){

    vector<int>v = {1,5,3,11};
    int total =0;
    for(auto x:v) total +=x;

    cout<<(total&1?false:isSubset(v,v.size(),total/2)); 
    return 0;
}

class Solution
{
    unordered_map<int,int>dp;
    unordered_set<string>st;//dictionary
    int partition(string s,int pos){
        if(pos==s.size()) return 1;
        if(dp.count(pos)) return dp[pos];
        string t="";
        for(int i=pos;i<s.size();++i){
            if(st.count(s.substr(pos,i-pos+1)) && partition(s,i+1)) return dp[pos] = 1;
        }
        return dp[pos] = 0;
    }   
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        for(auto x: B) st.insert(x);
        return partition(A,0);
    }
};
// brute force : TC: O(N) , SC : O(N)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    vector<int>exist(n+1);
    for(int i = 0;i<n;i++){
        exist[A[i]]++;
    }
    int a,b;
    for(int i =1;i<n+1;i++){
        if(exist[i]==0) b =i;
        else if(exist[i]>=2) a = i;
    }
    return {a,b};
    
}
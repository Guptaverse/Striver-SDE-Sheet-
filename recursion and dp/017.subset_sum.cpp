
// brute force : O(2^N + nlogn) , SC :O(N)

class Solution
{
public:
    void helper(vector<int>arr, int N , vector<int>& ans,int idx,int sum){
        if(idx==N){
            ans.push_back(sum);
            return;
        }
        //including 
        helper(arr,N,ans,idx+1,sum+arr[idx]);
        // not including
        helper(arr,N,ans,idx+1,sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>subsets;
        helper(arr,N,subsets,0,0);
        sort(subsets.begin(),subsets.end());
        return subsets;
    }
};

// Naive : iterative : O(N*2^N) , SC : O(1)

class Solution
{
public:
    vector<int>ans;
    void helper(vector<int> arr, int n)
    {
        // There are total 2^n subsets
        long long total = 1 << n;
     
        // Consider all numbers from 0 to 2^n - 1
        for (long long i = 0; i < total; i++) {
            long long sum = 0;
     
            // Consider binary representation of
            // current i to decide which elements
            // to pick.
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    sum += arr[j];
     
            // Print sum of picked elements.
            ans.push_back(sum);
        }
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        helper(arr,N);
        return ans;
    }
};
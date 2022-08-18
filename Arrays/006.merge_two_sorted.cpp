brute force : TC: O(N*LogN +N) , SC : O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {   
       int size1=nums1.size()-1;
       for(int i=0;i<nums2.size();i++)
       {
           nums1[size1]=nums2[i];
           size1--;
       }
       sort(nums1.begin(),nums1.end());
    }
};

optimized : TC: O(n) , SC : O(1)

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int ptr1 = m-1,ptr2 = n-1;
        int i = m+n-1;
        while(ptr2>=0){
            if(ptr1>=0 && a[ptr1]>b[ptr2]){
                a[i--]=a[ptr1--];
            }
            else{
                a[i--] = b[ptr2--];
            }
        }
    }
};



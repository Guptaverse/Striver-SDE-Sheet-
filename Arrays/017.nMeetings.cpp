// optimized : TC : O(nlogn) , SC :O(n)

class Solution
{
    // cusmtom comparator to sort 
    static bool myCmp(pair<int,int>a , pair<int,int>b){
       if(a.second==b.second)
       return (a.first<b.first);
       return (a.second<b.second);
   }
   public:
   int maxMeetings(int start[], int end[], int n)
   {
       // Your code here
       vector<pair<int,int>>v;
       for(int i=0; i<n; i++)
           v.push_back({start[i],end[i]});
           
       sort(v.begin(),v.end(),myCmp);
       
       int prev = v[0].second, res = 1;
       for(int i=1; i<n; i++){
           if(v[i].first > prev){
               res ++;
               prev = v[i].second;
           }
       }
       return res;
    }
};
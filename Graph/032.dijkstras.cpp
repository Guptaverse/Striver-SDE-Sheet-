// Guide to Dijkstra's Algo (Easy explaination ever!!)
//https://leetcode.com/discuss/general-discussion/1059477/A-noob's-guide-to-Djikstra's-Algorithm


////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                               Coded by Shivam Gupta :)                             //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define mod 1e9+7
#define ip(a) for(int i=0;i<a.size();i++){ cin >> a[i];}
#define op(a) for(int i=0;i<a.size();i++){ cout <<  a[i] << " ";}
#define setp(n,val) cout << setprecision(n) << fixed << val
#define pb push_back
#define Fast_chalane_ke_liye ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define f1 first
#define sec second
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vpii;
typedef map<int,int> mii;
typedef unordered_map<ll,ll> omll;
typedef unordered_map<int,int> omii;




void solver(){

    int n,m;
    cin>>n>>m;
    vpii g[n+1];

    int u,v,wt;
    for(int i =0;i<m;i++){
        cin>>u>>v>>wt;
        g[u].pb({v,wt});
        g[v].pb({u,wt});
    }

    int src;
    cin>>src;
    priority_queue<pii,vpii,greater<pii>>pq;

    vi Dist(n+1,INT_MAX);

    Dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        auto itr = pq.top();
        int dist = itr.first;
        int prev = itr.second;
        pq.pop();

        vpii :: iterator it;

        for(it = g[prev].begin();it!=g[prev].end();it++){
            int next = it->first;
            int nextDist = it->second;
            if(Dist[next]>Dist[prev]+nextDist){
                Dist[next]=Dist[prev]+nextDist;
                pq.push({Dist[next],next});
            }
        }
    }

    cout<<"The distance from the source ,"<<src<<",are : "<<endl;
    for(int i =1;i<=n;i++){
        cout<<Dist[i]<<" ";
    }
    cout<<endl;

}




int main(){
    Fast_chalane_ke_liye;
    int testcase;
    cin>>testcase;
    while(testcase--){
        solver();
    }
    return 0;
}

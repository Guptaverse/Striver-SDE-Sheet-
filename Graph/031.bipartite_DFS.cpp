

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

// TC : O(V+E) , SC : O(V+E) + O(N) + O(N)

bool dfs(int sv, vi adj[], vi &color) {
    for(auto child : adj[sv]) {
        if(color[child] == -1) {
            color[child] = 1 - color[sv];
            if(!dfs(child, adj, color)) {
                return false; 
            }
        } else if(color[child] == color[sv]) return false; 
    }
    return true; 
}
bool isBipartite(vi adj[], int n) {
    vi color(n,-1);

    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!dfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}


void solver(){

    int n,m;
    cin>>n>>m;

    vi adj[n];
    for(int i =0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cout<<(isBipartite(adj,n)?"YES":"NO")<<endl;


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

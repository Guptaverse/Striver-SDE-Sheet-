#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> movements = {
    {-1,0},{0,1},{1,0},{0,-1},{-1,1},
    {-1,-1},{1,-1},{1,1}
};

void dfs(int i,int j,int n,int m,int** arr){
    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(arr[i][j]==0) return;
    arr[i][j]=0;

    // using movements vector to move in 8 directions
    for(auto it : movements){
        int x = i + it.first;
        int y = j + it.second;
        dfs(x,y,n,m,arr);
    }

    // better not to use it :)

    // dfs(i-1 , j , n , m , arr);
    // dfs(i+1 , j , n , m , arr);
    // dfs(i , j-1 , n , m , arr);
    // dfs(i , j+1 , n , m , arr);
    // dfs(i-1 , j-1 , n , m , arr);
    // dfs(i+1 , j+1 , n , m , arr);
    // dfs(i-1 , j+1 , n , m , arr);
    // dfs(i+1 , j-1 , n , m , arr);
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    
    int ct = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(arr[i][j]==1){
                dfs(i , j , n , m , arr);
                ct++;
            }
        }
    }
    return ct;   
}

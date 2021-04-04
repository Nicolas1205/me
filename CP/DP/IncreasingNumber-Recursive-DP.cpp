#include<bits/stdc++.h>

using namespace std; 


vector<vector<int>> dp(200, vector<int> (200 , -1 ));

 vector<vector<int>> dp;
    int n , m; 
int dfs(vector<vector<int>> &a ,int i ,int j ){
  if(i < 0 || i >= n || j < 0 || j >= m ){
    return 0;
  }
  if(dp[i][j] != -1) {
    return dp[i][j]; 
  }
  int v = a[i][j];
  int x , y  , z ,  w ;
  x  =  y =  z  =  w = 0 ;
  if(i < n-1 && v > a[i+1][j] ){
     x = dfs(a , i+1 , j); 
  }
  if(i > 0 && v  > a[i-1][j]   ){
    y = dfs(a , i-1 , j);
  }
  if(j  < m-1 && v > a[i][j+1] ){
    z = dfs(a , i , j+1);
  }
  if( j > 0 && v > a[i][j-1] ){
    w = dfs(a , i , j-1);
  }
  return dp[i][j]  = max({x  , y , z , w   })+1;
}

    int longestIncreasingPath(vector<vector<int>>& a) {
        n = a.size()  , m  = a[0].size();
  int ans = -1; 
    dp = vector<vector<int>> (201  , vector<int> (201 , -1));
  for(int i =0 ;i <n; i++) {
    for(int j =0 ; j < m ; j++){ 
      if(dp[i][j] == -1) {
        ans = max(ans , dfs(a , i , j ));
      }
    }
  }
  return ans; 

    }


int main(){ 
  ios::sync_with_stdio(0); 
  std::cin.tie(0);
  int tt; cin>>tt; 
  while(tt--){
    cin>>n>>m;
    vector<vector<int>> a(n , vector<int> (m));
    for(int i =0 ;i < n; i++){
      for(int j = 0 ; j < m ; j++){
        int k; cin>>k; 
        a[i][j] = k ; 
      }
    }
    printf("%d" , solve(a));
  }
  return 0;
}


#include<bits/stdc++.h>

using namespace std; 

int solve(vector<int> &a ){
  int ans,n = a.size();
  vector<vector<int>> dp(n , vector<int> (n , 0));
  
  for(int len =1 ; len <= n  ; len++){ 
    for(int i = 0 ;i <= n - len ; i++){
      int j = len - i - 1; 
      for(int k = i ;  k <= j ; k++){
        int r = 1, l = 1; 
        if(i != 0) l = a[i-1];
        if(j != 0 ) r = a[j+1];
        int bef  , af; 
        if(i != k ) bef = dp[i][k-1]; 
        if(j != k) af = dp[k+1][j];
        
        dp[i][j] = max(dp[i][j] , af + bef + l * a[k] * r); 
      }
    }
  }
  return ans = dp[0][n-1];
}
int main(){
  vector<int> a;
  int n; 
  for(int i =0 ; i < n ; i++){ 
    int k; cin>>k; 
    a.push_back(k);
  }
  cout<<solve(a);
  return 0; 

}

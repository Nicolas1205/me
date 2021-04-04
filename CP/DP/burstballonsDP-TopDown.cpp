#include<bits/stdc++.h>

using namespace std;

map<vector<int> , int> dp;
int ans = 0; 
int maxv =0 ; 
int solve(vector<int> &a){
  if(dp.count(a)){
    return dp.at(a);
  }
  int maxv = 0; 
  for(int i  =0 ; i < a.size();  i++ ){
    int v = a[i];  
    if(i+1 < a.size()) {
      v *=  a[i+1];
    }
    if(i-1 <= 0){
      v *= a[i-1];
    }
    vector<int> na = a; 
    na.erase(na.begin()+1);
    maxv = max(maxv, solve(na) + v);
  }
  dp[a]  = maxv;
  return maxv; 
}

int main(){
  int n ; cin>>n;
  vector<int> a(n);
  for(int i=0 ;i < n ; i++){
    int k ; cin>>k; 
    a[i] = k; 
  }
  cout<<solve(a);
  return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll= long long;
ll solve(int n,int w,vector<ll>&wt,vector<ll>&val,vector<vector<ll>>&dp){
    if(w==0||n>=wt.size())return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    int pick=-1e9;
    int skip=-1e9;
    if(w>=wt[n]){
        pick=val[n]+solve(n+1,w-wt[n],wt,val,dp);
    }
    skip=solve(n+1,w,wt,val,dp);
    dp[n][w]=max(pick,skip);
    return dp[n][w];
}
int main(){
    ll n;
    cin>>n;
    ll w;
    cin>>w;
    vector<ll> wt(n);
    vector<ll> val(n);
    for(ll i=0;i<n;i++){
        cin>>wt[i];
    }
    for(ll i=0;i<n;i++){
        cin>>val[i];
    }
    vector<vector<ll>>dp(n+1,vector<ll>(w+1,-1));
     cout << "Maximum value = "<< solve(0, w, wt, val, dp) << endl;
    return 0;
}

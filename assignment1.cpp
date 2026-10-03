#include<bits/stdc++.h>
using namespace std;
using ll= long long;
ll fibor(ll n){
    if(n==0)return 0;
    if(n==1)return 1;
    return fibor(n-1)+fibor(n-2);
}
ll fiboi(ll n){
    if(n==0)return 0;
    ll a=0;
    ll b=1;
    for(ll i=0;i<=n-2;i++){
        ll c=a+b;
        a=b;
        b=c;
    }
    return b;
} 
int main(){
    cout<<"Enter the fibo number"<<endl;
    ll n;
    cin>>n;
    if(n<0){
        cout<<"Invalid input"<<endl;
        return 0;
    }
    cout<<"Iterative:"<<fiboi(n)<<endl;
    cout<<"Recursive: "<<fibor(n)<<endl;
    return 0;
}

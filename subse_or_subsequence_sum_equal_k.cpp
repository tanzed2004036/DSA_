#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;
int dp[N][N];
int n;
int a[N];

bool fun(int i,int k){
    if(k==0)return true;
    if(i<0)return false;
    if(dp[i][k]!=-1) return dp[i][k];
    // not take 
    bool is=fun(i-1,k);
    if(k-a[i]>=0)
        is = is || fun(i-1,k-a[i]);

    return dp[i][k]=is;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    bool ans=fun(n-1,k);
    if(ans)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

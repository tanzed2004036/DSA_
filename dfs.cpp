#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int> grp[N];
int vis[N]={0};

void dfs(int node)
{
    cout<<node<<" ";
    vis[node]=1;
    for(auto child:grp[node]){
        if(vis[child])continue;
        dfs(child);
    }
}

int main()
{
    int node,edge;cin>>node>>edge;
    for(int i=1;i<=edge;i++){
        int u,v;cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    // dfs(1);

    // Traverse all nodes to handle disconnected components
    for (int i = 1; i <= node; i++) {
        if (!vis[i]) {
            cout << "Component: ";
            dfs(i);
            cout << endl;
        }
    }
}
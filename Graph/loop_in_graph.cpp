#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> grp[N];
int vis[N] = {0};

// 🧠 Core Logic (Undirected Graph)
// DFS চলাকালীন:একটা node থেকে child এ যাও যদি child আগেই visited হয় এবং সে child যদি parent না হয় ➡️ তাহলে loop আছে

bool dfs(int node, int parent)
{
    vis[node] = 1; // mark current node as visited

    for (auto child : grp[node])
    {

        // If child is parent, ignore it
        if (child == parent)
            continue;

        // If child is already visited and not parent -> cycle found
        if (vis[child])
            return true;

        // Visit unvisited child
        //  child node থেকে DFS শুরু করলাম যদি child-এর ভেতরের কোনো জায়গায় loop পাওয়া যায় তাহলে আমার (current node) দিক দিয়েও loop আছে তাই সাথে সাথে true return করি
        if (dfs(child, node))
            return true;
        
    }
    return false; // no cycle from this path
}

int main()
{
    int node, edge;
    cin >> node >> edge;
    for (int i = 1; i <= edge; i++)
    {
        int u, v;
        cin >> u >> v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }

    // handle disconnected components
    bool isLoopExist = false;
    for (int i = 1; i <= node; i++)
    {
        if (vis[i])
            continue;
        if (dfs(i, -1))
        {
            isLoopExist = true;
            break;
        }
    }
    if (isLoopExist)
        cout << "Loop exists \n";
    else
        cout << "No loop \n";
}
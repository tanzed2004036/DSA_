#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int graph1[N][N];
int graph4[N][N];
vector<int> graph2[N];
vector<pair<int, int>> graph3[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;

        // unweighted graph
        cin >> v1 >> v2;
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);

        // weighted graph
        cin >> wt;
        graph3[v1].push_back({v2, wt});
        graph3[v2].push_back({v1, wt});
        graph4[v1][v2] = wt;
        graph4[v2][v1] = wt;
    }
    // adjacency matrix representation
    //  space complexity O(N^2)
    //  N = 10^5

    // adjacency list representation
    //  space complexity O(N + M)

    // ---- i,j connected or not ----   i,j er weight ki ----
    int i, j;
    cin >> i >> j;

    // matrix
    if (graph1[i][j] == 1){
        cout << "connected\n";
    }
    else{
        cout << "not connected\n";
    }
    cout << "weight: " << graph4[i][j] << "\n";

    // list
    for(int child: graph2[i]){
        if(child == j){
            cout << "connected\n";
            break;
        }
    }

    for(pair<int,int> child: graph3[i]){
        if(child.first == j){
            cout << "weight: " << child.second << "\n";
            break;
        }
    }
}

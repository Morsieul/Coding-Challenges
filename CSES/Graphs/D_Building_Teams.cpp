/*
O problema trata basicamente sobre como lidar com um grafo bipartido(As vértices podem ser separadas em dois grafos diferentes).

*/

#include<bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 1;

int M, N,a, b;

bool possible = 0;

bool vis[maxN], team[maxN];
vector<int> grafo[maxN];

void DepthFirstSearch(int p, int q = 0) {

    for(int k : grafo[p]) {
        if(k != q) {
                if(!vis[k]){
                team[k] = !team[p];
                vis[k] = true;
                DepthFirstSearch(k, p);
            } else
                if(team[k] == team[p])
                    possible = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    possible = true;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            vis[i] = true;
            DepthFirstSearch(i);
        }
    }

    if(!possible)
        printf("IMPOSSIBLE\n");
    else
        for(int i = 1; i <= N; i++)
            cout << (team[i] ? 1 : 2) << endl;

}
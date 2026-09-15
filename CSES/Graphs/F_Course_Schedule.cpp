/*
Topological sorting using Kahn's algorithm(BFS).

L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edge

while S is not empty do
    remove a node n from S
    add n to L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S

if graph has edges then
    return error   (graph has at least one cycle)
else 
    return L   (a topologically sorted order)
*/

#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, a, b, cnt, in[maxN];
vector<int> ans, grafo[maxN];
queue<int> Q;

int main(){
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        grafo[a].push_back(b);
        in[b]++;
    }

    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    cnt = N;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        ans.push_back(u);
        cnt--;

        for(int v : grafo[u]){
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    if(cnt)
        cout << ("IMPOSSIBLE\n");
    else
        for(int i = 0; i < N; i++)
            cout << ans[i] << endl;
}
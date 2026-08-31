#include<bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int maxw = 100010;
const int INF = maxn * maxw;

int weight[maxn];
int value[maxn];
int dp[maxn][maxw];

int n, w;

int solve(int i, int cap) {
    if(cap < 0) return -INF;
    if(i == n) return 0;
    if (dp[i][cap] != -1) return dp[i][cap];

    int colocar = value[i] + solve(i + 1, cap - weight[i]);
    int n_colocar = solve(i + 1, cap);

    return dp[i][cap] = max(colocar, n_colocar);
}

int main() {
    cin >> n >> w;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= w; j++) dp[i][j] = -1;
    }
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << solve(0, w) << endl;
 
}
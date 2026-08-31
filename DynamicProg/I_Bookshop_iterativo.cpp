#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;          // número máximo de itens
const int MAXW = 100010;        // capacidade máxima da mochila

int weight[MAXN];
int value[MAXN];
int dp[MAXN + 1][MAXW];      // +1 para facilitar o caso base (i = n)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    for (int i = 0; i < n; ++i)   cin >> weight[i];
    for (int i = 0; i < n; ++i)   cin >> value[i];

    /* ---------------------------------------------------------
       Inicialização:
      dp[n][c] = 0 para toda capacidade c (nenhum item restante).
       --------------------------------------------------------- */
    for (int c = 0; c <= W; ++c) dp[n][c] = 0;

    /* ---------------------------------------------------------
       Preenchimento da tabela de baixo para cima.
       Para cada posição i (de n‑1 até 0) calculamos o melhor valor
       possível para todas as capacidades c (de 0 até W).
       ----------------------------------------------------- */
    for (int i = n - 1; i >= 0; --i) {
        for (int c = 0; c <= W; ++c) {
            // opção 1: não pegar o item i
            int best = dp[i + 1][c];

            // opção 2: pegar o item i (se couber)
            if (c >= weight[i]) {
                best = max(best, value[i] + dp[i + 1][c - weight[i]]);
            }
            dp[i][c] = best;
        }
    }

    cout << dp[0][W] << '\n';
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int n, w;

const int MAXN = 1010;          // número máximo de itens
const int MAXW = 100010;        // capacidade máxima da mochila

int weight[MAXN];
int value[MAXN];
int dp[MAXN + 1][MAXW];      // +1 para facilitar o caso base (i = n)

long long solve(int books, int weight_limit, const vector<int>& price, const vector<int>& pages) {

    vector<long long> dp(weight_limit + 1, 0);   
    
    for(int i = 0; i < books; ++i) {
        for(int cost = weight_limit; cost >= price[i]; --cost) {
            dp[cost] = max(dp[cost], static_cast<long long> (pages[i]) + dp[cost - price[i]]);
        }
    }

    return dp[weight_limit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    vector<int> weight(n);
    vector<int> value(n);

    for(int i = 0; i < n; i++) {
        cin >> value[i];
        cin >> weight[i];
    }

    cout << solve(n, w, value, weight) << endl;

}

*/

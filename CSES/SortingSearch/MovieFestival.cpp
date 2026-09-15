#include <bits/stdc++.h>

using namespace std;

int main() {
    // Otimização de I/O para o CSES (evita TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Vetor de pares: {fim, inicio}
    vector<pair<int, int>> filmes(n);
    for(int i = 0; i < n; i++) {
        cin >> filmes[i].second >> filmes[i].first; // .second = início, .first = fim
    }

    // Ordena os filmes pelo horário de término mais cedo
    sort(filmes.begin(), filmes.end());

    int qts_filmes = 0;
    int ultimo_fim = 0;

    // Varre os filmes organizados
    for(int i = 0; i < n; i++) {
        // Se o filme atual começa no mesmo momento ou após o término do último filme assistido
        if(filmes[i].second >= ultimo_fim) {
            qts_filmes++;
            ultimo_fim = filmes[i].first; // Atualiza o horário que o último filme acabou
        }
    }

    cout << qts_filmes << "\n";

    return 0;
}
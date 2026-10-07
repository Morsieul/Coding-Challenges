#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int MOD = 1000000007;
const int MAXN = 1000000; // Maior valor possível para N_i

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 1. Pré-computar os fatoriais de 0 até 10^6
    vector<ll> fat(MAXN + 1);
    fat[0] = 1;
    
    for (int i = 1; i <= MAXN; i++) {
        fat[i] = (fat[i - 1] * i) % MOD;
    }
    
    int Q;
    if (!(cin >> Q)) return 0;
    
    // 2. Responder a cada consulta em O(1)
    for (int i = 0; i < Q; i++) {
        int n;
        cin >> n;
        cout << fat[n] << " ";
    }
    cout << "\n";

    return 0;
}
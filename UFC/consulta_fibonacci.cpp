#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const int MOD = 1000000007;
const int MAXN = 1000000; // O maior N_i possível é 10^6

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Pré-computar a sequência de Fibonacci até 10^6 de forma iterativa
    vector<ll> fib(MAXN + 1);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    int Q;
    if (!(cin >> Q)) return 0;

    // Responder a cada consulta em O(1)
    for (int i = 0; i < Q; i++) {
        int n;
        cin >> n;
        cout << fib[n] << "\n"; // Usar "\n" é mais rápido que endl
    }

    return 0;
}
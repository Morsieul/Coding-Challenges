#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000000;

int dp[maxn];

vector<int> separa_digitos(int n) {
    
    int aux = n;

    vector<int> digits;


    while(aux > 0) {

        digits.push_back(aux % 10);
        aux = aux / 10;
        
    }

    return digits;
}

int RemovingDigits(int n) {

    if(n == 0) return 0;

    if(n <= 9) return 1;

    if(dp[n] != -1 ) return dp[n];

    int resultado = INT_MAX - 100;

    for(int d: separa_digitos(n)) {
        if(d != 0) {
            resultado = min(resultado, 1 + RemovingDigits(n - d));
        }
    }
    dp[n] = resultado;
    return resultado;
}

int main(){

    int n;
    cin >> n;

    for(int i = 0 ; i <= n; i++) {
        dp[i] = -1;
    }

    cout << RemovingDigits(n) << endl;

}
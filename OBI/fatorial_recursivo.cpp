#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll fatorial(ll n) {
    
    if(n <= 1) return 1;
    
    return (n * fatorial(n - 1)) % 1000000007;
    
}

int main() {
    ll n;
    
    cin >> n;
    
    cout << fatorial(n);
}
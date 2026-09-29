// problema da codeforces: https://codeforces.com/problemset/problem/1858/A

#include <bits/stdc++.h>

using namespace std;

using ll = long long ;
int main() {
    int t;
    
    cin >> t; 
    
    while( t > 0) {
        ll a, b, c;
        
        cin >> a >> b >> c;
        
        /*
        Como Anna e Katie compartilham apenas os botões c e Anna começa primeiro,
        sua vantagem está em conseguir apertar mais botões c antes que Katie tenha qualquer chance.
        Se a quantidade de botões c for ímpar, Anna vence por conseguir apertar um botão a mais que Katie.
        */ 
        
        if(a + (c % 2) > b) {
            cout <<"First" << endl;
        }else cout << "Second" << endl;
        t--;
    }
}
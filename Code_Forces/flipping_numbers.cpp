#include<bits/stdc++.h>

using namespace std;

int Kadane(vector<int> v) {
    
    int max_gain = -1; // Começa com -1 para garantir que pelo menos um elemento seja escolhido se houver zeros
    int current_gain = 0;
    
    // atualizar a posição da contagem apenas quando chegar em 1. i.e aumentar a soma.
    for(int i = 0; i < (int) v.size(); i++) {

        int val = (v[i] == 0) ? 1 : -1;
        
        current_gain += val;
        if (current_gain > max_gain) {
            max_gain = current_gain;
        }
        if (current_gain < 0) {
            current_gain = 0;
        }
    }
    
    return max_gain;
    
}

int main() {
    int n;
    
    cin >> n;
    
    vector<int> seq(n);
    
    int total_1s = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
        if (seq[i] == 1) {
            total_1s++;
        }
    }
    
    if (total_1s == n) {
        cout << n - 1 << "\n";
    } else {
        cout << total_1s + Kadane(seq) << "\n";
    }
}
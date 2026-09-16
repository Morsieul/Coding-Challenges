#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, limite;
    
    cin >> n >> limite;
    
    vector<int> a;
    
    for(int i = 0; i < n; i++) {
        int at = 0;
        
        cin >> at; 
        
        a.push_back(at);
    }
    
    sort(a.begin(), a.end());
    
    int aprender = 0, tempo = 0;

    
    for(int i = 0; i < n; i++) {
        tempo = tempo + a[i];
        if(tempo <= limite) {
            aprender++;
        }else break;
    }
    
    cout << aprender;
    
}
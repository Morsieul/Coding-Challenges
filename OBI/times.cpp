#include <bits/stdc++.h> 

using namespace std;

int main() {
    int alunos, n_times;
    
    cin >> alunos >> n_times;
    
    vector<pair<int, string>> jogadores;
    
    for(int i = 0; i < alunos; i ++) {
        int skill;
        string nome;
        cin >> nome >> skill;
        
        jogadores.push_back({skill, nome});
    }
    
    sort(jogadores.begin(), jogadores.end()); 
    
    reverse(jogadores.begin(), jogadores.end());
    
    vector<string> times[n_times];

    for(int j = 0; j < alunos; j ++) {
        times[j % n_times].push_back(jogadores[j].second);
    }
    
    for(int i = 0; i < n_times; i ++) {
        cout << "Time " << i + 1 << endl;
            sort(times[i].begin(), times[i].end());
            for(int j = 0; j < times[i].size(); j++) cout << times[i][j] << endl;
        cout << endl;
    }
    
}
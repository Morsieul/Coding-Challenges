#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> minimalCover(vector<pair<int,int>> coordenadas, int m) {
    vector<pair<int,int>> intervals = coordenadas;          // Cópia
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { // Lumo corrigiu isso, pois o jeito que tinha feito tava errado.
             if (a.first != b.first) return a.first < b.first;
             return a.second > b.second;            // Mais longe primeiro.
         });

    vector<pair<int,int>> answer;  // Intervalos para cobrir o buraco.
    int posicao = 0;          // Ponto mais distante de até onde foi visto. 
    size_t i = 0;         // Índice que irá percorrer o vetor de pontos ordenados
    const size_t n = intervals.size();

    while (posicao < m) {
        int furthest = posicao;                     // Inicia-se o mais longe com a posição inicial.
        pair<int,int> best{-1,-1};

        // Verifica-se todos os intervalos menores ou iguais ao de posição.
        while (i < n && intervals[i].first <= posicao) {
            if (intervals[i].second > furthest) {
                furthest = intervals[i].second;
                best = intervals[i];
            }
            ++i;
        }

        // Caso não seja haja um intervalo viável.
        if (furthest == posicao) return {};

        // Se um intervalo passou pelos critérios, o contador incrementa.
        answer.push_back(best);
        posicao = furthest;                         // Atualiza a posição.
    }

    return answer;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; // número de intervalos que serão disponibilizados.
    cin >> t;


    for(int i = 0 ; i < t; ++i) {
        int m; // Tamanho máximo do espaço a ser preenchido. [0 - M]

        cin >> m;

        vector<pair<int,int>> coordenadas;

        while (true) {
                int L, R;
                cin >> L >> R;               // read a pair

                if (L == 0 && R == 0)        // sentinel – end of this test case
                    break;

                if (L > R) std::swap(L, R);


                if (R < 0 || L > m) continue;

                L = max(L, 0);
                R = min(R, m);

                coordenadas.emplace_back(L, R);
            }

        vector<pair<int,int>> cover = minimalCover(coordenadas, m);

        if (cover.empty()) {
            cout << 0 << "\n";
        } else {
            cout << cover.size() << "\n";
            for (auto &p : cover)
                cout << p.first << ' ' << p.second << "\n";
        }

        if (i + 1 != t) cout << "\n";
 
    }

}

/*

struct Seg {
    long long L, R;
    bool operator<(Seg const& other) const {
        return L < other.L || (L == other.L && R > other.R);
    }
};

int minimalCover(vector<Seg> segs, long long M) {
    sort(segs.begin(), segs.end());          // O(N log N)

    long long pos = 0;                       // already covered up to here
    int used = 0;
    size_t i = 0;

    while (pos < M) {
        long long far = pos;                 // farthest reachable in this step
        // examine all intervals that start at or before 'pos'
        while (i < segs.size() && segs[i].L <= pos) {
            far = max(far, segs[i].R);
            ++i;
        }
        if (far == pos)                      // nothing extends coverage
            return -1;                        // impossible
        ++used;
        pos = far;                            // extend covered prefix
    }
    return used;
}

*/


/*
If you truly want to use a set instead of the plain vector+index, replace the inner while loop with something like:

auto it = intervals.lower_bound({pos+1, -INF}); // first with L > pos
for (auto jt = intervals.begin(); jt != it; ++jt)
    far = max(far, jt->R);
intervals.erase(intervals.begin(), it); // discard examined intervals
*/
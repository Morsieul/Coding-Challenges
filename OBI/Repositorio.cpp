#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de entrada e saída para maior velocidade
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    // C = quantidade de programas instalados
    // N = quantidade de versões disponíveis na internet
    if (!(cin >> C >> N)) return 0;

    map<int, int> instalado;
    map<int, int> internet;

    // 1. Lendo os programas instalados nos computadores
    for (int i = 0; i < C; i++) {
        int pc, vc;
        cin >> pc >> vc;
        instalado[pc] = vc;
    }

    // 2. Lendo os programas disponíveis na internet
    for (int i = 0; i < N; i++) {
        int pn, vn;
        cin >> pn >> vn;
        
        // Se o programa já estiver no map da internet, mantemos a maior versão
        if (internet.find(pn) == internet.end()) {
            internet[pn] = vn;
        } else {
            internet[pn] = max(internet[pn], vn);
        }
    }

    // 3. Verificando quais programas devem ser instalados/atualizados
    // O map já percorre os elementos ordenados pela chave (número do programa)
    for (auto const& [programa, versao_web] : internet) {
        // Condição: O programa não está instalado OU a versão da web é mais recente
        if (instalado.find(programa) == instalado.end() || versao_web > instalado[programa]) {
            cout << programa << " " << versao_web << "\n";
        }
    }

    return 0;
}
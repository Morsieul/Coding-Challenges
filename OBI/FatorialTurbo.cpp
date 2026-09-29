// fonte: https://maratona.sbc.org.br/hist/2017/vagas17.html

#include <iostream>
#include <vector>

using namespace std;

int fatorial(int n) {
    
    if(n <= 1) return 1;
    
    return (n * fatorial(n - 1));
    
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Pré-calculando os fatoriais necessários
    // Para essa questão, inicialmente planejei fazer usando uma busca binária testando soma de valores até encontrar nosso limite N
    // Porém percebi que essa abordagem não funcionaria, já que logo nos exemplos mostra-se que é possível usar mais de um mesmo fatorial para obter a resposta
    // Estudando a questão e procurando por problemas semelhantes, aprendi sobre a estratégia de pré-calcular os valores de fatoriais e usar um algoritmo guloso
    // para encontrar a melhor combinação. 
    // Usei a função fatorial(int n) de uma questão anterior. 
    // Como N <= 10^5, o maior fatorial necessário é 8! = 40320 (9! = 362880 passa de N)
    vector<int> fatoriais;
    int fat = 1;
    
    for(int i = 0; fat <= 100000; i++) {
        fat = fatorial(i);
        fatoriais.push_back(fat);
    }

    int N;
    if (!(cin >> N)) return 0;

    int k = 0;

    // Percorrendo os fatoriais do maior para o menor
    for (int j = fatoriais.size() - 1; j >= 0; j--) {
        while (N >= fatoriais[j]) {
            N -= fatoriais[j];
            k++;
        }
    }

    cout << k << "\n";

    return 0;
}
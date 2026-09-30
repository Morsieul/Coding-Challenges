// fonte: https://olimpiada.ic.unicamp.br/passadas/OBI2008/fase1/programacao/
#include<bits/stdc++.h>
#define maxn 100002
using namespace std;

int n, m, a[maxn], b[maxn], p[maxn];

/*
Como temos um valor correspondente de prêmio para cada faixa de força, basta 
buscar eficientemente a posição que corresponde ao que cada ogro conseguiu 
produzir com sua bancada. Para isso foi feito uma rápida busca binária
comparando os valores obtidos até achar onde se encaixa.
*/

int pontuacao(int forca){
	int ini = 0, fim  = n;

	while(fim-ini > 1){
		int med = (fim + ini)/2;
		if(a[med] <= forca){
			ini = med;
		}
		else{
			fim = med;
		}
	}
	return p[fim-1];
}

int main() {
    
    cin >> n >> m;
    
    a[0] = 0;
    for (int i = 0; i < n-1; i++) cin >> a[i+1];   // faixas da competição 
    for (int i = 0; i < n; i++) cin >> p[i];  // premiacao. Como cada faixa começa de 0-X, fica um item a mais aqui.
    for (int i = 0; i < m; i++) cin >> b[i]; // poder da pancada de cada ogro
    
    bool first = true;
    
    for(int i = 0; i < m; i++){
        if(first) first = false; // separador de linha legal para testar
        else cout << " ";
        cout << pontuacao(b[i]);
    }
    
    cout << endl;
}
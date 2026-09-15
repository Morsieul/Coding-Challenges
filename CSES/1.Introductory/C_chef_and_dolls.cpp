/*Usar o Xor para comparar cada elemento, até que sobre apenas o diferente.
Propriedades do Xor:
X xor X = 0
A xor B = B xor A
X xor 0 = X
*/

#include<bits/stdc++.h>

const int MAXN = 100000;
int arr[MAXN];

int main() {
    int T;
    int n;

    std::cin >> T;

    for(int i = 0; i < T; i++) {

        std::cin >> n;
        for(int i = 0; i < n; i++) std::cin >> arr[i];
        
        int type = 0;
        
        for(int i = 0; i < n; i++) {
            type = type ^ arr[i];
        }
        std::cout << type << std::endl;
    }

}
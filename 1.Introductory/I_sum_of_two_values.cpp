#include <bits/stdc++.h>


int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> V(n);
    std::map<int, int> indice;

    for(int i = 0; i < n; i++) {
        std::cin >> V[i];
        if(indice.count(x - V[i])) {
        std::cout << i + 1 << " " << indice[x- V[i]] + 1;
        return 0;

        }
        indice[V[i]] = i;
    }

    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}
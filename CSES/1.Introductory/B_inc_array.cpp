#include<bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    if (!(std::cin >> n)) return 0;  


    std::vector<long long> a(n);
    long long moves = 0;
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    for(long long i = 1; i < n; ++i) {
        if(a[i - 1] > a[i] ) {
            moves += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }

    std::cout << moves << "\n";
    return 0;
}
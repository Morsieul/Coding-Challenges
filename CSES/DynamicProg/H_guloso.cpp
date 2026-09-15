#include<bits/stdc++.h>
using namespace std; 

const int INF = 1000000;

int RemovingDigits(int n) {

    if(n == 0) return 0;
    if(n <= 9) return 1;


    vector<int> digits;

        int aux = n;

        while(aux > 0) {
            digits.push_back(aux % 10);
            aux = aux / 10;
        }

        int maior = -INF;

        for(int d: digits) {
            if(d > maior) maior = d;
        }

    return 1 + RemovingDigits(n - maior);


}

int main() {
    int n;
    cin >> n;

    cout << RemovingDigits(n);

}
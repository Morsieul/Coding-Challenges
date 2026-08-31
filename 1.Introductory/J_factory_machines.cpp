#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2*100000;
int n;
long long k;
int maq[MAXN];

long long conta_produtos(long long t){
    long long qtd = 0;
    for(int i = 0; i < n; i++){
        qtd += t / maq[i];
        if(qtd > k){
            return k + 1;
        }
    }
    return qtd;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> maq[i];
    }
    // for(int i = 0; i < 20; i++){
    //     cout << "tempo " << i << " produtos : " << conta_produtos(i) << endl;
    // }


    long long left = 0;
    long long right = 1000000000LL * 1000000000LL + 1;
    long long ans = -1;
    while(left <= right){
        long long m = left + (right - left) / 2;
        long long qtd_m = conta_produtos(m);

        if(qtd_m >= k){
            ans = m;
            right = m-1;
        } else {
            left = m + 1;
        }
    }
    cout << ans << endl;

    return 0;
}




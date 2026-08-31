#include<bits/stdc++.h>

using namespace std;
const int MAXN = 30;
int arr[MAXN];
int n;

typedef long long ll;
ll solve_rec(int i, ll sum1, ll sum2) {
    if(n == i) {
        return abs(sum1 - sum2);
    }

    ll op1 = solve_rec(i + 1, sum1 + arr[i], sum2);
    ll op2 = solve_rec(i + 1, sum1, sum2 + arr[i]);

    return min(op1, op2);
    
}

int main() {
    cin >> n;
    
    for(int j =  0; j < n; j++) {
        cin >> arr[j];
    }

    cout << solve_rec(0, 0, 0) << endl;
}
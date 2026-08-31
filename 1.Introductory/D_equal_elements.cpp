
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;        

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int &x : arr) cin >> x;

        unordered_map<int, int> cnt;
        int maxFreq = 0;
        for (int x : arr) {
            int cur = ++cnt[x];
            if (cur > maxFreq) maxFreq = cur;
        }

        int moves = n - maxFreq;        
        cout << moves << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long soma(const vector<int>& nums, int n) {
    if (n < 0) {
        return 0;
    }
    
    return nums[n] + soma(nums, n - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << soma(nums, n - 1) << "\n";
    
    return 0;
}
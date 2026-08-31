#include <bits/stdc++.h>
using namespace std;

int MinimunCoins(vector<int>& coins, int amount) {
    auto n = (int) coins.size();
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]]+ 1);
            }
        }
        
    }
    return dp[amount] < 1e9 ? dp[amount] :-1; 
}

// Driver function
int main() {
    int n,amount;

    cin >> n >> amount;

    vector<int> coins(n);

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << MinimunCoins(coins, amount) ;
    return 0;
}


#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> nums_impares;

    if(n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            if(i % 2 == 0) {
                cout << i << " ";
            } else nums_impares.push_back(i);
        }

        for(int j : nums_impares) {
            cout <<j << " ";
        }      
    }

}
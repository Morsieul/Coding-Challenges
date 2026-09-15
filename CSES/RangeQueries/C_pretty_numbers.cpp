#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> pretties;

    for(int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        int pretty = 0;
  

        for(int j = l; j <= r; j++) {
            int last_digit = j % 10;
            if(last_digit == 2 || last_digit == 3 || last_digit == 9) pretty++; 
        }
        pretties.push_back(pretty);
    }

    for(int k = 0; k < (int) pretties.size(); k++) cout << pretties[k] << endl;

}
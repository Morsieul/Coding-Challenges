#include<bits/stdc++.h>

using namespace std;

int tribonacci(int n) {
    if(n <= 0) return 0;
    else if(n < 3) return 1;
    else return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

int main() {
    int n;
    
    cin >> n;
    
    cout << tribonacci(n) << endl;
}
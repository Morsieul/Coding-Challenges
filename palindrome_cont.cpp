#include <iostream>
#include <string>

using namespace std;

int custoP(string &s, int i, int f) {

    if (i >= f) {
        return 0;
    }
    
    if (s[i] != s[f]) {
        s[f] = s[i];
        return 1 + custoP(s, i + 1, f - 1);
    }
    
    return custoP(s, i + 1, f - 1);
}

int main() {
    string s;
    cin >> s;
    
    cout << custoP(s, 0, s.size() - 1) << endl;
    
    return 0;
}
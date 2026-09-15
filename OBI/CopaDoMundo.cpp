#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> f;
    string equipes = "ABCDEFGHIJKLMNOP";
    for(char c : equipes) {
        f.push(string(1, c));
    }
    
    int n, m;
    
    for(int i = 0; i < 15; i++) {
        cin >> n >> m;
        
        string time1 = f.front();
        f.pop();
        string time2 = f.front();
        f.pop();
        
        if(n > m) {
            f.push(time1);
        } else {
            f.push(time2);
        }
    }
    
    cout << f.front() << "\n";
    
    return 0;
}
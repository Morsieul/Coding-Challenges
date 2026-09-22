#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	int x;
	cin >> n >> x;

    // use the number as the key and the index as the values;
    
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (m.count(x - a)) {
			cout <<  m[x - a] + 1 << " " << i + 1  << endl;
			return 0;
		}
		m[a] = i;
	}

	cout << "IMPOSSIBLE" << endl;
}
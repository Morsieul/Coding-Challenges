/* Usar prefix sum 2D*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> prefix2D(vector<vector<int>> &arr) {
        // number of rows
    int n = arr.size();
    
    // number of columns
    // int m = arr[0].size(); a nossa matriz é n x n
    
    vector<vector<int>> prefix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            // Start with original value
            prefix[i][j] = arr[i][j];
            
            // Add value from top cell if it exists
            if (i > 0) {
                prefix[i][j] += prefix[i - 1][j];
            }
            
            // Add value from left cell if it exists
            if (j > 0) {
                prefix[i][j] += prefix[i][j - 1];
            }
            
            // Subtract overlap from top-left diagonal if it exists
            if (i > 0 && j > 0) {
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }

    return prefix;
}

int soma(int y1, int x1, int y2, int x2, 
            	vector<vector<int>> &pref) {
  
    // Start with the sum of the entire submatrix (0, 0) to (down, right)
    int sum = pref[y2][x2];
	
  	// Subtract the area to the left of the submatrix, if it exists
    if (x1 - 1 >= 0) {
        sum -= pref[y2][x1 - 1];
    }

  	// Subtract the area above the submatrix, if it exists
    if (y1 - 1 >= 0) {
        sum -= pref[y1 - 1][x2];
    }

    // Add back the overlapping area that was subtracted twice
    if (y1 - 1 >= 0 && x1 - 1 >= 0) {
        sum += pref[y1 - 1][x1 - 1];
    }

    return sum;
}


int main() {
    int n, q;

    cin >> n >> q;

    vector<vector<int>> floresta(n);
    vector<int> queries;

    for(int i = 0; i < n; i++) {
        string arvore;
        cin >> arvore;
        floresta[i].resize(n);
        for(int j = 0; j < n; j++) {
            if(arvore[j] == '*') floresta[i][j] = 1;
            else if(arvore[j] == '.') floresta[i][j] = 0;
        }

    }

    vector<vector<int>> prefixSum = prefix2D(floresta);

    //queries
    for(int k = 0; k < q; k++) {
        int y1, x1, y2, x2;

        cin >> y1 >> x1 >> y2 >> x2;
        y1 --;
        x1 --;
        y2 --;
        x2 --;

        queries.push_back(soma(y1, x1, y2, x2, prefixSum));
    }

    for(int m = 0; m < (int) queries.size(); m++) cout << queries[m] << endl;
    
}
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;
    if (n == 1) {
        int rows, cols;
        fin >> rows >> cols;
        fout << 0;
        return 0;
    }

    vector<int> input(n + 1);
    for (int i = 0; i < n; i++) {
        int rows, cols;
        fin >> rows >> cols;
        if (i == 0)
            input[0] = rows;
        input[i + 1] = cols;
    }

    vector<vector<int>> V(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            V[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = V[i][k] + V[k + 1][j] + input[i] * input[k + 1] * input[j + 1];
                if (cost < V[i][j]) {
                    V[i][j] = cost;
                }
            }
        }
    }

    fout << V[0][n - 1] << endl;

    return 0;
}
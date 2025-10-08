#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<char> input;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    char c;
    while (fin.get(c)) {
        input.push_back(c);
    }
    int n = (int)input.size(); 
    vector<vector<int>> V(n, vector<int>(n, 0));
    
    for (int i = n - 1; i >= 0; i--) {
        V[i][i] = 1; 
        for (int j = i + 1; j < n; j++) {
            if (input[i] == input[j]) 
                V[i][j] = V[i + 1][j - 1] + 2;
            else 
                V[i][j] = max(V[i + 1][j], V[i][j - 1]);
        }
    }
    fout << V[0][n-1] << endl;

    int i = 0;
    int j = n-1;
    vector <char> output;
    while (j >= i) {
        if (input[i] == input[j]) {
            output.push_back(input[i]);
            i++; 
            j--;
        }
        else {
            if (V[i][ j - 1] > V[i + 1][ j]) 
                j--;
            else
                i++;
        }
    }

    bool needA = false;
    char a = ' ';
    if (V[0][n - 1] % 2 != 0 && !output.empty()) {
        a = output.back();
        output.pop_back();
        needA = true;
    }
    for (char c : output) {
        fout << c;
    }
    if (needA)
        fout << a;
    reverse(output.begin(), output.end());
    for (char c : output) {
        fout << c;
    }


    fin.close();
    fout.close();
}
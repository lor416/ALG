#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> input1(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> input1[i];
    }
    vector<int> input2(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> input2[i];
    }

    vector<vector<int>> V(n+1, vector<int>(n+1, 0));
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (input1[i] == input2[j])
                V[i][j] = V[i - 1][j - 1] + 1;
            else {
                if (V[i - 1][j] >= V[i][j - 1])
                    V[i][j] = V[i - 1][j];
                else
                    V[i][j] = V[i][j-1];
                //V[i][j] = max(V[i - 1, j], V[i][j - 1]);
            }
        }
    }
    int num = V[n][n];
    cout << num << endl;
    int i = n;
    int j = n;
    vector <int> out1;
    vector <int> out2;
    
    while (i > 0 && j> 0) {
        if (input1[i] == input2[j]) {
            out1.push_back(i-1);
            out2.push_back(j-1);
            i--;
            j--;
        }
        else {
            if (V[i - 1][j] >= V[i][j - 1]) 
                i--;
            else
                j--;
        }
    }
    reverse(out1.begin(), out1.end());  
    reverse(out2.begin(), out2.end());
    for (int i = 0; i < num; i++) {
        cout << out1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < num; i++) {
        cout << out2[i] << ' ';
    }
    
    return 0;
}
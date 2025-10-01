#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> V(n+1);
    vector<int> work(n+1);
    if (n == 2) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i < n+1; i++) {
        cin >> V[i];
    }
    
    work[1] = V[1];
    work[2] = -100000;
    work[3] = V[3] + V[1];
    work[4] = V[4] + V[1];
    //work[5] = V[1] + V[3] + V[5];
    if (n == 1) {
        cout << V[1] << endl << 1;
        return 0;
    }
    if (n == 3) {
        cout << V[1] + V[3] << endl << "1 3";
        return 0;
    }


    for (int i = 5; i <= n; i++) {
        
        work[i] = max(work[i - 2], work[i - 3]) + V[i];
    }
    cout << work[n];
    






    
    return 0;
}
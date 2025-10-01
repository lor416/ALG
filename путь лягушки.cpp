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
    
    for (int i = 1; i < n+1; i++) {
        cin >> V[i];
    }
    if (n == 2) {
        cout << -1;
        return 0;
    }
   
    
    //work[5] = V[1] + V[3] + V[5];
    if (n == 1) {
        cout << V[1] << endl << 1;
        return 0;
    }
    if (n == 3) {
        cout << V[1] + V[3] << endl << "1 3";
        return 0;
    }
    work[1] = V[1];
    work[2] = -100000;
    work[3] = V[3] + V[1];
    work[4] = V[4] + V[1];

    vector<int> way(n + 1, -1);
    for (int i = 5; i <= n; i++) {
        
        if (work[i - 2] > work[i - 3]) {
            work[i] = work[i - 2] + V[i];
            way[i] = i - 2;
        }
        else {
            work[i] = work[i - 3] + V[i];
            way[i] = i - 3;
        }
        //work[i] = max(work[i - 2], work[i - 3]) + V[i];
    }
    cout << work[n] << endl;
    /*for (int i = 1; i < n + 1; i++) {
        cout << way[i] << ' ';
    }
    cout << endl;*/
    vector <int> newWay;
    int induk = n;
    way[1] = 0;  
    way[3] = 1; 
    way[4] = 1;  

    while (induk > 0) {
        newWay.push_back(induk);
        induk = way[induk];
    }
    reverse(newWay.begin(), newWay.end());

    // Вывод результата
    //cout << work[n] << endl;
    for (int i = 0; i < newWay.size(); i++) {
        cout << newWay[i] << ' ';
    }
    






    
    return 0;
}
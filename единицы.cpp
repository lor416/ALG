#include <iostream>
#include <vector>
using namespace std;

/*
unsigned long long fac(int n, int k) {
	if (n == k)
		return 1;
	return fac(n - 1, k) * n / (n - k);
}*/
int main()
{
	int n;
	int k;
	cin >> n;
	cin >> k;
	/*unsigned long long res = 1;
	
	for (int i = 0; i < k; i++) {
		res *= (n - i) / (i + 1);
	}*/
	//long long  result = fac(n, k) / fac1(n - k);
	//unsigned long long  result = fac(n, k);

	if (k > n - k) 
		k = n - k;
	vector<int> memo(k + 1, 0);
	memo[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = k; j > 0; j--) {
			if (j <= i) { 
				memo[j] = (memo[j] + memo[j - 1]) % 1000000007;
			}
		}
	}

	cout << memo[k] << endl;

	//cout << result % 1000000007;

}
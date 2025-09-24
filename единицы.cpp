#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<vector<int>> memo;

int binomial(int n, int k) {
	if (k == 0 || k == n) 
		return 1;
	if (k > n) 
		return 0;

	if (memo[n][k] != -1) 
		return memo[n][k];

	int result = (binomial(n - 1, k - 1) + binomial(n - 1, k)) % MOD;
	memo[n][k] = result;
	return result;
}
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
	memo.resize(n + 1, vector<int>(k + 1, -1));

	cout << binomial(n, k) << endl;

	//cout << result % 1000000007;

}
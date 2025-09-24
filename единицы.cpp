#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

long long mod_pow(long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b % 2 == 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return res;
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
	long long result = 1;

	for (int i = 1; i <= k; i++) {
		result = (result * (n - i + 1)) % MOD;
		result = (result * mod_pow(i, MOD - 2)) % MOD;  
	}


	cout << result;

}
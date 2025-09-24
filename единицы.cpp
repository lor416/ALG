#include <iostream>
using namespace std;
/*
unsigned long long binomial(int n, int k) {
	unsigned long long res = 1;
	for (int i = 1; i <= k; ++i) {
		res = res * (n - i + 1) / i;
	}
	return res;
}*/

unsigned long long fac(int n, int k) {
	if (n == k)
		return 1;
	return fac(n - 1, k) * n / (n - k);
}/*
long long fac1(int n) {
	if (n == 0)
		return 1;
	return fac1(n - 1) * n;
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
	unsigned long long  result = fac(n, k);
	//unsigned long long result = binomial(n, k);

	cout << result % 1000000007 << "\n";
	//cout << res % 1000000007;

}
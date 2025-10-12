
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int upper(const vector<int>& mas, int x) {
	int left = 0, right = mas.size();
	while (left < right) {
		int mid = (left + right) / 2;
		if (mas[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left;
}
int main()
{
	fstream fin("input.txt");
	ofstream fout("output.txt");
	
	int n;
	fin >> n;
	vector < int> input(n);
	for (int i = 0; i < n; i++) {
		fin >> input[i];
	}
	vector < int> V;

	int i = 0;
	while (i != n) {
		int x = input[i];
		int up = upper(V, x);
		if (up == V.size())
			V.push_back(x);
		else
			V[up] = x;
		i++;
	}
	cout << V.size();
	fout << V.size();
	return 0;
}

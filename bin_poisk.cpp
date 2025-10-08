// bin_poisk.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	//Массив
	// 1 строка 
	int n;
	cin >> n;
	// 2 строка
	vector <int> Mas(n);
	for (int i = 0; i < n; i++) {
		cin >> Mas[i];
	}
	// Запросы
	// 3 строка
	int k;
	cin >> k;
	// 4 строка
	vector <int> X(k);
	for (int i = 0; i < k; i++) {
		cin >> X[i];
	}
	/*Для каждого числа-запроса x в отдельной строке выведите через пробел числа b, l и r, где 
	b равно 1, если x присутствует в массиве, или 0 в противном случае; l — индекс первого элемента,
	большего либо равного x;r — индекс первого элемента, большего x. Элементы массива нумеруются индексами
	от 0 до n-1.Если подходящих элементов в массиве нет, договоримся, что возвращаемый индекс будет равен n.*/
	
	for (int i = 0; i < k; i++) {
		int x = X[i];
		int b = 0, l = 0, r = 0;

		// Поиск первого элемента >= x 
		int left = 0, right = n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (Mas[mid] < x) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		l = left;

		// Поиск первого элемента > x 
		left = 0; right = n;
		while (left < right) {
			int mid = (left + right) / 2;
			if (Mas[mid] <= x) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		r = left;



		if (l < n && Mas[l] == x) {
			b = 1;
		}
		else {
			b = 0;
		}


		cout << b << " " << l << " " << r << endl;
	}

	return 0;



}

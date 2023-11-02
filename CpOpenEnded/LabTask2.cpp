// Prime Numbers Generator and Checker
/*
#include<iostream>
using namespace std;
int main() {
	int numba, start_range, end_range;
	char choice;
	numba = 1;
	cout << "Do you want to find prime numbers in a range or do you want to check if a number is prime or not (1|0): ";
	cin >> choice;
	if (choice == '1') {
		cout << "Enter the first number of range: ";
		cin >> start_range;
		cout << "Enter the last number of range: ";
		cin >> end_range;

		for (int x = start_range; x <= end_range; x++) {
			bool Green = 1;
			for (int y = 2; y <= x / 2; y++) {
				if (x % y == 0) {
					Green = 0;
					break;
				}
			}
			if (Green) {
				cout << x << " ";

			}
		}

		


	}
	else if (choice == '0') {
		
		int n;
		cout << "Enter the number to be checked: ";
		cin >> n;
		bool Green = 1;
		for (int x = 2; x <= n / 2; x++) {
			if (n % x == 0) {
				Green = 0;
				break;
			}
		}
		if (Green) {
			cout << n <<" "<<"is a prime number." << endl;

		}
		else {
			cout << n <<" " << "is not a prime number." << endl;
		}
	}
	return 0;
}*/


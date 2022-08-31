#include<iostream>
using namespace std;
class matrix
{
	int** p;
	int d1, d2;
public:
	matrix(int x, int y);
	void input(int& i, int& j, int value)
	{
		p[i][j] = value;
	}
	void print(int row, int col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
	}
	int saddlePoint();
};
matrix::matrix(int x, int y)
{
	d1 = x;
	d2 = y;
	p = new int* [d1];
	for (int i = 0; i < d1; i++)
	{
		p[i] = new int[d2];
	}
}
int matrix::saddlePoint() {
	int minm = 0, cindex;
	for (int i = 0; i < d1; i++) {
		int minm = p[i][0];
		cindex = 0;
		for (int j = 1; j < d2; j++) {
			if (minm > p[i][j]) {
				minm = p[i][j];
				cindex = j;
			}
		}
		int k;
		for (k = 0; k < d1; k++) {
			if (minm < p[k][cindex])
				break;
		}
		if (k == d2)
			return minm;
	}
	return 0;
}
int main() {
	int ans = 0;
	do {
		cout << "Enter the size of the matrix : ";
		int row, col, value;
		cin >> row >> col;
		matrix m(row, col);
		cout << "Enter the values of the matrix : " << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> value;
				m.input(i, j, value);
			}
		}
		cout << "Matrix : " << endl;
		m.print(row, col);

		int saddle = m.saddlePoint();
		if (saddle == 0) {
			cout << "There is no saddle point" << endl;
		}
		else {
			cout << "Saddle Point : " << saddle << endl;
		}
		cout << "\nDo you want to find saddle point of another matrix?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you " << endl;

}
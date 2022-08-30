#include<iostream>
using namespace std;
class SparseMatrix {
public:
	int** sparse = { 0 };
	int row; int col;
	int val=0;
	SparseMatrix(int rows,int cols,int zeros) {
		row = rows;
		col = cols;
		sparse = new int* [zeros];
		for (int i = 0; i < zeros; i++) {
			sparse[i] = new int[3];
		}
	}
	void insert(int r, int c, int value) {
		if (r > row || c > col) {
			cout << "Not possible"<<endl;
		}
		else{
			sparse[val][0] = r;
			sparse[val][1] = c;
			sparse[val][2] = value;
			val++;
		}

	}
	void transpose() {
		//cout << "\nMatrix : " << endl;
		cout << "\nRow\tColoumn\tValue" << endl;
		for (int i = 0; i < val; i++) {
			cout << sparse[i][1] << "\t" << sparse[i][0] << "\t" << sparse[i][2] << endl;
		}
	}
	void print_matrix() {
		//cout << "\nMatrix : "<<endl;
		cout << "\nRow\tColoumn\tValue" << endl;
		for (int i = 0; i < val; i++) {
			cout << sparse[i][0] << "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
		}
	}
	void addn(SparseMatrix s2) {
		int p1 = 0, p2 = 0;
		if (row != s2.row && col != s2.col) {
			cout << "\nAddition not possible" << endl;
		}
		else {
			SparseMatrix s3(row, col,40);
			cout << "After addition : ";
			while (p1 < val && p2 < s2.val) {
				if (sparse[p1][0] == s2.sparse[p2][0] && sparse[p1][1] == s2.sparse[p2][1]) {
					int sum = sparse[p1][2] + s2.sparse[p2][2];
					s3.insert(s2.sparse[p2][0], s2.sparse[p2][1], sum);
					p1++; p2++;
				}
				else if (sparse[p1][0] <= s2.sparse[p2][0] || sparse[p1][1] < s2.sparse[p2][1]) {
					s3.insert(sparse[p1][0], sparse[p1][1], sparse[p1][2]);
					p1++;
				}
				else if (sparse[p1][0] >= s2.sparse[p2][0] || sparse[p1][1] > s2.sparse[p2][1]) {
					s3.insert(s2.sparse[p2][0],s2.sparse[p2][1],s2.sparse[p2][2]);
					p2++;
				}
				while (p1 < val) {
					s3.insert(sparse[p1][0], sparse[p1][1], sparse[p1][2]);
					p1++;
				}
				while (p2 < s2.val) {
					s3.insert(s2.sparse[p2][0], s2.sparse[p2][1], s2.sparse[p2][2]);
					p2++;
				}
				s3.print_matrix();
				cout << "\n2. Transpose : ";
				cout << "\nTranspose of Second Matrix : ";
				s2.transpose();
				cout << "\nTranspose of final matrix : ";
				s3.transpose();
			}
		}
	}
};
int main() {
	int rows, cols, zeros, ans = 0;
	do{
		cout << "Sparse Matrix Operations : \n1. Addition of two Sparse Matrices\n";
			cout << "Enter the number of rows and coloumns of the first matrix : ";
			cin >> rows >> cols;
			cout << "Enter the number of non-zero values for the matrix : ";
			cin >> zeros;
			SparseMatrix s1(rows, cols, zeros);
			cout << "Enter the row number,coloumn number and value : ";
			for (int i = 0; i < zeros; i++) {
				int row, col, val;
				cin >> row >> col >> val;
				s1.insert(row, col, val);
			}
			cout << "Enter the number of rows and coloumns of the second matrix : ";
			int rows, cols, zeros;
			cin >> rows >> cols;
			cout << "Enter the number of non-zero values for the second matrix : ";
			cin >> zeros;
			SparseMatrix s2(rows, cols, zeros);
			cout << "Enter the row number,coloumn number and value : ";
			for (int i = 0; i < zeros; i++) {
				int row, col, val;
				cin >> row >> col >> val;
				s2.insert(row, col, val);
			}cout << "\nFirst Matrix : ";
			s1.print_matrix();
			cout << "\nSecond Matrix : ";
			s2.print_matrix();
			s1.addn(s2);
			cout << "Transpose of First matrix : ";
			s1.transpose();
		cout << "\nDo you want to start over?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;

}
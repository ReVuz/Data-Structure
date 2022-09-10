#include<iostream>
using namespace std;

class SPARSE
{

	int MAX = 100;

	int** data;

	int row, col;

	int val;

public:
	SPARSE(int r, int c)
	{

		row = r;

		col = c;

		val = 0;

		data = new int* [MAX];

		for (int i = 0; i < MAX; i++)
			data[i] = new int[3];
	}

	void insert(int r, int c, int val)
	{

		if (r > row || c > col)
		{
			cout << "Invalid Entry!";
		}
		else
		{

			data[val][0] = r;

			data[val][1] = c;

			data[val][2] = val;

			val++;
		}
	}
	void print()
	{
		cout << "\n\nDimension of the matrix : " << row << "x" << col;
		cout << "\n\nMatrix: \nRow\tColumn\tValue\n";

		for (int i = 0; i < val; i++)
		{
			cout << data[i][0] << "\t " << data[i][1]
				<< "\t " << data[i][2] << endl;
		}
	}
	SPARSE transpose()
	{

		SPARSE s3(col, row);

		s3.val = val;

		int* count = new int[col + 1];

		for (int i = 1; i <= col; i++)
			count[i] = 0;

		for (int i = 0; i < val; i++)
			count[data[i][1]]++;

		int* index = new int[col + 1];

		index[0] = 0;

		for (int i = 1; i <= col; i++)

			index[i] = index[i - 1] + count[i - 1];

		for (int i = 0; i < val; i++)
		{

			int pos = index[data[i][1]]++;

			s3.data[pos][0] = data[i][1];

			s3.data[pos][1] = data[i][0];

			s3.data[pos][2] = data[i][2];
		}

		return s3;
	}
	void add(SPARSE s2)
	{

		if (row != s2.row || col != s2.col)
		{
			cout << "Addition not possible" << endl;
		}

		else
		{
			int pos1 = 0, pos2 = 0;
			SPARSE s3(row, col);

			while (pos1 < val && pos2 < s2.val)
			{

				if (data[pos1][0] > s2.data[pos2][0] ||
					(data[pos1][0] == s2.data[pos2][0] &&
						data[pos1][1] > s2.data[pos2][1]))

				{

					s3.insert(s2.data[pos2][0],
						s2.data[pos2][1],
						s2.data[pos2][2]);

					pos2++;
				}

				else if (data[pos1][0] < s2.data[pos2][0] ||
					(data[pos1][0] == s2.data[pos2][0] &&
						data[pos1][1] < s2.data[pos2][1]))

				{

					s3.insert(data[pos1][0],
						data[pos1][1],
						data[pos1][2]);

					pos1++;
				}

				else
				{

					int value_sum = data[pos1][2] +
						s2.data[pos2][2];

					if (value_sum != 0)
						s3.insert(data[pos1][0],
							data[pos1][1],
							value_sum);
					pos1++;
					pos2++;
				}
			}

			while (pos1 < val) {
				s3.insert(data[pos1][0],
					data[pos1][1],
					data[pos1][2]);
				pos1++;
			}
			while (pos2 < s2.val) {
				s3.insert(s2.data[pos2][0],
					s2.data[pos2][1],
					s2.data[pos2][2]);
				pos2++;
			}
			cout << "\nSum of the two matrix : ";
			s3.print();
			cout << "\nTranspose of the matrix : ";
			s3.transpose().print();
		}
	}

};

int main() {
	int rows, cols, zeros, ans = 0;
	do {
		cout << "\nSparse Matrix Operations \n1. Addition of two Sparse Matrices\n";
		cout << "Enter the number of rows and coloumns of the first matrix : ";
		cin >> rows >> cols;
		cout << "Enter the number of non-zero values for the matrix : ";
		cin >> zeros;
		SPARSE s1(rows, cols);
		cout << "Enter the row number,coloumn number and value : " << endl;
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
		SPARSE s2(rows, cols);
		cout << "Enter the row number,coloumn number and value : " << endl;
		for (int i = 0; i < zeros; i++) {
			int row, col, val;
			cin >> row >> col >> val;
			s2.insert(row, col, val);
		}cout << "\nFirst Matrix : ";
		s1.print();
		cout << "\nTranspose of first matrix : ";
		s1.transpose().print();
		cout << "\nSecond Matrix : ";
		s2.print();
		cout << "\nTranspose of second matrix : ";
		s2.transpose().print();
		s1.add(s2);
		cout << "\nDo you want to start over?(1/0) : ";
		cin >> ans;
	} while (ans);
	cout << "Thank you" << endl;
}

#include<iostream>
#include<iomanip>
using namespace std;
class magic_square {
public:

    void create(int size) {
        int** matrix;
        matrix = new int* [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new int[size];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = 0;
            }
        }
        int row = size / 2;
        int col = size - 1;
        for (int values = 1; values <= size * size; values++) {
            matrix[row][col] = values;
            row = row - 1;
            col = col + 1;
            if (row == -1 && col == size) {
                row = 0;
                col = size - 2;
            }
            else if (row == -1) {
                row = size - 1;
            }
            else if (col == size) {
                col = 0;
            }
            else if (matrix[row][col] != 0) {
                row = row + 1;
                col = col - 2;
            }
        }
        cout << "\nThe Magic Square of size " << size << "x" << size << " is : " << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << setw(5) << matrix[i][j];
            }
            cout << endl;
        }
    }
};
int main() {
    cout << "Enter an odd number to generate a magic square : ";
    int rc;
    cin >> rc;
    magic_square details;
    details.create(rc);
}
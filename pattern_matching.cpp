#include<iostream>
using namespace std;
void substring(int pos, int length, char text[]) {
	cout << "\nSubstrings extracted from the text " << text << " from index " << pos << " are : "<<endl;
	for (int i = pos; i < length; i++) {
		for (int j = i; j < length; j++) {
				cout << "\n"<<text[j];
		}cout << endl;
	}
}
int main() {
	cout << "Enter a word : ";
	char str[40];
	cin >> str;
	cout << "Enter the position from which the substring need to be extracted : ";
	int sub_len;
	cin >> sub_len;
	substring(sub_len, strlen(str), str);
	return 0;

}
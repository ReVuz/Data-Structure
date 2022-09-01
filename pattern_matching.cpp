#include<iostream>
#include<cstring>>
using namespace std;
void substring(int pos, int length, string text) {

	cout << "\nSubstrings extracted from the text " << text << " from index " << pos << " are : "<<endl;
	for (int i = pos; i < length; i++) {
		for (int j = i; j < length; j++) {
				cout <<text[j];
		}cout << endl;
	}
}
int pattern( string String, int str_length, char pattern[], int pat_length){
		int k = 0;
		int max = str_length - pat_length + 1;
		while (k <= max)
		{
			int c = 0;
			for (int i = 0; i < pat_length; i++)
			{
				if (pattern[i] != String[k + i])
				{
					i = pat_length;
				}
				else
				{
					c++;
				}
			}
			if (c == pat_length)
			{
				return k;
			}
			k++;
		}
		return -1;
	}
string insert(string S, int E_p, string SUB)
{
	int n = S.length();
	SUB = SUB + " ";
	int ns = SUB.length();
	int total = n + ns + 1;
	char* str = new char[total];
	strcpy(str, S.c_str());
	char* Sub = new char[ns + 1];
	strcpy(Sub, SUB.c_str());

	string tep = S;

	char* temp = new char[total];
	strcpy(temp, tep.c_str());

	for (int i = E_p, j = 0; i < ns + E_p; i++, j++)
	{
		str[i] = Sub[j];
	}
	for (int i = E_p + ns, j = E_p; i < n + ns + 1; i++, j++)
	{
		str[i] = temp[j];
	}
	cout << "New String : " << str << "\n";
	return(string(str));
}
string del(string S, int pos, int len)
{
	int nm = pos + len;
	int n = S.length();
	char* str = new char[n + 1];
	strcpy(str, S.c_str());

	string tep = S;
	char* temp = new char[n + 1];
	strcpy(temp, tep.c_str());
	for (int i = 0, j = pos; j < n + 1; i++)
	{
		str[j] = temp[nm];
		nm = nm + 1;
		j = j + 1;
	}
	return (string(str));
}

int main() {
	cout << "Enter a word : ";
	string str;
	cin >> str;
	string S,Str,str2;
	cin >> str;
	cout << "String Operations : \n1. pattern matching \n2. Substring Extraction \n3. Insertion of a String \n4.Deletion of a string \n5. String Replacement \n0. Exit"
		"\nChoose any option : ";
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
		cout << "Enter the pattern : ";
		char ptn[40];
		cin >> ptn;
		int match = pattern( str, str.length(), ptn, strlen(ptn));
		if (match == 0) {
			cout << "Pattern not found" << endl;
		}
		else {
			cout << "Pattern found at position : " << match << endl;
		}
		break;
	case 2:
		cout << "Enter the position from which the substring need to be extracted : ";
		int sub_len;
		cin >> sub_len;
		substring(sub_len, str.length(), str);
		break;
	case 3 :
		cout << "Enter a string : ";
		cin >> Str;
		cout << "Enter the position to insert : ";
		int pos;
		cin >> pos;
		S = insert(str, pos, Str);
		cout << "New String : " << S << endl;
		break;
	case 4:
		cout << "Enter the position of string to delete : ";
		cin >> pos;
		cout << "Enter the length to delete : ";
		int len;
		cin >> len;
		S = del(str, pos, len);
		cout << "Updated String : " << S << endl;
		break;
	case 5: 
		cout << "Enter the position to replace : ";
		cin >> pos;
		cout << "Enter the length to replace : ";
		cin >> len;
		cout << "Enter the string to replace : ";
		cin >> str2;
		S = del(str, pos, len);
		S = insert(str, pos, str2);
		cout << "Updated String : " << S << endl;
		break;
	default:
		break;
	}

}
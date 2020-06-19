#include <iostream>
#include <string>
using namespace std;

int Hash(string key, int n)
{
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
	{
		sum += key[i];
	}
	sum %= n;
	return sum;
}

string* Create(int n)
{
	string* Table = new string[n];
	for (int i = 0; i < n; i++)
	{
		Table[i].empty();
	}
	int i = 0;
	while (i < n)
	{
		string key;
		cout <<"key = ";
		cin >> key;
		int hash = Hash(key, n);
		if (Table[hash].empty())
			Table[hash] = key;
		else
		{
			cout << "Conflict situation. Replace the word" << endl;
			continue;
		}
		i++;
	}
	return Table;
}

int Search(string key, string* Table, int n)
{
	int hash = Hash(key, n);
	if (Table[hash] == key)
		return hash;
	else
		return -1;
}

void Show(string* Table, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Table[" << i << "] = " << Table[i] << endl;
	}
}

int main()
{
	string* Table = NULL;
	string key;
	int n = 0;
	int action;
	do
	{
		cout<< "1. Create table" << endl << "2. Search" << endl << "3. Show" << endl << "0. Exit" << endl << "Select an action = ";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
		{
			if (Table != NULL)
				delete[] Table;
			n = 10;
			Table = Create(n);
			cout << "Table created" << endl;
			break;
		}
		case 2:
		{
			if (n != 0)
			{
				cout << "Enter key = ";
				cin >> key;
				if (Search(key, Table, n) != -1)
					cout << "Index = " << Search(key, Table, n) << endl;
				else
					cout << "Not found" << endl;
			}
			else cout << "Create a table" << endl;
			break;
		}
		case 3:
		{
			if (n != 0)
			{
				Show(Table, n);
				cout << endl;
			}
			else
				cout << "Create a table" << endl;
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Error" << endl;
			break;
		}
		}

	} while (action != 0);
	
	return 0;
}
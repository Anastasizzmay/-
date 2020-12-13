#include "userValidation.h"

void inputPass(string& s)
{
	for (int i = 0; i < 81; i++)
		cout << "-";
	cout << endl << "\t\tВведите пароль: ";
	hidePass(s);
	for (int i = 0; i < 81; i++)
		cout << "-";
	cout << endl;
}

void hidePass(string& s)
{
	int temp;
	s = "";
	while (true)
	{
		temp = _getch();
		if (temp == 13) break;
		cout << "*";
		s += (char)temp;
	}
	cout << endl;
}

bool checkUser(string pass)
{
	ifstream fread(PASS_WAY, ios::in);
	string innerPass;
	if (!fread.is_open()) cout << "Файл не существует!" << endl;
	else
	{
		string incomingPass = sha256(sha256(pass) + pass);
		fread >> innerPass;
		if (incomingPass == innerPass)
		{
			fread.close();
			return true;
		}
		cout << endl << "Проверьте введённый пароль" << endl;
	}
	fread.close();
	return false;
}

void rewritePass(string pass)
{
	ofstream fout(PASS_WAY, ios::out);
	string new_pass = sha256(sha256(pass) + pass);
	fout << new_pass;
	fout.close();
}

void checkDefaultPass()
{
	ifstream fread(PASS_WAY, ios::in);
	if (!fread.is_open()) cout << "Файл не существует!" << endl;
	else
	{
		string innerPass;
		fread >> innerPass;
		if (innerPass == "d36ed169b0452636221ec97da8202bdb5831a10d21e5e25aee66fc92a0625f46")
		{
			int fate;
			system("color 4");
			cout << "\tВы используете стандартный пароль! Рекомендуется его сменить" << endl << endl;
			cout << endl << "\t1 - Сменить сейчас";
			cout << endl << "\t0 - Сменить позже";
			cout << endl << "~>> ";
			cin >> fate;
			if (fate == 1)
			{
				system("cls");
				system("color 5");
				string pass;
				cout << "\t\tВведите новый пароль: ";
				cin >> pass;
				rewritePass(pass);
			}
			fread.close();
			system("color 7");
			return;
		}

	}
	fread.close();
}

void core()
{
	cout << "\t\t\t*SHOP*" << endl << endl;
	checkDefaultPass();
	string pass;
	do {
		inputPass(pass);
	} while (!checkUser(pass));
}

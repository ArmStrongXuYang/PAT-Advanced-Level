#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;

string str;
int num;
void solution()
{
	cin >> str;
	int pos_e, pos_exp;
	bool isPositive = true;
	if (str[0] == '-')
		isPositive = false;
	pos_e = str.find('E');
	string str_num = str.substr(1, pos_e - 1);
	string str_exp = str.substr(pos_e + 1);
	//double num = stod(str_num);
	int exp = stoi(str_exp);
	if (exp > 0)
	{
		str_num.erase(1, 1);			//ȥ��С����
		if (exp < str_num.size() - 1)
			str_num.insert(exp + 1, ".");	//����ȷ��С����
		else
		{
			int pos = exp - (str_num.size() - 1);
			for (int i = 0; i < pos; i++)
			{
				str_num += '0';			//�ں������0
			}
		}
	}
	else if (exp<0)
	{
		str_num.erase(1, 1);			//ȥ��С����
		for (int i = 0; i < (-exp); i++)
		{
			str_num.insert(0, "0");
		}
		str_num.insert(1, ".");			//����0֮���ټ���С����
	}
	if (!isPositive)
		cout << '-';
	cout << str_num;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
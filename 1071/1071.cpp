#include<iostream>
#include<string>
#include<map>
#pragma warning(disable:4996)
using namespace std;
map<string, int> res;
string str, word;

void solution()
{
	getline(cin, str);			//�пո����getline
	for (int i = 0; i < str.size(); i++)
	{
		while ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z') || str[i] >= '0'&&str[i] <= '9')		//�������Ч���ַ�
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
				str[i] = 'a' + str[i] - 'A';
			word += str[i];
			i++;
		}
		if (word.size())
		{
			res[word]++;
			word.clear();
		}
	}
	//ʡ�¾���ôд
	int MaxNum = 0;
	auto i = res.begin();
	auto temp = i;
	for (; i != res.end(); i++)
	{
		if (i->second > MaxNum)
		{
			MaxNum = i->second;
			temp = i;
		}
	}
	cout << temp->first << ' ' << temp->second;

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
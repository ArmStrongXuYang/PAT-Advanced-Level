#include<iostream>
#include<string>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

string num[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
string c[6] = { "Ge","Shi", "Bai", "Qian", "Yi", "Wan" };
int J[] = {
    1, 10, 100, 1000,
    10000, 100000, 1000000, 10000000,
    100000000 };
vector<string>res;
void solution()
{
    int n;
    cin >> n;
    if (n==0)
    {
        cout << "ling";
        return;
    }
    if (n<0)
    {
        cout << "Fu ";
        n = -n;
    }
	int part[3];
	part[0]= n / 100000000; 
	part[1]= (n % 100000000) / 10000;
	part[2] = n % 10000;
    bool zero = false;		//�Ƿ��ڷ�������ǰ������ʵ�ling
	int printCnt = 0;			//����ά������ǰû�пո�֮������ĵ��ʶ���ǰ���һ���ո�
	for (int i = 0; i < 3; i++)
	{
		int temp = part[i];		//�������֣�ÿ�����ڲ�����������һ��������XǧX��XʮX
		for (int j = 3; j >= 0; j--)
		{
			int curPos = 8 - i * 4 + j;			//��ǰ���ֵ�λ��
			if (curPos >= 9)
				continue;						//����λ��
			int cur = (temp / J[j]) % 10;		//ȡ����ǰ����
			if (cur!=0)
			{
				if (zero)						//ǰ������
				{
					 printCnt++ == 0 ? cout<<"ling" : cout<<" ling";
					 zero = false;
				}
				if (j == 0)
				{
					printCnt++ == 0 ? cout << num[cur] : cout << ' ' << num[cur];		//�ڸ�λ��ֱ�����
				}
				else
				{																		//������λ����Ҫ���ʮ��ǧ
					printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j];
				}
				
			}
			else
			{
				if (!zero&&j != 0 && n / J[curPos] >= 10)			//ע��100020���������
				{
					zero = true;
				}
			}
			
		}
		//������ÿ����֮����������λ��Yi/Wan
		if (i != 2 && part[i]>0)
		{
			cout << ' ' << c[i + 4];
		}
	}
}

int main()
{
    freopen("2.txt", "r", stdin);
    solution();
    system("pause");
    return 0;
}
//����ʽ�˷�����
//�ǰ���ָ�������½���˳�������
#include<iostream>
#include<iomanip>
#pragma warning(disable:4996)


using namespace std;
int k1, k2;								//k1  k2�Ǵ洢����ʽ������
int zhishu1[11], zhishu2[11];						//����ʽ1��2��ָ����ϵ����Ϣ
float xishu1[11], xishu2[11];

void solution()
{
	float res[2002] = {0};
	int num = 0;
	freopen("1.txt", "r", stdin);
	cin >> k1;
	for (int i = 0; i < k1; i++)
		cin >> zhishu1[i] >> xishu1[i];
	cin >> k2;
	for (int i = 0; i < k2; i++)
		cin >> zhishu2[i] >> xishu2[i];
	//���������е���Ϣ�����濪ʼ����

	for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k2; j++)
		{
			res[zhishu1[i] + zhishu2[j]] += xishu1[i] * xishu2[j];							//����ʽ��ˣ�ָ����ӣ�ϵ����ˣ����ϵ�����
		}
	}

	for (int i = 0; i < 2002; i++)
	{
		if (res[i] != 0)
			num++;
	}
	cout << num;
	for (int i = 2001; i >= 0 ; i--)
	{
		if (res[i]!=0)
		{
			cout << ' ' << i ;
			cout << fixed << setprecision(1) << ' ' << res[i] ;
		}
	}
}

int main()
{
	solution();
	system("pause");
	return 0;
}
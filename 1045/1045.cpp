#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int N, like[201] = {0}, stripe[10001];
void solution()
{
	int M, L;
	cin >> N >> M;
	int color;
	for (int i = 1; i <= M; i++)
	{
		cin >> color;
		like[color] = i;				//��Ϊ�Ĺ�����ɫ�Ĵ�С��ϵ
	}
	int like_num=0;
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> color;
		if (like[color])
		{
			stripe[like_num++] = like[color];			//ֻ����ϲ���ģ�������ϲ����Ҳ�ü�ȥ
		}
	}
	int dp[10001];
	int res = 0;
	for (int i = 0; i < like_num; i++)
	{
		dp[i] = 1;						//����ϲ��һ��
		for (int j = 0; j < i; j++)
		{
			if(stripe[j] <= stripe[i])	//��Ҫ�����
				dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	cout << res;
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
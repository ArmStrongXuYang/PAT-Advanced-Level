#include<iostream>
#include<vector>
#include<algorithm>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;
typedef struct
{
	int ID;				//ע��ID��ֵ�����⣬��Ȼ������������ʱ��дif(user[i].show)������������ӳ�ֵ������IDĬ�ϳ�ֵΪ0������������0��ѧ����ǰ�档
	int score[6] = { -2,-2,-2,-2,-2,-2 };
	int solved = 0;
	int total_score = 0;
	int rank;
	bool show = false;
}u;
vector<u> user;
int N, K, M;
int full_mark[6];
bool cmp(u a, u b)
{
	if (a.total_score != b.total_score)
		return a.total_score > b.total_score;
	else if (a.solved != b.solved)
		return a.solved > b.solved;
	else
		return a.ID < b.ID;
}
void solution()
{
	cin >> N >> K >> M;
	user.resize(N + 1);
	for (int i = 1; i <= K; i++)
	{
		cin >> full_mark[i];
	}
	int user_ID, problem_ID, get_score;
	for (int i = 0; i < M; i++)
	{
		cin >> user_ID >> problem_ID >> get_score;
		user[user_ID].ID = user_ID;
		if (user[user_ID].score[problem_ID]<get_score)
		{
			user[user_ID].score[problem_ID] = get_score;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (user[i].score[j] >= 0)
			{
				user[i].total_score += user[i].score[j];
				user[i].show = true;				//��һ�����0�ּ����ϾͿ������
			}
			if (user[i].score[j] == full_mark[j])
			{
				user[i].solved++;
			}
		}
	}
	sort(user.begin() + 1, user.end(), cmp);
	user[1].rank = 1;
	for (int i = 2; i <= N; i++)
	{
		user[i].rank = i;
		if (user[i].total_score == user[i - 1].total_score)
		{
			user[i].rank = user[i - 1].rank;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (user[i].show)			//ע�����������ôд�����дfor (int i = 1; i <=N&&user[i].show ; i++)����ͬ������0�֣����ʱ��С����ǰ������ں󣬵���С�Ų��ñ���������������
		{
			printf("%d %05d %d", user[i].rank, user[i].ID, user[i].total_score);
			for (int j = 1; j <= K; j++)
			{
				if (user[i].score[j] >= 0)
					cout << ' ' << user[i].score[j];
				else if (user[i].score[j] == -1)
					cout << " 0";
				else
					cout << " -";
			}
			cout << endl;
		}
	}
}

int main()
{
	freopen("3.txt", "r", stdin);
	solution();
	//system("pause");
	return 0;
}
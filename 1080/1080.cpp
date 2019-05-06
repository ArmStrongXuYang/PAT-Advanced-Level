#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int N, M, K;
typedef struct 
{
	int Ge;
	int Gi;
	int Total;
	vector<int> wish;		//־Ը����
	int ID;
}student;
vector<student> S;			//	ѧ������
int college[101];

bool cmp(student a, student b)			//������
{
	if (a.Total != b.Total)
		return a.Total > b.Total;
	else 
		return a.Ge > b.Ge;
}

void solution()
{
	cin >> N >> M >> K;
	S.resize(N);
	int temp;
	for (int i = 0; i < M; i++)
	{
		cin >> college[i];		//������������
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d ", &S[i].Ge, &S[i].Gi);
		S[i].Total = S[i].Ge + S[i].Gi;
		S[i].wish.resize(K);
		for (int j = 0; j < K; j++)				//����־Ը��Ϣ
		{
			scanf("%d", &S[i].wish[j]);
		}
		S[i].ID = i;
	}
	vector<student> S1 = S;						//����ID��Ϣ
	sort(S.begin(), S.end(), cmp);
	vector<vector<int>> res;			//��Ž��
	res.resize(M);

	for (int i = 0; i < S.size(); i++)
	{
		for (int j = 0; j < K; j++)
		{
			temp = S[i].wish[j];		//��ǰ־Ը
			if (college[temp] > 0||(S1[res[temp].back()].Ge == S[i].Ge&&S1[res[temp].back()].Total == S[i].Total))		//���������������������Ƚϱ���ѧУ���һ��ѧ���ĳɼ��͵�ǰѧ���ĳɼ�
			{
				res[temp].push_back(S[i].ID);		//Ͷ��
				college[temp]--;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		sort(res[i].begin(), res[i].end());
		for (int j = 0; j < res[i].size(); j++)
		{
			printf("%d", res[i][j]);
			if (j!= res[i].size()-1)
			{
				printf(" ");
			}
		}
		cout << endl;
	}
}

int main()
{
	freopen("2.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
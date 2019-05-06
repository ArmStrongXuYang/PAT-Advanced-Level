#include<iostream>
#include<vector>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
vector <vector<int>> g;
typedef struct
{
	int id;
	int level;
}fans;
int N, L;
int BFS(fans follow)
{
	bool visit[1001] = {0};
	queue<fans> q;
	q.push(follow);
	visit[follow.id] = true;
	int cnt = 0;			//����
	while (!q.empty())
	{
		follow = q.front();
		q.pop();
		for (int i = 0; i < g[follow.id].size(); i++)
		{
			int next_id = g[follow.id][i];
			if (!visit[next_id]&&follow.level<L)
			{
				q.push({ next_id,follow.level + 1 });		//��next_idѹ�������
				visit[next_id] = true;
				cnt++;
			}
		}
	}
	return cnt;
}
void solution()
{
	int M, input_id;
	cin >> N >> L;
	g.resize(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> input_id;
			g[input_id].push_back(i);			//ע������Ҫ����д����ΪM[i]�ǹ�ע�б����û�i��˭�ķ�˿��
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> input_id;
		cout<<BFS({ input_id,0 })<<endl;
	}
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
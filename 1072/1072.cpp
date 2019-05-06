#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#pragma warning(disable:4996)
#define MAX_NUM 2147483646
using namespace std;

int N, M, K, Ds;
bool visit[1011] = {0};

void solution()
{
	cin >> N >> M >> K >> Ds;
	vector<vector<int>> g(N + M + 1, vector<int>(N + M + 1, MAX_NUM/2));	//��ʼ��
	for (int i = 1; i <= N+M; i++)
	{
		g[i][i] = 0;				//�Խ��߳�ʼ��
	}
	string start_string, end_string;
	int input_dis;
	int start_num, end_num;

	//��������
	for (int i = 0; i < K; i++)
	{
		cin >> start_string >> end_string >> input_dis;
		if (start_string[0]=='G')
		{
			start_string=start_string.substr(1);//��ȡ���������
			start_num = stoi(start_string)+N;		//תΪ����
		}
		else
		{
			start_num = stoi(start_string);		//תΪ����
		}
		if (end_string[0]=='G')
		{
			end_string = end_string.substr(1);
			end_num = stoi(end_string)+N;
		}
		else
		{
			end_num = stoi(end_string);
		}
		g[end_num][start_num] = g[start_num][end_num] = min(g[start_num][end_num], input_dis);
	}
	int res = -1;		//��ʾδ�ҵ�
	double res_dis = -1, res_aver =MAX_NUM/2;		//��ʼ��
	for (int start_point = N+1; start_point <= N+M; start_point++)					//��ÿ��λ�ý���Dij�����·��
	{
		vector<int> dis = g[start_point];
		fill(visit, visit + 1011, false);
		//dis[start_point] = 0;			//��i��ʼ
		for (int i = 0; i < N+M; i++)			//dij�㷨
		{
			int u = -1, min_dis = MAX_NUM/2;
			for (int j = 1; j <= N+M; j++)
			{
				if (!visit[j]&&dis[j]<min_dis)
				{
					u = j;
					min_dis = dis[j];			//�ҵ�һ�������
				}
			}
			if (u == -1)
				break;
			visit[u] = true;					//������Ϊ����
			for (int k = 1; k <= N+M; k++)
			{
				if (!visit[k]&&dis[k]>dis[u]+g[u][k])
				{
					dis[k] = dis[u] + g[u][k];		//����dis����
				}
			}
		}
		double min_dis=MAX_NUM/2, min_aver=0.0;
		for (int i = 1; i <= N; i++)
		{
			if (dis[i]>Ds)							//��һ���������Χ������
			{
				min_dis = -1;
				break;
			}
			if (dis[i]<min_dis)
			{
				min_dis = dis[i];
			}
			min_aver += 1.0*dis[i];
		}
		if (min_dis==-1)//û�ҵ�
		{
			continue;  //��һ������վ
		}
		min_aver /= N;
		if (min_dis>res_dis)						//����˼���վ��������ķ��� ����Ŀǰ��֪���������
		{
			res = start_point;//�������
			res_dis = min_dis;
			res_aver = min_aver;
		}
		else if (min_dis==res_dis&&min_aver<res_aver)	//������ͬ����ƽ���������
		{
			res = start_point;
			res_aver = min_aver;
		}
		
	}
	if (res==-1)
	{
		cout << "No Solution";
	}
	else
	{
		printf("G%d\n%.1f %.1f", res - N, res_dis, res_aver);
	}

}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
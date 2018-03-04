//�Ͻ�˹�����㷨  �ͳ˷�ԭ��
//1003

#include<iostream>
#include<algorithm>
#define MAX 99999999				//�趨999999Ϊ����Զ
#pragma warning(disable:4996)

using namespace std;

int person[501];
int road[501][501];

void solution()
{
	freopen("input.txt", "r", stdin);
	int n, m, start, end;
	int road_a, road_b;
	int visit[501] = { 0 };		//Ĭ��Ϊû�з��ʵ�״̬
	int number[501] = { 0 };	//number�����·������
	int dis[501];				//dis��dij�㷨�У���㵽�������е����·��
	int rescue[501] = { 0 };	//����ĿǰΪֹ���߹��ĳ����У���Ԯ����������

	int min, k;					//������dij�㷨�е�ѭ��


	fill(road[0], road[0] + 501 * 501, MAX);
	fill(dis, dis + 501, MAX);
	cin >> n >> m >> start >> end;	//�����һ�е�ֵ    n�ǳ��е�������m��·��������start����ʼ���У�end���յ�
	for (int i = 0; i < n; i++)
	{
		cin >> person[i];		//�����Ԯ�ӵ�ֵ
	}
	for (int i = 0; i < m; i++)		//M��·���������ͼ�ı����Ϣ
	{
		cin >> road_a >> road_b;
		cin >> road[road_a][road_b];
		road[road_b][road_a] = road[road_a][road_b];
	}


	//��ʼ������start���з��ʱ��1��rescue��Ԯ�ӵ�������dis���鱣��
	//visit[start] = 1;
	rescue[start] = person[start];
	number[start] = 1;
	for (int i = 0; i < n; i++)
	{
		dis[i] = road[start][i];
	}
	dis[start] = 0;

	//��ѭ��
	for (int i = 0; i < n; i++)
	{
		min = MAX;
		for (int j = 0; j < n; j++)
		{
			if (!visit[j] && dis[j] < min)								//���ҳ�����start��̵ĵ�
			{ 
				k = j;
				min = dis[j];
			}		
		}

		visit[k] = 1;													//�����ͱ������ˣ���һ��k��start�㱾���Լ�����һ��min��0
		


		for (int j = 0; j < n; j++)
		{
			if (!visit[j]&&(min+road[k][j]<dis[j]))
			{
				dis[j] = min + road[k][j];
				number[j] = number[k];
				rescue[j] = rescue[k] + person[j];
			}
			else if (!visit[j]&&(min+road[k][j])==dis[j]&&road[k][j]!=MAX)
			{
				number[j] += number[k];
				if (rescue[k]+person[j]>rescue[j])
				{
					rescue[j] = rescue[k] + person[j];
				}
			}
		}
	}
	//���ʱ��dis�����ﱣ����Ǵ�start�㿪ʼ������������·���ĳ��ȡ�

	cout << number[end] << ' ' << rescue[end];

}

int main(void)
{
	solution();
	system("pause");
	return 0;
}
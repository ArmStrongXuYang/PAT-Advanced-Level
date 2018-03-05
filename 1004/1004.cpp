//��ϰʹ��vector��map��һЩ�÷�
//�����Ŀ����ڣ������ڵ��child��Ϣ��ʱ�򣬲��ǰ�˳������ģ����п��ܴ������ϸ����ڵ���Ϣ
//��Ȼ�����Ŀ��������һ����������������ǿ��Կ���һ����Դ������ͼ�ģ��������ͼ�ı����ǿ�����BFS��DFS
//����ʹ��BFS������ȱ���


//ÿ���ڵ��������ID�ţ���child��Ϣ������ʹ��map<int,vector<int>>���洢����һ���洢ID��Ϣ���ڶ���vector�洢child���
//BFD������ȱ�����ʱ����Ҫ��������queue��˳����ϰʹ�ö����ˡ�

#include<iostream>
#include<vector>
#include<map>

#pragma warning(disable:4996)

using namespace std;

map<int, vector<int>> trees;						//mapͼ�ı�����һ���������������map���洢���������ID��child�Ĺ�ϵ����Ӧ��map<int,vector<int>>
vector<int> res;									//res�����д�ŵ��Ƿ�Ҷ������Ϣ

void solution()
{
	freopen("3.txt", "r", stdin);
	int n, m;										//n�ǽڵ�������m�Ƿ�Ҷ��������
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int id, k, son;
		cin >> id >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> son;
			trees[id].push_back(son);				//����������child����Ϣ
		}
	}
	//�����Ѿ����������е�ID���亢�ӵ���Ϣ�ˣ�ע�⣬���������˳�򲢷ǰ��մӸ��ڵ㿪ʼ��˳��
	
	//BFS�㷨
	//res.push_back(0);								//��ʼ������һ���Ȱѷ�Ҷ�����Ϊ0
	vector<int> now, next = {1};					//�����������У�һ���ǽ�����Ҫ���ʵĲ�Σ�һ�����������ڷ��ʵĲ��
	int floor = 0;									//��ʼ�ǵ�0�㣬��������Ϣ	
	while (!next.empty())							//�����зǿգ���һֱ����
	{
		res.push_back(0);							//�µ�һ��
		now = next;
		next.clear();
		for (auto i = now.begin(); i < now.end(); i++)
		{
			if (!trees[*i].empty())
				for (vector<int>::iterator j = trees[*i].begin(); j < trees[*i].end(); j++)
					next.push_back(*j);
			else
				res[floor]++;
		}
		floor++;
	}



	//������
	cout << res[0];
	//int k = res.size();
	for (int i = 1; i < res.size(); i++)
	{
		cout <<' '<<res[i];
	}


}


int main()
{
	solution();
	system("pause");
	return 0;
}
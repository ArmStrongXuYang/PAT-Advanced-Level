#include<iostream>
#include<vector>
#pragma warning(disable:4996)

using namespace std;
vector<int> post, in, level(100000, -1);
//level���ڴ�Ŷ�������������ö����������Ա�洢�����������Ļ����򵥣�����Ҳ�ܺ�ֱ�۵Ľ��в�α�����
void pre(int root, int start, int end, int index)
{
	if (start > end)
		return;
	int i = start;
	while (i < end&&in[i] != post[root])
		i++;
	level[index] = post[root];
	pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
	pre(root-1, i + 1, end, 2 * index + 2);
}
void solution()
{
	//total���ڴ洢��һ��ֵ�����ж��ٸ�����
	//isFirst���ڱ���Ƿ����������
	int total, isFirst = false;
	cin >> total;
	in.resize(total);
	post.resize(total);
	for (int i = 0; i < total; i++)
	{
		cin >> post[i];
	}
	for (int i = 0; i < total; i++)
	{
		cin >> in[i];
	}


	//����������
	pre(total - 1, 0, total - 1, 0);


	for (int i = 0; i < level.size(); i++)
	{
		if (level[i] != -1)
		{
			if (isFirst)
				cout << ' ';
			cout << level[i];
			isFirst++;
		}
		if (isFirst == total)
			return;
	}

}
int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
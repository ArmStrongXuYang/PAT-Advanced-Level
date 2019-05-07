#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int N, cnt, pre[100], in[100], post[100];
int len = 0, n;
bool build(int l1, int r1, int l2, int r2)
{
	if (l1 > r1)
		return false;
	if (l1==r1)
	{
		in[++len] = pre[l1];
		return true;
	}
	int i = l2;
	while (pre[l1 + 1] != post[i])			//ȷ���������ĸ��ں�������е�λ��
		i++;
	bool res;
	res = build(l1 + 1, l1 + 1 + i - l2, l2, i);			//i-l2��ʾ�������ж��ٸ��ڵ㣬���l1+1+(i-l2)��ʾ��������ǰ���е�λ��
	in[++len] = pre[l1];
	res = build(l1 + 2 + i - l2, r1, i + 1, r2 - 1);
	return res;
}



void solution()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> pre[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> post[i];
	}
	if (build(1, N, 1, N))
	{
		cout << "Yes" << endl;
	}
	else
		cout << "No" << endl;
	for (int i = 1; i <= len; i++)
	{
		cout << in[i];
		if (i!=len)
		{
			cout << ' ';
		}
	}
	cout << endl;			//��������ᵼ�¸�ʽ����
}

int main()
{
	freopen("1.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
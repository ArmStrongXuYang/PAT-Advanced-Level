#include<iostream>
#pragma warning(disable:4996)

using namespace std;

int k = 0;
int num[10001] = { 0 };
int flag = 0;
int temp = 0, sum = 0;						//temp��ʾ��ʱ�ͣ�sum��ʾ��ǰ��֪������
int tempstart = 0;
int start = 0, over = 0;								//start��ʾ���������еĿ�ʼ��end��ʾ����
int solution()
{
	//int *num = (int *)malloc(10001 * sizeof(int));
	freopen("11.txt", "r", stdin);
	cin >> k;
	for (int i = 0; i < k; i++)				//������K�������������������ô�ѱ��Ϊ��Ϊ1
	{
		cin >> num[i];
		if (num[i]>=0)
		{
			flag = 1;
		}
	}
	if (!flag)
	{
		cout << "0 " << num[0] << ' ' << num[k - 1];
		return 0;
	}
	
	for (int i = 0; i < k; i++)				//������������һ��������
	{
		temp += num[i];
		
		if (temp < 0)
		{
			temp = 0;
			tempstart = i + 1;				//�����ǰ��С��0�ˣ���Ϊ0�����Ҵ���һ����ʼ
			continue;
		}
		if (temp > sum)
		{
			start = num[tempstart];
			over = num[i];
			sum = temp;
		}


	}

	cout << sum << ' ' << start << ' ' << over;
	return 0;
}

int main()
{
	solution();
	system("pause");
	return 0;
}
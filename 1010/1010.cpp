//˼·������
//1����Ҫ��ÿ���������ʮ���ƣ�����Ƚϡ�
//2�������Ľ���ֻ���ڣ����������������+1��~max(��һ������ֵ���������)+1�������1������������ɣ��и�����  ��Ϊ��������������5 5 1 10�����������Ȼ��6���Ʒ���Ҫ��
//3��ʹ�ö��ַ�����
//4��pow�����ķ���ֵ��double����longlongint �У������ܴ��ʱ�򣬻ᶪʧ���ȣ����Ի���Ҫ�Լ�дһ���˷�����

#include<iostream>
#include<string>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;
string n1, n2;
int tag, radix;
unsigned long long n1_10, n2_10;


unsigned long long tras(string n, unsigned long long rad)
{
	int num;								//��ʾλ��
	unsigned long long res = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] <= 'z'&&n[i] >= 'a')			//����������a~z֮��
			res = res*rad + (n[i] - 'a' + 10);
		else
			res = res*rad + (n[i] - '0');
	}
	return res;
}

unsigned long long getrad(string n)		//�õ����Ǳ��ַ����������뻹��1�����������ֲ��ҷ�����㡣
{
	int zuida = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] <= 'z'&&n[i] >= 'a')			//����������a~z֮��
			zuida = zuida >(n[i] - 'a' + 10) ? zuida : (n[i] - 'a' + 10);
		else
			zuida = zuida > (n[i] - '0') ? zuida : (n[i] - '0');
	}
	return zuida+1;
}

void solution()
{
	
	cin >> n1 >> n2 >> tag >> radix;
	unsigned long long low, high, mid;
	//�����n1����n2�ľ���10����ֵ������������С�n1==n2ʱ���ҵ����ơ�����û��
	//���Ƶ���Сֵ��n2�����������+1�����ֵ��n1��ʮ����ֵ����Ϊ������������10000000 10 1 10��
	if (tag == 2) { string temp = n1;  n1 = n2; n2 = temp; }

	n1_10 = tras(n1, radix);
	low = getrad(n2);
	high = (n1_10+1) > getrad(n2) ?  (n1_10+1) : getrad(n2);


	while (low<=high)
	{
		mid = (low + high) / 2;
		if (tras(n2, mid) > n1_10)
			high = mid - 1;
		else if (tras(n2, mid) < n1_10)
			low = mid + 1;
		else
		{
			cout << mid;
			return;
		}
	}

		cout << "Impossible";


}


int main()
{
	freopen("7.txt", "r", stdin);
	solution();

	system("pause");
	return 0;
}
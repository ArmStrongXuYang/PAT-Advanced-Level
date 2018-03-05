//��Ŀ���⣬��һ�����룬������������ĳ������������ǰ�����
//���ӡyes���������������������ĺ�����������
//��һ��ǰ������л�ԭ������
#include<iostream>
#pragma warning(disable:4996)

using namespace std;

struct node
{
	node* LeftChild=NULL;
	node* RightChild=NULL;
	int value=0;
}Node[1010],MNode[1010];

int Num;
bool BST = true;
int j = 0;
bool Output = false;
void PreOrder(node* T)							
{
	if (T!=NULL)
	{
		if (T->value == Node[j].value)
			j++;
		else
		{
			BST = false;
			return;
		}
		PreOrder(T->LeftChild);
		PreOrder(T->RightChild);
		
	}
}


void PostOrder(node* T)							//�������������
{
	
	if (T!=NULL)
	{
		PostOrder(T->LeftChild);
		PostOrder(T->RightChild);
		if (!Output)
		{
			cout << T->value;
			Output = true;
		}
		else
		{
			cout << ' ' << T->value;
		}
		
	}
}


void solution()
{
	cin >> Num;
	node* p = &Node[0];
	cin >> Node[0].value;
	bool SetNode = false;
	for (int i = 1; i < Num; i++)
	{
		cin >> Node[i].value;
		SetNode = false;
		p = Node;
		while (!SetNode)
		{
			if (p->value>Node[i].value)				//Ҫ�ŵ�������
			{
				if (p->LeftChild == NULL)
				{
					p->LeftChild = &Node[i];
					SetNode = true;
					break;
				}
				else
				{
					p = p->LeftChild;
				}
			}
			else
			{
				if (p->RightChild==NULL)
				{
					p->RightChild = &Node[i];
					SetNode = true;
					break;
				}
				else
				{
					p = p->RightChild;
				}
			}
		}
		
	}

	PreOrder(Node);
	if (BST)
	{
		cout << "YES" << endl;
		PostOrder(Node);
	}
	else 
	{
		//���ǲ��Ǿ���BST
		for (int i = 0; i < Num; i++)
		{
			node* temp;
			temp = Node[i].LeftChild;
			Node[i].LeftChild = Node[i].RightChild;
			Node[i].RightChild = temp;
		}

		BST = true;
		j = 0;

		PreOrder(Node);
		if (BST)
		{
			cout << "YES" << endl;
			PostOrder(Node);
		}
		else
			cout << "NO";
	}
}

int main()
{
	freopen("6.txt", "r", stdin);
	solution();
	system("pause");
	return 0;
}
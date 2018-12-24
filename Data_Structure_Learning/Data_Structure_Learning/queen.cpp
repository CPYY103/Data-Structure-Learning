#include<stdio.h>
#include"misc.h"

static int a[20][20] = { 0 };
static int n;
static int count = 0;

static void queen(int i, int j);
static bool check(int i, int j);


void Queen_n(int x)
{
	n = 8;
	queen(0, 0);
	printf("%d Queens %d Solutions\n", n, count);

}

void queen(int i, int j)
{

	if (j == n)		//�Ҳ�Խ�磬��ʾ�Ѿ�����
		return;
	if (check(i, j))//����ܷ�
	{
		a[i][j] = 1;
		if (i == n - 1)  //����Ѿ��������һ�У���ʾ��������¼
		{
			count++;
			for (int ii = 0; ii<n; ii++)
			{
				for (int jj = 0; jj<n; jj++)
					printf("%3d", a[ii][jj]);
				printf("\n");
			}
			printf("\n\n");
		}
		else
			queen(i + 1, 0); //����һ������߿�ʼ��
	}

	a[i][j] = 0;//���λ�ò��ܷţ�д0�ÿ�
				//���λ���ܷţ���ʱ����Ĵ����Ѿ�ִ�У��Ѿ���¼����һ��������ÿգ��ж�����λ��
	queen(i, j + 1);
}

bool check(int i, int j)
{
	int ii;
	for (ii = 0; ii < n; ii++)
	{
		if (a[i][ii] || a[ii][j])		//���������лʺ�
			return 0;
		if ((i - ii >= 0 && j - ii >= 0 && a[i - ii][j - ii]) || (i + ii < n && j + ii < n && a[i + ii][j + ii]))	//���ϵ�����
			return 0;
		if ((i - ii >= 0 && j + ii < n && a[i - ii][j + ii]) || (i + ii < n && j - ii >= 0 && a[i + ii][j - ii]))	//���µ�����
			return 0;
	}
	return 1;

}

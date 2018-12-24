#include<stdio.h>
#include<stdlib.h>
#include "sort.h"


void SortTest()
{
	int A[] = { 3,5,1,6,4,9,7,8,2 };
	int i;
	int n = sizeof(A) / sizeof(A[0]);

	printf("Before Sort:\n");
	for (i = 0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");

	InsertSort(A, n);
	//InsertSort_2(A, n);
	//ShellSort(A, n);
	//ShellSort_2(A, n);
	//BubbleSort(A, n);
	//BubbleSort_2(A, n);
	//QuickSort(A, 0, n - 1);
	//QuickSort_2(A, 0, n - 1);
	//printf("A[%d]: %d \n",7,  K_Elem(A, 0, n - 1, 7));
	//SelectSort(A, n);
	//SelectSort_2(A, n);
	//HeapSort(A, n);
	//MergeSort_1(A, 0, n - 1);
	//MergeSort_2(A, n);
	//CountSort(A, n);

	printf("Sorted:\n");
	for (i = 0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");

	//Sort_2();
}


void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

//��������  
void InsertSort(int A[], int n)
{
	int i, j, temp;
	for (i = 1; i<n; i++)
	{
		temp = A[i];
		for (j = i - 1; j >= 0 && A[j] > temp; j--)
			A[j + 1] = A[j];
		A[j + 1] = temp;
	}
}

//�۰�������򣨶��ֲ��룩 
void InsertSort_2(int A[], int n)
{
	int i, j, temp;
	int left, right, mid;
	for(i = 1; i < n; i++)
	{
		temp = A[i];
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (A[mid]>temp)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (j = i - 1; j >= right + 1; j--)
			A[j + 1] = A[j];
		A[right + 1] = temp;
	}
}

//ϣ������
void ShellSort(int A[], int n)
{
	int step = 0;
	int i, j, temp;
	while (step <= n)
		step = 3 * step + 1;	//�����ɵ�
	for (step; step >= 1; step = (step - 1) / 3)
		for (i = step; i < n; i++)
		{
			temp = A[i];
			for (j = i - step; j >= 0 && A[j] > temp; j -= step)
				A[j + step] = A[j];
			A[j + step] = temp;
		}
}

//ϣ������֮�� 
void ShellSort_2(int A[], int n)
{
	int step;
	int i, j, temp;
	for (step = n / 2; step >= 1; step /= 2)
		for (i = step; i < n; i++)
		{
			temp = A[i];
			for (j = i - step; j >= 0 && A[j] > temp; j -= step)
				A[j + step] = A[j];
			A[j + step] = temp;
		}

}

//ð������
void BubbleSort(int A[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
			if (A[j] > A[j + 1])
				swap(&A[j], &A[j + 1]);                         }
//ð������˫�򣬴������ң���������ð��
void BubbleSort_2(int A[], int n)
{
	int left = 0, right = n - 1, i;
	while (left<right)
	{
		for (i = left; i<right; i++)
			if (A[i]>A[i + 1])
				swap(&A[i], &A[i + 1]);
		right--;
		for (i = right; i>left; i--)
			if (A[i - 1]>A[i])
				swap(&A[i - 1], &A[i]);
		left++;
	}
}

//��������
void QuickSort(int A[], int left, int right)
{
	if (left >= right)
		return;
	int temp = A[left]; //��׼��
	int i = left, j = right;
	while (i<j)
	{
		while (A[j] >= temp && i<j)
			j--;
		while (A[i] <= temp && i<j)
			i++;
		if (i<j)
			swap(&A[i], &A[j]);
	}
	A[left] = A[i];		//��׼����λ  
	A[i] = temp;		//swap(&A[i], &A[left])

	QuickSort(A, left, i - 1); 	
	QuickSort(A, i + 1, right); 
}
//��������֮�������ݻ�׼���±�
int partition(int A[], int left, int right)   //��ȡ�±� 
{
	int temp = A[left];
	while (left<right)
	{
		while (left<right && A[right] >= temp)
			right--;
		A[left] = A[right];   //��С�ڻ�׼������������� 

		while (left<right && A[left] <= temp)
			left++;
		A[right] = A[left];   //�Ѵ��ڻ�׼�����������ұ�
							  //��ֵǰ��A[right]�ϵ����Ѿ�ͨ����һ�������˳�ʼ��A[left]�� 
	}
	A[left] = temp;    //��׼����λ 
	return left;
}
void QuickSort_2(int A[], int left, int right)
{
	if (left >= right)
		return;
	int i = partition(A, left, right);
	QuickSort_2(A, i + 1, right);
	QuickSort_2(A, left, i - 1);
}
//��������Ӧ��֮ѡ���±�k����
int K_Elem(int A[], int left, int right, int k)
{
	if (left >= right)
		return 0;
	int temp = A[left];
	int i = left, j = right;
	while (i<j)
	{
		while (i<j && A[j] >= temp)
			j--;
		while (i<j && A[i] <= temp)
			i++;

		if (i<j)
			swap(&A[i], &A[j]);
	}
	swap(&A[i], &A[left]);

	if (i == k)
		return A[k];
	else if (i>k)     //��ǰһ�����в��� 
		return K_Elem(A, left, i - 1, k);
	else 				//�ں�һ�����в���
		return K_Elem(A, i + 1, right, k);
}
//ѡ������
void SelectSort(int A[], int n)
{
	int min, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (A[j]<A[min])
				min = j;
		if (min != i)
			swap(&A[i], &A[min]);
	}
}
//˫��ѡ������
void SelectSort_2(int A[], int n)
{
	int min, max, i, j;
	for (i = 0; i < n - i; i++)
	{
		min = max = i;
		for (j = i + 1; j < n - i; j++)
		{
			if (A[j] > A[max])   
				max = j;
			if (A[j] < A[min])
				min = j;

		}
		if (min != i)
			swap(&A[i], &A[min]);
		if (max != n - i - 1)
			if (max == i)		//������ֵ�ǵ�һ������ʱ�����ֵ��ͨ����һ������ԭminλ����
				swap(&A[min], &A[n - i - 1]);
			else
				swap(&A[max], &A[n - i - 1]);
	}
}

//������
//������±�0��ʼ�����������±�1��ʼ��i��ʼΪ n/2�������� 
//��������� 
void BuildMaxHeap(int A[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		AdjustHeap(A, i, n);	//�Ӻ���ǰ��һ����Ҷ���
}
//���µ�����
void AdjustHeap(int A[], int i, int n)
{
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	int max = i;
	if (left_child<n && A[left_child]>A[max])
		max = left_child;
	if (right_child<n && A[right_child]>A[max])
		max = right_child;
	if (max != i)
	{
		swap(&A[i], &A[max]);
		AdjustHeap(A, max, n);
	}
}
void HeapSort(int A[], int n)
{
	int i;
	BuildMaxHeap(A, n);
	printf("isMaxHeap: %d\n", isMaxHeap(A, n));
	for (i = n - 1; i >= 0; i--)
	{
		swap(&A[0], &A[i]);     //���Ѷ������������������һ�������� 
		AdjustHeap(A, 0, i);
	}

}
bool isMaxHeap(int A[], int n)
{
	if (n % 2 == 0)			//��һ������֧���
	{
		if (A[n / 2] < A[n])
			return false;
		n--;
	}
	for (int i = n / 2; i >= 1; i--)
		if (A[i] < A[i * 2] || A[i] < A[i * 2 + 1])
			return false;
	return true;
}

//�鲢����
//�ϲ� 
void merge(int A[], int left, int mid, int right)
{
	int *B = (int *)malloc((right - left + 1) * sizeof(int));		//����Ϊȫ��
	int i = left, j = mid + 1, index = 0;
	int len = right - left + 1;
	while (i <= mid&&j <= right)
		B[index++] = A[i] <= A[j] ? A[i++] : A[j++];
	while (i <= mid)
		B[index++] = A[i++];
	while (j <= right)
		B[index++] = A[j++];
	for (i = 0; i<len; i++)
		A[left++] = B[i];

}
//�鲢���ݹ� 
void MergeSort_1(int A[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	MergeSort_1(A, left, mid);
	MergeSort_1(A, mid + 1, right);
	merge(A, left, mid, right);
}
//�鲢���ǵݹ�
void MergeSort_2(int A[], int n)
{
	int left, mid, right, i;
	for (i = 1; i<n; i *= 2)
	{
		left = 0;
		while (left + i<n)
		{
			mid = left + i - 1;
			right = mid + i<n ? mid + i : n - 1;
			merge(A, left, mid, right);
			left = right + 1;
		}
	}
}
//�������򣬶�������
void CountSort(int A[], int n)
{
	int i, j = 0, max = A[0], min = A[0];
	for (i = 1; i<n; i++) {
		max = max<A[i] ? A[i] : max;
		min = min>A[i] ? A[i] : min;
	}
	int len = max - min + 1;
	int *B = (int *)malloc((len + 1) * sizeof(int));
	for (i = 0; i<len + 1; i++)
		B[i] = 0;

	for (i = 0; i<n; i++)
		B[A[i] - min + 1]++;

	for (i = 1; i <= len; i++)
		while (B[i])
		{
			A[j++] = i;
			B[i]--;
		}
}
//������Ȼ����1��ʼ�������±��1��ʼ��
void Sort_2()
{
	int A[10] = { 0,4,5,3,6,8,1,9,7,2 };
	int i, t, n = 9;
	for (i = 1; i < n + 1; i++)		//һ�������©��
	{
		t = A[A[i]];
		A[A[i]] = A[i];
		A[i] = t;
	}
	for (i = 1; i < n + 1; i++)
	{
		t = A[A[i]];
		A[A[i]] = A[i];
		A[i] = t;
	}
	for (i = 1; i < n + 1; i++)
		printf("%d ", A[i]);
	printf("\n");
}
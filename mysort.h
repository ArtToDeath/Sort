#ifndef MYSORT__H
#define MYSORT__H

#define MAXSIZE 1000
//�������� 
void InsertSort(int r[], int n);//ֱ�Ӳ�������,ƽ��ʱ�临�Ӷ�O(n^2) 
void ShellSort(int r[], int n);//ϣ������ƽ��ʱ�临�Ӷ�O(nlogn)~O(n^2),���ȶ����� 

//��������
void BubbleSort(int r[], int n);//ð������ƽ��ʱ�临�Ӷ�O(n^2) 
void Qsort(int r[], int i, int j);//��������ƽ��ʱ�临�Ӷ�O(nlogn)�����ȶ����򣬸����ռ�O(logn)~O(n) 
int Partion(int r[], int first, int end);//���ŷ���ʵ�� 

//ѡ������
void SelectSort(int r[], int n);//��ѡ������, ƽ��ʱ�临�Ӷ�O(n^2)�����ȶ�����
void HeapSort(int r[], int n);//������ƽ��ʱ�临�Ӷ�O(nlogn),���ȶ����� 
void Sift(int r[], int k, int m);//�����ɸѡ 

//�鲢����
void MergeSort(int r[], int r1[], int n);//��·�鲢����ƽ��ʱ�临�Ӷ�O(nlogn)�������ռ�O(n) 
void MergeSort(int r[], int r1[], int s, int t);
void Merge(int r[], int r1[], int s, int m, int t);//�鲢r[s]~r[m]��r[m+1]~r[t]�õ�r1[s]~r1[t] 
void MergePass(int r[], int r1[], int n, int h);//����һ������ 

#endif

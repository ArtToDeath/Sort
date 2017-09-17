#ifndef MYSORT__H
#define MYSORT__H

#define MAXSIZE 1000
//插入排序 
void InsertSort(int r[], int n);//直接插入排序,平均时间复杂度O(n^2) 
void ShellSort(int r[], int n);//希尔排序，平均时间复杂度O(nlogn)~O(n^2),不稳定排序 

//交换排序
void BubbleSort(int r[], int n);//冒泡排序，平均时间复杂度O(n^2) 
void Qsort(int r[], int i, int j);//快速排序，平均时间复杂度O(nlogn)，不稳定排序，辅助空间O(logn)~O(n) 
int Partion(int r[], int first, int end);//快排分区实现 

//选择排序
void SelectSort(int r[], int n);//简单选择排序, 平均时间复杂度O(n^2)，不稳定排序
void HeapSort(int r[], int n);//堆排序，平均时间复杂度O(nlogn),不稳定排序 
void Sift(int r[], int k, int m);//大根堆筛选 

//归并排序
void MergeSort(int r[], int r1[], int n);//二路归并排序，平均时间复杂度O(nlogn)，辅助空间O(n) 
void MergeSort(int r[], int r1[], int s, int t);
void Merge(int r[], int r1[], int s, int m, int t);//归并r[s]~r[m]和r[m+1]~r[t]得到r1[s]~r1[t] 
void MergePass(int r[], int r1[], int n, int h);//进行一趟排序 

#endif

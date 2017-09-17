#include "mysort.h" 

void InsertSort(int r[], int n)
{
	int k = r[0];
	int j = 0;
	for(int i = 1; i < n; i ++){
		if(r[i] < r[i-1]){
			k = r[i];
			r[i] = r[i-1];
			for(j = i - 2; k < r[j]; j --){
				r[j+1] = r[j];
			}
			r[j+1] = k;
		}
	}
}

void ShellSort(int r[], int n)
{
	int k = r[0];
	int j = 0;
	for(int d = n/2; d >=1; d = d/2){
		for(int i = d; i < n; i ++){
			if(r[i] < r[i - d]){
				k = r[i];
				for(j = i - d; j >= 0 && k < r[j]; j -= d){
					r[j + d] = r[j];
				}
				r[j + d] = k;
			}
		}
	}
}

void BubbleSort(int r[], int n)
{
	int pos = n;	//初始化时无序元素的范围 
	while(pos != 0){
		int bound = pos;	//本趟无序元素的范围 
		pos = 0;
		for(int i = 0; i < bound - 1; i ++){
			if(r[i] > r[i + 1]){
				int temp = r[i];
				r[i] = r[i + 1];
				r[i + 1] = temp;
				pos = i + 1;
			}
		}
	}
}

void Qsort(int r[], int i, int j)
{
	if(i < j){
		int pivotloc = Partion(r, i, j);
		Qsort(r, i, pivotloc - 1);			//左分区快排 
		Qsort(r, pivotloc + 1, j);			//右分区快排 
	}
}
int Partion(int r[], int first, int end)
{
	int i = first;
	int j = end;
	int pivot = r[i];//基准元素分界 
	
	while(i < j){
		while((i < j) && (r[j] >= pivot))	//右侧扫描，寻找<pivot的元素前移 
			j--;
		r[i] = r[j];
		while((i < j) && (r[i] <= pivot))	//左侧扫描，寻找>pivot的元素后移 
			i++;
		r[j] = r[i];
	}
	r[i] = pivot;
	return i;
}

void SelectSort(int r[], int n)
{
	for(int i = 0; i < n; i ++){
		int index = i;			//查找最小记录的位置index 
		for(int j = i + 1; j < n; j ++){
			if(r[j] < r[index])
				index = j;
		}
		if(index != i){
			int temp = r[i];
			r[i] = r[index];
			r[index] = temp;
		}
	}
}

void HeapSort(int r[], int n)
{
	for(int i = n/2; i >= 0; i --)//建堆 
		Sift(r, i, n-1);
	for(int i = n-1; i > 0; i --){//堆排序 
		int temp = r[0]; 
		r[0] = r[i];
		r[i] = temp;//输出堆顶元素 
		Sift(r, 0, i-1);//重新建堆 
	}
} 
void Sift(int r[], int k, int m)//k是被“筛选”结点的编号，m是最后一个结点的编号
{
	int i = k, j = 2 * i;
	while(j <= m){//j存在 
		if(j < m && r[j] < r[j+1]) j ++;//j是左右结点中的较大者 
		if(r[i] >= r[j]) break; //符合大根堆的条件 
		else{					//根结点与孩子结点交换 
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i = j;
			j = 2 * i;//待比较结点下移 
		}
	}
} 

void MergeSort(int r[], int r1[], int n)
{
	int h = 1;
	while(h <= n){
		MergePass(r, r1, n, h);
		h = 2 * h;
		MergePass(r1, r, n, h);
		h = 2 * h;
	} 
}

void MergeSort(int r[], int r1[], int s, int t)
{
	int r2[MAXSIZE];
	if(s == t) r1[s] = r[s];
	else{
		int m = (s + t) / 2;
		MergeSort(r, r2, s, m);
		MergeSort(r, r2, m+1, t);
		
		Merge(r2, r1, s, m, t);
	}
}

void Merge(int r[], int r1[], int s, int m, int t)
{
	int i = s;		//指向r[s~m] 
	int j = m + 1;	//指向r[m+1~t] 
	int k = s;		//指向r1
	while(i <= m && j <= t){
		if(r[i] < r[j])
			r1[k ++] = r[i ++];
		else
			r1[k ++] = r[j ++];
	} 
	while(i <= m) r1[k ++] = r[i ++]; //r[s~m]未处理完 
	while(j <= t) r1[k ++] = r[j ++]; //r[m+1~t]未处理完 
}

void MergePass(int r[], int r1[], int n, int h)
{
	int i = 0;
	while(i <= n - 2*h){
		Merge(r, r1, i, i + h - 1, i + 2*h - 1);	//长度为h的序列两两归并 
		i += 2*h;
	}
	if(i < n - h)
		Merge(r, r1, i, i + h - 1, n - 1);	//两个序列，其中一个长度小于h 
	else
		for(;i < n; i ++)	//只有一个小于等于h的序列 
			r1[i] = r[i];
} 

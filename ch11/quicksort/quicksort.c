#include <stdio.h>
#include <stdlib.h>

void printarr(int *a, int n);
void quicksort(int *a, int l, int r);
void swap(int *a, int l, int r);
int partition(int *a, int l, int r);

int main(int argc, char **argv) {
	int a0[5] = {0, 1, 2, 3, 4};
	quicksort(a0, 0, 4);
	printarr(a0, 5);

	int a1[10] = {8, 10, 9, 5, 6, 4, 7, 1, 2, 3};
	quicksort(a1, 0, 9);
	printarr(a1, 10);

	int a2[16] = {8, 10, 9, 5, 6, 4, 7, 1, 2, 3, 100, 13, 12, 15, 11, 14};
	quicksort(a2, 0, 15);
	printarr(a2, 16);

	return 0;
}

void printarr(int *a, int n) {
	for(int i=0;i<n;++i)	printf("%d\t", a[i]);
	printf("\n");
}

void quicksort(int *a, int l, int r) {
	if(l<r) {
		if(r>l+1) {
			int flag = 0;
			for(int i=l;i<r;++i) {
				if(a[i]>a[i+1]) {
					flag = 1;
					break;
				}
			}
			if(!flag)	return;

			int mid = (l+r)>>1;
			if(a[mid]>a[l])	swap(a, mid, l);
			if(a[l]>a[r])	swap(a, r, l);
			if(a[mid]>a[l])	swap(a, mid, l);

			int part = partition(a, l, r);
			quicksort(a, l, part-1);
			quicksort(a, part+1, r);

		}else {
			if(a[l]>a[r]) {
				int tmp = a[l];
				a[l] = a[r];
				a[r] = tmp;
			}
		}
	}
}

void swap(int *a, int l, int r) {
	int tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}

int partition(int *a, int l, int r) {
	if(l<r) {
		if(r==l+1) {
			if(a[l]>a[r])	swap(a, l, r);
			return l;
		}

		int mid = (l+r)>>1;
		if(a[l]>a[r])	swap(a, l, r);
		if(a[r]>a[mid])	swap(a, r, mid);
		if(a[l]>a[r])	swap(a, l, r);

		int i=l-1, j=l;
		while(j<r) {
			if(a[j]<a[r]) {
				++i;
				if(i!=j)	swap(a, i, j);
			}
			++j;
		}
		++i;
		swap(a, i, r);
		return i;

	}else if(l==r)	return l;
	else	return -1;

	/*
	int tmp, i=l+1, j=r;
	while(i<j) {
		while(a[i]<a[l] && i<=j)	++i;
		while(a[l]<=a[j] && i<=j)	--j;
		if(i<j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			++i;
			--j;
		}
	}
	if(i==j) {
		if(a[l]<=a[i]) {
			if(l!=i-1)	swap(a, l, i-1);
			return i-1;
		}else {
			swap(a, l, i);
			return i;
		}
	}else {
		swap(a, l, i-1);
		return i-1;
	}
	*/
}


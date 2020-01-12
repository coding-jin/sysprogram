#include <stdio.h>
#include <stdlib.h>

int partition(int *a, int l, int r);
void quicksort(int *a, int l, int r);
void swap(int *t1, int *t2);
void printarr(int *a, int l, int r);
int kth(int *a, int l, int r, int k);

int main(int argc, char **argv) {
	int a[16] = {8, 10, 9, 5, 6, 4, 7, 1, 2, 3, 100, 13, 12, 15, 11, 14};
	quicksort(a, 0, 15);
	printarr(a, 0, 15);

	printf("14th=%d\n", kth(a, 0, 15, 14));
	return 0;
}

int partition(int *a, int l, int r) {
	if(r>l) {
		int i=l-1, j=l;
		while(j<r) {
			if(a[j]<a[r]) {
				++i;
				if(i != j)	swap(&a[i], &a[j]);
			}
			++j;
		}
		++i;
		if(i != r)	swap(&a[i], &a[r]);
		return i;
	}else if(r==l)	return l;
	else	return -1;
}

void swap(int *t1, int *t2) {
	int t = *t1;
	*t1 = *t2;
	*t2 = t;
}

void quicksort(int *a, int l, int r) {
	if(l<r) {
		int mid = partition(a, l, r);
		quicksort(a, l, mid-1);
		quicksort(a, mid+1, r);
	}
}

void printarr(int *a, int l, int r) {
	for(int i=l;i<=r;++i)	printf("%d\t", a[i]);
	printf("\n");
}

int kth(int *a, int l, int r, int k) {
	int mid = partition(a, l, r);
	if(mid==k)	return a[mid];
	while(mid != k) {
		if(mid>k)	mid = partition(a, l, mid-1);
		else {
			k = k-mid;
			mid = partition(a, mid+1, r);
		}
	}
	return a[mid];
	/* recursive
	int mid = partition(a, l, r);
	if(mid==k)	return a[mid];
	else if(mid>k)	return kth(a, l, mid-1, k);
	else	return kth(a, mid+1, r, k-mid);
	*/

}


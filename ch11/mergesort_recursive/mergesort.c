#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int l1, int r1, int l2, int r2);
void printarr(int *a, int l, int r);
void mergesort(int *a, int l, int r);

int main(int argc, char **argv) {

	/*
	int a[9] = {5, 2, 4, 7, 1, 3, 8, 2, 6};
	mergesort(a, 0, 8);
	printarr(a, 0, 8);
	*/
	int a[1] = {100};
	mergesort(a, 0, 0);
	printarr(a, 0, 0);
	return 0;
}

void merge(int *a, int l1, int r1, int l2, int r2) {
	if(l1==r1 && r1==l2 && l2==r2)	return;
	if(r1<l1 || r2<l2)	return;
	int n1 = r1-l1+1;
	int n2 = r2-l2+1;
	int *arr = (int*)malloc(sizeof(int)*(n1+n2));
	if(arr==NULL) {
		printf("failed to malloc\n");
		exit(1);
	}

	int i=l1, j=l2, arri=0;
	while(i<=r1 && j<=r2) {
		if(a[i]<=a[j])	arr[arri++]=a[i++];
		else			arr[arri++]=a[j++];
	}

	if(i>r1)
		while(j<=r2)	arr[arri++] = a[j++];
	else
		while(i<=r1)	arr[arri++] = a[i++];


	for(i=0;i<n1;++i)	a[l1+i] = arr[i];
	for(i=0;i<n2;++i)	a[l2+i] = arr[n1+i];

	free(arr);
}

void printarr(int *a, int l, int r) {
	if(l>r)	return;
	for(int i=l;i<=r;++i)	printf("%d\t", a[i]);
	printf("\n");
}

void mergesort(int *a, int l, int r) {
	if(l>=r)	return;

	int mid = (l+r)/2;
	mergesort(a, l, mid);
	mergesort(a, mid+1, r);
	merge(a, l, mid, mid+1, r);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void merge(int *a, int l1, int r1, int l2, int r2);
void merge(int *a, int l, int mid, int r);
void printarr(int *a, int l, int r);
void mergesort(int *a, int l, int r);
void bbsort(int *a, int l, int r);
int numpow2(int n);
int setcounter(int delta, int length);

int main(int argc, char **argv) {

	int a0[9] = {5, 2, 4, 7, 1, 3, 8, 2, 6};
	mergesort(a0, 0, 8);
	printarr(a0, 0, 8);
	
	int a1[16] = {100, 4, 1, 2, 3, 6, 5, 7, 8, 9, 11, 10, 13, 12, 14, 15};
	mergesort(a1, 0, 15);
	printarr(a1, 0, 15);

	int a2[15] = {100, 4, 1, 2, 3, 6, 5, 7, 8, 9, 11, 10, 13, 12, 14};
	mergesort(a2, 0, 14);
	printarr(a2, 0, 14);

	int a3[9] = {100, 1, 3, 2, 8, 4, 5, 6, 7};
	mergesort(a3, 0, 8);
	printarr(a3, 0, 8);
	return 0;
}
/*
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
*/

void merge(int *a, int l, int mid, int r) {
	if(l>=r)	return;

	int length = r-l+1;
	int *arr = (int*)malloc(sizeof(int)*length);
	if(arr==NULL) {
		printf("fail to malloc for arr\n");
		return;
	}
	int i=l, j=mid+1, arri=0;
	while(i<=mid && j<=r) {
		if(a[i] <= a[j])	arr[arri++] = a[i++];
		else	arr[arri++] = a[j++];
	}
	
	if(i>mid)	memcpy(arr+arri, a+j, (r-j+1)*sizeof(int));
	else	memcpy(arr+arri, a+i, (mid-i+1)*sizeof(int));
	memcpy(a+l, arr, length*sizeof(int));
	free(arr);
}

void printarr(int *a, int l, int r) {
	if(l>r)	return;
	for(int i=l;i<=r;++i)	printf("%d\t", a[i]);
	printf("\n");
}

void mergesort(int *a, int l, int r) {
	if(l>=r)	return;
	
	/*
	int mid = (l+r)>>1;
	mergesort(a, l, mid);
	mergesort(a, mid+1, r);
	merge(a, l, mid, r);
	*/

	int length = r-l+1, tmp;
	if(length<=8) {
		bbsort(a, l, r);
		return;
	}

	int power = numpow2(length);
	tmp = 1<<power;
	int ll, rr, delta, sets;
	if(length != tmp) {
		// length != 2^power
		for(delta=2;delta<length;delta<<=1) {
			sets = setcounter(delta, length);
			for(int i=0;i<sets-1;++i) {
				ll = l + i*delta;
				rr = ll + delta - 1;
				merge(a, ll, (ll+rr)>>1, rr);
			}
			ll = l + (sets-1)*delta;
			merge(a, ll, (ll+r)>>1, r);
		}
		merge(a, l,l+(delta>>1)-1, r);

	}else {
		// length == 2^power
		for(delta=2;delta<=length;delta<<=1) {
			sets = setcounter(delta, length);
			for(int i=0;i<sets;++i) {
				ll = l + i*delta;
				rr = ll + delta - 1;
				merge(a, ll, (ll+rr)>>1, rr);
			}
		}
	}

}

void bbsort(int *a, int l, int r) {
	if(l>=r)	return;

	int length = r-l+1, flag, tmp;
	for(int i=1;i<length;++i) {
		flag = 0;	
		for(int j=r;j>=l+i;--j) {
			if(a[j]<a[j-1]) {
				flag = 1;
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
		if(flag==0)	break;
	}

}

int numpow2(int n) {
	if(n<=1)	return 0;
	else {
		int tmp = n>>1;
		int count = 0;
		while(tmp) {
			tmp >>= 1;
			++count;
		}
		return count;
	}

}

int setcounter(int delta, int length) {

	int power = numpow2(delta);
	if(!power)	return 0;
	else {
		int counter = length>>power;
		if((length & ((1<<power)-1)) != 0)	++counter;
		return counter;
	}

}

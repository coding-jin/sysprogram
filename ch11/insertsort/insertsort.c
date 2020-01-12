#include <stdio.h>
#include <stdlib.h>

void insertsort(int *a, int len);
void printarr(int *a, int len);

int main(int argc, char **argv) {
	int a[5] = {5, 3, 2, 1, 4};
	insertsort(a, 5);
	printarr(a, 5);
	return 0;
}

void insertsort(int *a, int len) {
	if(len <= 1)	return;
	int i, j, key;
	for(i=1;i<len;++i) {
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key)	{
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = key;
	}
}

void printarr(int *a, int len) {
	for(int i=0;i<len;++i)	printf("%d\t", a[i]);
	printf("\n");
}


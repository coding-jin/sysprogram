#include <stdio.h>
#include <stdlib.h>

void bbsort(int *a, int l, int r);
void printarr(int *a, int l, int r);

int main(int argc, char **argv) {
	int a[5] = {1, 5, 3, 4, 2};
	bbsort(a, 0, 4);
	printarr(a, 0, 4);
	return 0;
}

void bbsort(int *a, int l, int r) {
	if(l>=r)	return;

	int length = r-l+1, tmp, flag;
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

void printarr(int *a, int l, int r) {
	if(l>=r)	return;
	
	for(int i=l;i<=r;++i)	printf("%d\t", a[i]);
	printf("\n");
}

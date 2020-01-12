#include <stdio.h>
#include <stdlib.h>

void swap(int *t1, int *t2);

int main(int argc, char **argv) {
	int a[10] = {9, 7, 10, 8, 3, 4, 2, 1, 6, 5};
	if(a[0]>a[1])	swap(&a[0], &a[1]);

	for(int i=2;i<10;++i) {
		if(a[i]<a[0]) {
			a[1] = a[0];
			a[0] = a[i];
		}else if(a[0]<=a[i] && a[i]<=a[1]) {
			a[1] = a[i];
		}
	}

	printf("min=%d the second min=%d\n", a[0], a[1]);
	return 0;
}

void swap(int *t1, int *t2) {
	int tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}

#include <stdio.h>
typedef struct{
	int c1;
	float c2;
}dl;
void docfile(dl a[],int *n){
	FILE *f=fopen("data.txt","r");
	int i;
	while (!feof(f)){
		fscanf (f,"%d %f", &a[i].c1,&a[i].c2);
		i++;
	}
	*n=i;
	fclose(f);
}
void in(dl a[], int n){
	for (int i=0;i<n;i++){
		printf ("%3d %7.2f\n", a[i].c1,a[i].c2);
	}
}
void swap(dl *x,dl *y){
	dl temp=*x;
	*x=*y;
	*y=temp;
}
void vundong(dl a[],int dau,int cuoi){
	int le,ri,max;
	int r=dau;
	while (1){
		le=2*r+1;
		ri=2*r+2;
		max=r;
		if (le<=cuoi&&a[le].c1>a[max].c1){
			max=le;
		}
		if (ri<=cuoi&&a[ri].c1>a[max].c1){
			max=ri;
		}
		if (max!=r){
			swap(&a[r],&a[max]);
			r=max;
		}
		else break;
	}
}
void heapsort(dl a[],int n){
	for (int i=(n-2)/2;i>=0;i--){
		vundong(a,i,n-1);
	}
	for (int i=n-1;i>=2;i--){
		swap(&a[0],&a[i]);
		vundong(a,0,i-1);
	}
	swap(&a[0],&a[1]);
}
int main(){
	int n;
	dl a[20];
	docfile(a,&n);
	in(a,n);
	printf("du lieu da duoc sap xep:\n");
	heapsort(a,n);
	in(a,n);
}

#include <stdio.h>
typedef struct{
	int c1;
	float c2;
}dl;
void docfile(dl a[], int *n){
	FILE *f=fopen("data.txt","r");
	int i;
	while (!feof(f)){
		fscanf(f,"%d %f", &a[i].c1,&a[i].c2);
		i++;
	}
	*n=i;
	fclose(f);
}
void in(dl a[],int n){
	for (int i=0;i<n;i++){
		printf ("%3d %7.2f\n",a[i].c1,a[i].c2);
	}
}
void swap(dl *x,dl *y){
	dl temp=*x;
	*x=*y;
	*y=temp;
}
int timchot(dl a[],int i,int j){
	int k=i+1;
	int max=a[i].c1;
	while (k<=j&&max==a[k].c1){
		k++;
	}
	if (k>j) return -1;
	if (a[k].c1<max) return k;
	return i;
}
int phanhoach(dl a[],int i,int j,int chot){
	int l,r;
	l=i;
	r=j;
	while (l<=r){
		while (a[l].c1<=chot) l++;
		while (a[r].c1>chot) r--;
		if (l<r) swap(&a[l],&a[r]);
	}
	return l;
}
void quicksort(dl a[],int i,int j){
	int chot,vtchot,k;
	vtchot=timchot(a,i,j);
	if (vtchot!=-1){
		chot=a[vtchot].c1;
		k=phanhoach(a,i,j,chot);
		quicksort(a,i,k-1);
		quicksort(a,k,j);
	}
}
int main(){
	int n;
	dl a[20];
	docfile (a,&n);
	in(a,n);
	printf ("mang da duoc sap xep:\n");
	quicksort(a,0,n-1);
	in(a,n);
}

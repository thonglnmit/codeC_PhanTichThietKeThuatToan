#include <stdio.h>
typedef struct {
	int c1;
	float c2;
}data;
void docfile(data dl[], int *n){
	FILE *f=fopen("data.txt","r");
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d%f", &dl[i].c1,&dl[i].c2);
		i++;
	}
	*n=i;
	fclose(f);
}
void in(data dl[],int n){
	for (int i=0;i<n;i++){
		printf("%4d %7.1f\n", dl[i].c1,dl[i].c2);
	}
}
void swap( data *x,data *y){
	data temp=*x;
	*x=*y;
	*y=temp;
}
int timchot(data dl[],int i,int j){
	int chot;
	int k;
	k=i+1;
	chot=dl[i].c1;
	while(k<=j && dl[k].c1==chot) k++;
	if(k>j) return -1;
	if (dl[k].c1>chot) return k;
	return i;
}
int phanhoach(data dl[],int i,int j, int chot){
	int l,r;
	l=i;
	r=j;
	while(l<=r){
		while(dl[l].c1<chot) l++;
		while(dl[r].c1>=chot) r--;
		if (l<r) swap(&dl[l],&dl[r]);
	}
	return l;
}
void quicksort(data dl[],int i, int j){
	int chot;
	int vtchot,k;
	vtchot=timchot(dl,i,j);
	if(vtchot!=-1){
		chot=dl[vtchot].c1;
		k=phanhoach(dl,i,j,chot);
		quicksort(dl,i,k-1);
		quicksort(dl,k,j);
	}
}
int main(){
	int n;
	data dl[20];
	docfile(dl,&n);
	in(dl,n);
	printf ("du lieu da duoc sap xep:\n");
	quicksort(dl,0,n-1);
	in(dl,n);
}

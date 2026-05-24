#include <stdio.h>
typedef struct{
	int c1;
	float c2;
}data;
void docfile(data dulieu[],int *n){
	FILE *f;
	f=fopen("data.txt","r");
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d %f",&dulieu[i].c1,&dulieu[i].c2);
		i++;
	}
	*n=i;
	fclose(f);
}
void in(data dulieu[],int n){
	for (int i=0;i<n;i++){
		printf ("%4d %9.2f\n", dulieu[i].c1,dulieu[i].c2);
	}
}
void swap(data *x,data *y){
	data temp=*x;
	*x=*y;
	*y=temp;
}
void sapxepnoibot(data dulieu[],int n){
	int i,j;
	for (i=0;i<=n-2;i++){
		for (j=n-1;j>=i+1;j--){
			if (dulieu[j].c1<dulieu[j-1].c1){
				swap(&dulieu[j],&dulieu[j-1]);
			}
		}
	}
}
int main(){
	int n;
	data dulieu[20];
	docfile(dulieu,&n);
	in(dulieu,n);
	printf ("du lieu sao khi sap xep:\n");
	sapxepnoibot(dulieu,n);
	in(dulieu,n);
}

#include <stdio.h>
typedef struct{
	int gia,pa;
	char ten[25];
}dl;
void docfile (dl atm[10], int *n){
	FILE *f=fopen("atm.txt", "r");
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d%[^\n]", &atm[i].gia,atm[i].ten);
		atm[i++].pa=0;
	}
	*n=i;
	fclose(f);
}
void in(dl atm[],int n){
	printf ("-----------------------------------------------\n");
	printf ("| menh gia |         ten          | phuong an |\n");
	for (int i=0;i<n;i++){
		printf ("| %-6d   |%-22s| %-5d     |", atm[i].gia,atm[i].ten,atm[i].pa);
		printf ("\n");
	}
	printf ("-----------------------------------------------\n");
	int sotienrutduoc;
	for (int i=0;i<n;i++){
		sotienrutduoc+=atm[i].gia*atm[i].pa;
	}
	printf ("so tien rut duoc la: %d", sotienrutduoc);
}
void swap(dl *x,dl *y){
	dl temp=*x;
	*x=*y;
	*y=temp;
}
void sxnb(dl atm[],int n){
	int i,j;
	for (i=0;i<=n-2;i++){
		for (j=n-1;j>i;j--){
			if (atm[j].gia>atm[j-1].gia){
				swap(&atm[j],&atm[j-1]);
			}
		}
	}
}
void pa(dl atm[],int n,int sotien){
	int i=0;
	sxnb(atm,n);
	while(i<n&&sotien>0){
		atm[i].pa=sotien/atm[i].gia;
		sotien=sotien-atm[i].gia*atm[i].pa;
		i++;
	}
}
int main(){
	int n;
	dl atm[10];
	docfile(atm,&n);
	int sotien;
	printf ("nhap so tien muon rut:\n");
	scanf("%d", &sotien);printf ("\n");
	pa(atm,n,sotien);
	in(atm,n);
}

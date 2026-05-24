#include <stdio.h>
typedef struct{
	int cot1;
	float cot2;
}data;
void docfile(data dulieu[],int *n){
	FILE *f;
	f=fopen("data.txt", "r");
	if (f==NULL){
		printf("loi doc file");
		return;
	}
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d %f", &dulieu[i].cot1,&dulieu[i].cot2);
		i++;
	}
	*n=i;
	fclose(f);
}
void in(data dulieu[],int n){
	for (int i=0;i<n;i++){
		printf ("%3d %7.2f\n", dulieu[i].cot1,dulieu[i].cot2);
	}
}
void swap(data *dulieu1,data *dulieu2){
	data temp=*dulieu1;
	*dulieu1=*dulieu2;
	*dulieu2=temp;
}
void sapxepchon(data dulieu[],int n){
	int i,j,vtnhonhat,gtnhonhat;
	for (i=0;i<=n-2;i++){
		vtnhonhat=i;
		gtnhonhat=dulieu[i].cot1;
		for(j=i+1;j<=n-1;j++){
			if(dulieu[j].cot1<gtnhonhat){
				gtnhonhat=dulieu[j].cot1;
				vtnhonhat=j;
			}
		}
		swap(&dulieu[i],&dulieu[vtnhonhat]);
	}
}
int main(){
	int n=0;
	data dulieu[20];
	docfile(dulieu,&n);
	in(dulieu,n);
	printf("du lieu da duoc sap xep:\n");
	sapxepchon(dulieu,n);
	in(dulieu,n);
}

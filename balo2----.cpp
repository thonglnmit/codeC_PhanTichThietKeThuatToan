#include <stdio.h>
typedef struct {
	float tl,gt,dg;
	int pa,sl;
	char ten[20];
}dl;
void docfile(dl a[],int *n,int *w){
	FILE *f=fopen("balo2thaman.txt","r");
	fscanf (f,"%d", w);
	int i=0;
	while (!feof(f)){
		fscanf (f,"%f %f %d %[^\n]", &a[i].tl,&a[i].dg,&a[i].sl,a[i].ten);
		a[i].pa=0;
		a[i].gt=a[i].dg/a[i].tl;
		i++;
	}
	*n=i;
	fclose(f);
}
void in(dl a[],int n,int w){
	printf ("trong luong cua ba lo la: %d\n", w);
	printf ("|---------------------------------------------------------------------------|\n");
	printf ("|       Ten        | trong luong | don gia | so luong | gia tri | phuong an |\n");
	for(int i=0;i<n;i++){
		printf ("|%18s|%9.2f    |%7.2f  |%6d    |%7.2f  |%5d      |\n", a[i].ten,a[i].tl,a[i].dg,a[i].sl,a[i].gt,a[i].pa);
	}
	printf ("|---------------------------------------------------------------------------|\n");
	printf ("phuong an la : \n");
	float tgt,ttl;
	for (int i=0;i<n;i++){
		printf ("%d",a[i].pa);
		if (i<n-1) printf (" -> ");
		ttl+=a[i].pa*a[i].tl;
		tgt+=a[i].pa*a[i].dg;
	}
	printf ("\n");
	printf ("trong luong con lai: %.2f\n", w-ttl);
	printf ("tong gia tri: %.2f\n", tgt);
	printf ("tong trong luong: %.2f\n", ttl);
}
void swap(dl *x,dl *y){
	dl temp=*x;
	*x=*y;
	*y=temp;
}
void sapxep(dl a[],int n){
	for (int i=0;i<n;i++){
		for (int j=n-1;j>i;j--){
			if (a[j].gt>a[j-1].gt){
				swap(&a[j],&a[j-1]);
			}
		}
	}
}
int min(int x,int y){
	if (x<y) return x;
	return y;
}
void thaman(dl a[],int n,int w){
	float ttcl=w;
	int i=0;
	while(ttcl>=0&&i<n){
		a[i].pa=min(a[i].sl,ttcl/a[i].tl);
		ttcl-=a[i].tl*a[i].pa;
		i++;
	}
}
int main(){
	int n,w;
	dl a[10];
	docfile(a,&n,&w);
	sapxep(a,n);
	thaman(a,n,w);
	in(a,n,w);
}

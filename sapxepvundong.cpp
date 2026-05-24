#include <stdio.h>
typedef struct {
 int key;
 float otherfields;
}recordtype;
void nhapfile(recordtype a[], int *n){
 FILE *f=fopen("data.txt","r");
 int i=0;
 if (f!=NULL){
  while (!feof(f)){
   fscanf(f,"%d %f", &a[i].key, &a[i].otherfields);
   i++;
  }
 }
 else printf ("loi doc file");
 fclose(f);
 *n=i;
}
void in(int n,recordtype a[]){
 for (int i=0;i<n;i++){
  printf ("%3d %5d %8.2f", i+1,a[i].key,a[i].otherfields);
  printf ("\n");
 }
}
void swap(recordtype *x, recordtype *y){
 recordtype temp=*x;
 *x=*y;
 *y=temp;
}
void pushdown(recordtype a[], int first, int last) {
    int r = first;
    int leftChild, rightChild, maxChild;
    while (1) {
        leftChild = 2 * r + 1;
        rightChild = 2 * r + 2;
        maxChild = r;
        if (leftChild <= last && a[leftChild].key > a[maxChild].key)
            maxChild = leftChild;
        if (rightChild <= last && a[rightChild].key > a[maxChild].key)
            maxChild = rightChild;
        if (maxChild != r) {
            swap(&a[r],&a[maxChild]);
            r = maxChild;
        } 
		else {
            break;
        }
    }
}
void heapsort(recordtype a[],int n){
 int i;
 for(i=(n-2)/2;i>=0;i--){
  pushdown(a,i,n-1);
 }
 for (i=n-1;i>=2;i--){
  swap(&a[0],&a[i]);
  pushdown(a,0,i-1);
 }
 swap(&a[0],&a[1]);
}
int main(){
 recordtype a[100];
 int n;
 nhapfile(a,&n);
 printf ("thuat toan sap xep noi bot:\n");
 printf ("danh sach truoc khi sap xep:\n");
 in(n,a);
 heapsort(a,n);
 printf ("danh sach sau khi sap xep:\n");
 in(n,a);
 return 0;
}

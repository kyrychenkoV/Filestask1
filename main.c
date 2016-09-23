#include <stdio.h>
#include<malloc.h>
void memAllocationOneArr();
void memAllocationTwoArr ();
int main(){

    int i,x=0, y=0,count=0;

    FILE *fin, *fout;
    int  a[10];
    int b[10];
    fin = fopen("input.txt", "w");

    if(fin==NULL){
        printf("error");
    }
    fout = fopen("output.txt", "w");
    if(fin==NULL){
        printf("error");
    }
    fclose(fout);
    printf("enter two number or exit for exit:");
    while( x<5)            //scanf("%d%d", &x, &y))!=0){
    { x++;y=1+x;
        fprintf(fin, "%d %d\n", x, y);

    }
    fclose(fin);
    fin = fopen("input.txt", "r");
    if(fin==NULL){
        printf("error");
    }
    fout = fopen("output.txt", "r+");
    if(fin==NULL){
        printf("error");
    }
    i=0;
    while((fscanf(fin, "%d %d", &a[i], &b[i]))!=EOF){
        fprintf(fout, "%d %d\n", a[i], b[i]);
        i++;
        count++;
    }

    for (i=0;i<count;i++){
        fprintf(fout, "%d ",a[i]+b[i]);
    }

    memAllocationOneArr();
    memAllocationTwoArr();
    fclose(fin);
    fclose(fout);
    return 0;
}
void memAllocationOneArr(){
    FILE *fin, *fout;
    printf("\ndynamic memory allocation for one-dimensional array\n");
    fin = fopen("input.txt", "r");
    int *p,*p1;
    p=(int*)malloc(sizeof(int));
    p1=(int*)malloc(sizeof(int));
    int i=0;
    int count=0;
    while((fscanf(fin, "%d%d", &p[i],&p1[i]))!=EOF){
        i++;
        p=(int*)realloc (p,(i+1)*sizeof(int));
        p1=(int*)realloc (p1,(i+1)*sizeof(int));
        count++;
    }
    for (i=0;i<count;i++){
        printf("%d ",*(p+i));
        printf("%d ",p1[i]);
    }
    fclose(fin);
}void memAllocationTwoArr (){
    FILE *fin, *fout;
    printf("\ndynamic memory allocation for two-dimensional array\n");
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "r");
    int **p2;
    int i=0;
    p2=(int **)malloc(sizeof(int*));
    p2[0]=(int *)malloc(2*sizeof(int));
    int count2=0;
    while((fscanf(fin, "%d%d", &p2[i][0], &p2[i][1]))!=EOF){
        i++;
        p2=(int **)realloc(p2,(i+1)*sizeof(int*));
        p2[i]=(int *)malloc((2)*sizeof(int));
        count2++;
    }
    for (i=0;i<count2;i++){

        printf(" %d %d",*(*(p2+i)+0),*(*(p2+i)+1));
    }
    printf("\n");
    fclose(fout);
    fclose(fin);

}


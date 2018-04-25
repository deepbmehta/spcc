#include<stdio.h>
#include<math.h>
#include<string.h>
    int n,i,j,k;
    char a[10][20];


void first(char a[10][20], char x){
    int i,j;
    for(i=0;i<n;++i)if(a[i][0]==x)break;
    if(i==n){
	printf("%c; ",x);
	return;
	}
    for(j=3;i<n && j<strlen(a[i]);++j){
        first(a, a[i][j]);
        while(a[i][j]!='/' && j!=strlen(a[i]))j++;
    }
}

void follow(char a[10][20], char x){
    int i,j,flag=0;
    for(i=0;i<n;++i){
        for(j=3;j<strlen(a[i]);++j){
            if((a[i][j]==x) && j+1<strlen(a[i]) && a[i][j+1]!='/'){
                flag=1;
                first(a,a[i][j+1]);
            }
        }
    }
    if(flag==0)printf("$");
}



int main(){
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    for(i=0;i<n;++i){
    printf("Enter string: ");
            scanf("%s",a[i]);
    }
    for(i=0;i<n;++i){
        printf("Follow of %c : ",a[i][0]);//Epsilon case is not considered
        follow(a, a[i][0]);
        printf("\n");;
    }
return 0;
}

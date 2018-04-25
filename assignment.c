#include<stdio.h>
#include<string.h>
#include<math.h>
char prior[] = {'^','*','/','+','-','\0'};
char x = 'A';


void AC3(char a[30],int j){
	int i;
	printf("%c=%c%c%c\n",x,a[j-1],a[j],a[j+1]);
	for(i=j+2;i<=strlen(a);i++){
		a[i-2]=a[i];

	}
	a[j-1]=x;
	x++;
}







void main(){
	char a[30];
	int i,j,flag=0;
	printf("Enter the string\n");
	scanf("%s",a);
	for(i=0;i<strlen(prior);i++){
		flag=0;
		for(j=0;j<strlen(a);j++){
			if(prior[i] == a[j]){
				while(j<strlen(a) && prior[i]==a[j+2]){
					flag = 1;
					j+=2;
				}
				AC3(a,j);
			}
		}
		if(flag==1)
			i--;
	}
	printf("%c=%c",a[0],--x);

}
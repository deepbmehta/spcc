#include <stdio.h>
#include <time.h>

int global;

int before_optimize()
{
	int i;
	i=1;
	global=1;
	global=2;
	return global;
	global=3;
}

int after_optimize()
{
	global=2;
	return global;
}

void main()
{
	int a,b;
	a=before_optimize();
	printf("\nValue of global variable before optimization %d\n",a);
	b=after_optimize();
	printf("\nValue of global variable after optimization %d\n",b);
}

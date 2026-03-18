#include <stdio.h>
#include <stdlib.h>

int ok(int c,int r,int *b)
{
	int i=0;
	while(i<c)
	{
		if(b[i]==r || b[i]-i==r-c || b[i]+i==r+c)
			return 0;
		i++;
	}
	return 1;
}

void solve(int c,int n,int *b)
{
	int r=0,i;
	if(c==n)
	{
		i=0;
		while(i<n)
		{
			fprintf(stdout,"%d",b[i]);
			if(i+1<n) 
				fprintf(stdout," ");
			i++;
		}
		fprintf(stdout,"\n");
		return;
	}
	while(r<n)
	{
		if(ok(c,r,b))
		{
			b[c]=r;
			solve(c+1,n,b);
		}
		r++;
	}
}

int main(int ac,char **av)
{
	int *b,n;
	if(ac!=2)
         return 1;
	n= atoi(av[1]);
	if (n == 0)
		return (1);
	b= malloc(sizeof(int)*n);
	if (!b)
		return (1);
	solve(0,n,b);
	free(b);
}
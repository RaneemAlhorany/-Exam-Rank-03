// to test it write in the shell : bash tester.sh

#include <unistd.h>
#include <stdlib.h>
//selection sort
void sort (char *s)
{
	int i = 0;
	int j;
	char temp ;

	while (s[i])
	{
		j = i+1;
		while (s[j])
		{
			if (s[i] > s[j])
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
			j++;
		}
		i++;
	}
}


void Backtracking(char * s ,int * used , char * result , int len , int depth)
{
	//base case
	if (len == depth)
	{
		write(1, result , len);
		write(1, "\n" , 1);
		return;
	}

	int i = 0;
	while (i < len)
	{
		if (!used[i])
		{
			used[i] = 1;
			result[depth] = s[i];
			Backtracking(s , used ,  result ,  len , depth+1);
			used[i] = 0;
		}

		i++;
	}
}


int main (int argc , char ** argv)
{
	if (argc != 2)
		return (1);

	int len = 0;
	int *used;
	char *result;
	int i = 0 ;

	while (argv[1][len])
		len ++;

	used = malloc (len);
	if (!used)
		return(1);
	result = malloc (len);
	if (!result)
	{
		free(used);
		return (1);
	}

	 while (i < len)
	 {
		 used[i] = 0;
		 i ++;
	 }

	 sort (argv[1]);
	 Backtracking(argv[1] ,used , result , len , 0);

	 return (0);
}




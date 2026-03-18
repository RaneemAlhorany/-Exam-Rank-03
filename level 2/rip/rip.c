// to test it write in the shell : bash tester.sh

#include <unistd.h>

void count_invalid (char *s , int *open , int *close)
{
	int index = 0;
	int balance = 0;

	while (s[index])
	{
		if (s[index] == '(')
			balance++;
		if (s[index] == ')')
		{
			if (balance > 0)
				balance--;
			else 
				(*close) ++;
		}

		index++;
	}

	(*open) = balance;
}


void backtracking(char *s , int index, int open , int close , int len , int balance)
{
	//base case
	if (index == len)
	{
		if (balance == 0 && open == 0 && close == 0)
		{
			write (1,s,len);
			write (1,"\n" , 1);
		}
		return ;
	}


	// backtracking 
	
	if (s[index] == '(')
	{
		if (open > 0)
		{
			s[index] = ' ';
			backtracking(s , index +1,  open - 1 ,  close ,  len , balance);
			s[index] = '(';
		}
   		backtracking(s , index + 1,  open  ,  close ,  len , balance + 1 );
	}
	else if (s[index] == ')')
	{
		if (close > 0)
                {
                        s[index] = ' ';
                        backtracking(s , index +1,  open  ,  close - 1,  len , balance);
                        s[index] = ')';
                }
		if (balance > 0)
		       	backtracking(s , index + 1,  open  ,  close ,  len , balance -1 );
		
	}
}



int main (int argc , char **argv)
{
	if (argc != 2)
		return (1);

	int open = 0;
	int close = 0;
	int len = 0;

	while (argv[1][len])
		len ++;
	
	count_invalid (argv[1] , &open , &close);
	backtracking(argv[1], 0 , open ,  close ,  len , 0);

	return (0);
}

// to use tets :  bash tester.sh

#include <stdlib.h>
#include <stdio.h>

void backtracking(int *set , int *subset , int subset_size , int index , int sum , int target , int count )
{
	if (index == count)
	{
		if (sum == target)
		{
			int i = 0;
			while (i < subset_size)
			{
				printf(i ? " %d" : "%d" , subset[i]);
				i++;
			}
             printf("\n");
		}
		return ;
	}
	
	subset[subset_size] = set[index];

	backtracking(set , subset , subset_size + 1 ,  index + 1 , sum + set[index] ,  target ,  count );
	backtracking(set ,subset , subset_size ,  index + 1 ,   sum ,  target ,  count );
}

int main (int argc , char **argv)
{
	if (argc < 3)
		return (1);

	int *set ;
	int *subset ;
	int target = atoi(argv[1]);
	int count = argc -2 ;

	set = malloc (count);
	if (!set)
		return (1);
	
	subset = malloc (count);
	if (!subset)
	{
		free(set);
		return (1);
	}

    int i = 0;

    while (i < count)
    {
        set[i] = atoi(argv[i+2]);
        i++;
    }

	backtracking(set , subset , 0 , 0 ,0 , target , count );

    return (0);
}

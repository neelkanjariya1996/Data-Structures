#include <stdio.h>
#include <stdlib.h>

unsigned long int
factorial (unsigned int n)
{

	unsigned long int res = 1;

	for (int i = 1; i <= n; i++)
		res = res * i;

	return res;
	
}

unsigned long int
binomial_coeff (unsigned int n, unsigned int k)
{

	unsigned long int res = 1;

	if (k > (n - k))
		k = n - k;

	for (int i = 0; i < k; i++) {
	
		res = res * (n - i);
		res = res / (i + 1);
	}

	return res;

}

unsigned long int
catalan (unsigned int n)
{

	unsigned long int c = 0;

	c = binomial_coeff ((2 * n), n);

	return (c/(n+1));

}

unsigned long int 
count_bst (unsigned int n)
{
	
	unsigned long int count = 0;

	count = catalan (n);

	return count;

}

unsigned long int
count_bt (unsigned int n)
{

	unsigned long int count  = 0;

	count = catalan (n);

	return (count * factorial (n));

}

int
main ()
{

	int count1 	= 0;
	int count2 	= 0;
	int n		= 0;

	n = 5;
	count1 = count_bst (n);
	count2 = count_bt (n);

	printf ("The number of binary search trees with %d nodes is: %d\n", n, count1);
	printf ("The number of binary trees with %d nodes is: %d\n", n, count2);

	return 0;

}

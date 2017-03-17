#include "stdafx.h"
#include <stdlib.h>
#include "generic_merge_sort.h"



void merge_helper(void *input, int left, int right, void *scratch, generic_max max, generic_assign assign)
{
	int i, length, midpoint_distance, l, r;
	/* base case: one element */
	if (right == left + 1)
	{
		return;
	}
	else
	{
		i = 0;
		length = right - left;
		midpoint_distance = length / 2;
		/* l and r are to the positions in the left and right subarrays */
		l = left, r = left + midpoint_distance;

		/* sort each subarray */
		merge_helper(input, left, left + midpoint_distance, scratch, max, assign);
		merge_helper(input, left + midpoint_distance, right, scratch, max, assign);

		/* merge the arrays together using scratch for temporary storage */
		for (i = 0; i < length; i++)
		{
			/* Check to see if any elements remain in the left array; if so,
			* we check if there are any elements left in the right array; if
			* so, we compare them.  Otherwise, we know that the merge must
			* use take the element from the left array */
			if (l < left + midpoint_distance &&
				(r == right || max(input, r, input, l)))
			{
				assign(scratch, i, input, l);
				//scratch[i] = input[l];
				l++;
			}
			else
			{
				assign(scratch, i, input, r);
				//scratch[i] = input[r];
				r++;
			}
		}
		/* Copy the sorted subarray back to the input */
		for (i = left; i < right; i++)
		{
			assign(input, i, scratch, i - left);
			//input[i] = scratch[i - left];
		}
	}
}

int mergesort(void *input, int elem_count, size_t elem_size, generic_max max, generic_assign assign)
{
	void *scratch = (void *)malloc(elem_count * elem_size);
	if (scratch != NULL)
	{
		merge_helper(input, 0, elem_count, scratch, max, assign);
		free(scratch);
		scratch = 0;
		return 1;
	}
	else
	{
		return 0;
	}
}

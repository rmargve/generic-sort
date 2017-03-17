// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "generic_merge_sort.h"
typedef struct {
	int x;
}point;

bool int_max(void *arg1, int index1, void *arg2, int index2)
{
	int x = *((int *)arg1 + index1);
	int y = *((int *)arg2 + index2);
	if (x > y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void int_assign(void * arg1, int index1, void * arg2, int index2)
{
	*((int *)arg1 + index1) = *((int *)arg2 + index2);
}

bool point_max(void *arg1, int index1, void *arg2, int index2)
{
	int x = (*((point *)arg1 + index1)).x;
	int y = (*((point *)arg2 + index2)).x;
	if (x > y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void point_assign(void * arg1, int index1, void * arg2, int index2)
{
	*((point *)arg1 + index1) = *((point *)arg2 + index2);
}

bool double_max(void *arg1, int index1, void *arg2, int index2)
{
	double x = *((double *)arg1 + index1);
	double y = *((double *)arg2 + index2);
	if (x > y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void double_assign(void * arg1, int index1, void * arg2, int index2)
{
	*((double *)arg1 + index1) = *((double *)arg2 + index2);
}


int main()
{
	int nums[] = { 2, 6, 4, 3, 9 };
	mergesort(nums, sizeof(nums) / sizeof(int), sizeof(int), int_max, int_assign);
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
		printf("%d ", nums[i]);
	printf("\n");

	point coords[5]; coords[0].x = 9; coords[1].x = 12; coords[2].x = 122; coords[3].x = 10;
	mergesort(coords, sizeof(coords) / sizeof(point), sizeof(point), point_max, point_assign);
	for (int i = 0; i < sizeof(coords) / sizeof(point); i++)
		printf("%d ", coords[i].x);
	printf("\n");

	double d_nums[] = { 2.5, 1.9, 4.1, 6.2 };
	mergesort(d_nums, sizeof(d_nums) / sizeof(double), sizeof(double), double_max, double_assign);
	for (int i = 0; i < sizeof(d_nums) / sizeof(double); i++)
		printf("%f ", d_nums[i]);
	printf("\n");
	return 0;
}





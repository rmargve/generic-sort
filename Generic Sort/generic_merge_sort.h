#pragma once

//returns true if first argument is greater than second
typedef bool(*generic_max)(void *, int, void *, int);

// assigns second argument to first
typedef void(*generic_assign)(void *, int, void *, int);

void merge_helper(void *, int, int, void *, generic_max, generic_assign);
int mergesort(void *, int, size_t, generic_max, generic_assign);

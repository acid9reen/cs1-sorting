#pragma once

void pprint(int arr[], int n);
int max(int arr[], int n);
void random_array(int n);
void merge(int arr[], int l, int m, int r, int *sw_counter, int *eq_counter);
void swap(int *xp, int *yp);
int partition(int arr[], int low, int high, int *sw_counter, int *eq_counter);
int linear_search(int arr[], int n, int element, int *sw_counter, int *eq_counter);
int binarySearch(int arr[], int left, int right, int element, int *sw_counter, int *eq_counter);

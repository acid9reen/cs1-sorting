#pragma once

void bubble_sort(int arr[], int n, int *sw, int *eq);
void selection_sort(int arr[], int n, int *sw_counter, int *eq_counter);
void insertion_sort(int arr[], int n, int *sw_counter, int *eq_counter);
void counting_sort(int arr[], int n, int *sw_counter, int *eq_counter);
void merge_sort(int arr[], int l, int r, int *sw_counter, int *eq_counter);
void quick_sort(int arr[], int low, int high, int *sw_counter, int *eq_counter);

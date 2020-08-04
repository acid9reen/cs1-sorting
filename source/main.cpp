#include "sort.hpp"
#include "usefull_funcs.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int length, func = 1;
	int sw = 0, eq = 0;
	int *sw_counter = &sw;
	int *eq_counter = &eq;
	
	while(true)
	{
		sw = 0;
		eq = 0;

		printf("The Greatest Sorting Machine\n\n");

		printf("1.| Bubble Sort    |\n");
		printf("--|----------------|\n");
		printf("2 | Insertion Sort |\n");
		printf("--|----------------|\n");
		printf("3.| Selection Sort |\n");
		printf("--|----------------|\n");
		printf("4.| Counting Sort  |\n");
		printf("--|----------------|\n");
		printf("5.| Merge Sort     |\n");
		printf("--|----------------|\n");
		printf("6.| Quick Sort     |\n");
		printf("--|----------------|\n");
		printf("7.| Linear Search  |\n");
		printf("--|----------------|\n");
		printf("8.| Binary Search  |\n");
		printf("--|----------------|\n");
		printf("0.| Exit           |\n");

		printf("\nEnter function number: ");
		scanf("%d", &func);
		if (func != 0)
		{
			printf("Enter length of an array: ");
			scanf("%d", &length);

			int *random_array_ = (int*)malloc(sizeof(int) * length);
			int i;

			for (i = 0; i < length; i++)
			{
				random_array_[i] = rand();
			}

			if (length < 100)
			{
				printf("\nRandom Array:");
				pprint(random_array_, length);
			}
			

			clock_t begin = clock();

			switch (func)
			{
			case 1: bubble_sort(random_array_, length, &sw, &eq);
				break;
			case 2: insertion_sort(random_array_, length, &sw, &eq);
				break;
			case 3: selection_sort(random_array_, length, &sw, &eq);
				break;
			case 4: counting_sort(random_array_, length, &sw, &eq);
				break;
			case 5:
				merge_sort(random_array_, 0, length - 1, &sw, &eq);
				break;
			case 6:
				quick_sort(random_array_, 0, length - 1, &sw, &eq);
				break;
			case 7:
				int element;
				printf("\nEnter the element to search: \n");
				scanf("%i", &element);
				int index;
				index = linear_search(random_array_, length, element, &sw, &eq);
				printf("\nIndex of the element: %i\n", index);
				break;
			case 8:
				int element_;
				quick_sort(random_array_, 0, length - 1, &sw, &eq);
				if (length < 100)
				{
					printf("\nSorted array: ");
					pprint(random_array_, length);
				}
				printf("\nEnter the element to search: \n");
				scanf("%i", &element_);

				int index_;
				index_ = binarySearch(random_array_, 0, length, element_, &sw, &eq);
				printf("\nIndex of the element: %i\n", index_);
				break;

			default:
				break;
			}

			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

			if (length < 100 && func < 7)
			{
				printf("\nResult:");
				pprint(random_array_, length);
			}

			free(random_array_);
			
			if (func < 7)
			{
				printf("\nExecution Time: %lf\n", time_spent);
			}

			printf("Swap count: %i, Comparison count: %i\n", sw, eq);
			
			printf("\nOnce again? (1 - yes, 0 - no): ");
			scanf("%d", &func);
			
			if (func == 0)
				break;
			printf("\n\n\n\n\n");
		}
		else
			break;
		
	} 
	return 0;
}

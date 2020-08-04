# Sorting 

Sorting is a C++ program for demonstrating complexity of some sorting algorithms.

## Introduction
Currently, people operate with a huge amount of data, including
the number stored in the arrays. Since now the volumes of this data are only
grow, the question of the effectiveness of algorithms becomes relevant,
able to process them, in particular to sort them.   
In this paper, we consider some efficient and not very efficient algorithms
sorting, as well as some auxiliary algorithms.   
Below is a table comparing the complexity of the considered algorithms. 

| Algorithm        | Complexity  |
| :---             |    :---:    |
| Linear search    | O(n)        |
| Binary search    | O(log(n))   |
| Bubble sort      | O(n^2)      |
| Counting sort    | O(n)        |
| Insertion sort   | O(n^2)      |
| Quick sort       | O(n*log(n)) |
| Merge sort       | O(n*log(n)) |
| Selection sort   | O(n^2)      |   

## Program description
The written program is capable of generating a random array of length,
set by the user and depending on the user's choice
sort it by the selected algorithm or search for the element entered
by the user, also at the end of
the completion of sorts, program displays the time spent on their execution,
the number of exchanges and comparisons, for sorts - only the number
comparisons and exchanges.

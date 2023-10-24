# Sorting algorithms, Big O notation 
--------------
- Sorting algorithm - an algorithm that puts element of a list into an order.
	- most frequently used orders are:
		1. numerical order
		2. Lexicographical order
- sorting is important for optimizing the  efficiency of other algorithm
	- The output of any sorting algorithm must satisfy 2 conditions
		1. The output is in monotonic order
		2. The output is a permutation
- For optimum efficiency input data shd be stored in a data structure which allows random access instead of sequential.
#### Classification
- sorting algorithms can be classified by:
###### Computation Complexity
__*Best Case*__  - situation in which an algorithm performs as efficient as possible.
	It represent the lower bound on the algorithm performance.
	It typically occurs when the input data is structured in a way that allows the algorithm to complete it tasks with the _fewest_ number of operations 
__*Worst case*__ -  It is a situation in which an algorithm performs inefficiently as possible.
	It represent the upper bound of the algorithm performance
	It considers  input data that forces the algorithm to take _maximum_ no of steps or use most resources 
__*Average case*__ - It takes into account the expected or average performance of an algorithm over a wide range of inputs, considering their probability of occurrence
	It provides a more understanding of an algorithm typical performance 
- Algorithms are often designed and optimized to perform well in the worst-case scenario, as that guarantees predictable and reliable performance, even if average-case or best-case performance may not be as impressive.
------------------
# **Understanding Big O Notation**

Big O Notation is a crucial concept in computer science and algorithm analysis. It provides a way to describe _how an algorithm's runtime grows concerning the size of its input._ In other words, it helps us understand _how quickly an algorithm's performance degrades as the problem size increases._ Keep in mind that Big O describes the `upper bound` or `worst-case` scenario for an algorithm's runtime. It may not precisely predict the execution time in seconds because it focuses on how the algorithm's performance scales with input size.

Common Big O run times include:

- **`O(1)`** `(Constant Time)`: Algorithms with constant time complexity have a consistent runtime, independent of input size. For example, accessing an element in an array by index.
    
- **`O(log(n))`** (Logarithmic Time): Algorithms with logarithmic time complexity often involve divide-and-conquer approaches. Binary search is a classic example.
    
- **`O(n)`** (Linear Time): Linear time complexity algorithms have a runtime that grows linearly with the input size. Simple searching algorithms like linear search fall into this category.
    
- **`O(n * log(n))`**: Common in efficient sorting algorithms like Merge Sort and Quick Sort.
    
- **`O(n^2)`** (Quadratic Time): Algorithms with quadratic time complexity often have nested loops and comparisons. Insertion Sort is an example.
    
- **`O(n!)`** (Factorial Time): This is a highly inefficient complexity, often associated with problems like the Traveling Salesman.
    
--------------------
**Sorting Algorithms in C**

Sorting algorithms are fundamental in computer science. Here's a more detailed explanation of some common sorting algorithms and their implementation in C, along with Big O time complexity analysis.


#### 1. **Selection Sort**
    
    Selection sort is straightforward but inefficient on large lists. It divides the array into sorted and unsorted parts. Two nested loops repeatedly find the minimum element in the unsorted part and place it at the end of the sorted part.
```c
void selectionSort(int arr[], int n) {
    // We're given an array called 'arr' with 'n' elements.
    for (int i = 0; i < n - 1; i++) {
        // We start at the first element (i=0) and go through each element in the array.

        // Assume the current element (at position 'i') is the smallest we've seen.
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            // Now, we compare the current element (at position 'i') with all the elements that come after it.

            if (arr[j] < arr[minIndex]) {
                // If we find an element smaller than the assumed smallest, we update 'minIndex'.
                minIndex = j;
            }
        }

        // After going through all the elements, 'minIndex' points to the position of the smallest element.

        // We swap the current element (at position 'i') with the smallest element we found.
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // We repeat this process until we've gone through the entire array.
    // By the end, the array will be sorted in ascending order.
}

```
**Time Complexity**: O(n^2)
**Goal:** The goal of this code is to sort an array (a list of numbers) in ascending order, meaning from the smallest number to the largest.

**Algorithm:** The selection sort algorithm works like this:

1. Start at the beginning of the array.
2. Go through the array and find the smallest number.
3. Swap that smallest number with the number at the current position.
4. Move to the next position in the array.
5. Repeat steps 2 to 4 until you've gone through the entire array.
#### 2. Insertion sort
Insertion sort is efficient for small dataset . It builds a sorted array by repeatedly taking an element from the unsorted path and inserting it into its correct position in sorted part.
```c
void insertionSort(int arr[], int n) {
    // We're given an array called 'arr' with 'n' elements.
    for (int i = 1; i < n; i++) {
        // We start at the second element (i=1) and go through each element in the array.

        // We take the current element (at position 'i') and call it 'key'.
        int key = arr[i];

        // We create a variable 'j' and set it to 'i - 1'. This will help us compare 'key' with the elements before it.
        int j = i - 1;

        // Now, we start comparing 'key' with the elements before it, moving from right to left.
        // We do this as long as 'j' is greater than or equal to 0, and the element we're comparing (arr[j]) is greater than 'key'.
        while (j >= 0 && arr[j] > key) {
            // If we find an element (arr[j]) greater than 'key', we move it to the right (arr[j + 1]) to make space for 'key'.
            arr[j + 1] = arr[j];
            
            // We also move 'j' one position to the left to continue comparing with previous elements.
            j--;
        }

        // Once we've found the correct spot for 'key' (where it's either smaller or equal to the element on its left),
        // we place 'key' in that spot.
        arr[j + 1] = key;
    }

    // We repeat this process for each element in the array, one by one.
    // By the end, the array will be sorted in ascending order.
}

```
**Time Complexity**: O(n^2)

1. Start with an array of unsorted elements.
    
2. Begin with the second element (index 1) because we consider the first element as already sorted.
    
3. Take the current element (referred to as 'key') and remember it. We'll use 'key' to find its correct position in the sorted part of the array.
    
4. Create a variable 'j' and set it to the position just before 'key' (i-1). 'j' will help us compare 'key' with the elements before it.
    
5. Compare 'key' with the element at position 'j'. If 'key' is smaller than the element at 'j', we move the element at 'j' to the right to make space for 'key.'
    
6. Continue this comparison and shifting process as long as 'j' is greater than or equal to 0 and the element at 'j' is greater than 'key.'
    
7. Once you've found the correct spot for 'key' (where it's either smaller or equal to the element on its left), place 'key' in that spot.
    
8. Move to the next element in the unsorted part of the array (increment 'i' by 1) and repeat the process from steps 3 to 7.
    
9. Continue this process until you've gone through all the elements in the array.
    
10. By the end, the array will be sorted in ascending order, with the smallest element at the beginning and the largest at the end.
    

That's how the Insertion Sort algorithm works step by step. It's like sorting a hand of playing cards, where you pick up a card, compare it to the cards in your hand, and insert it into the right position.

#### 3. Quick sort 
It is a more efficient sorting algorithm that uses recursion. It selects a pivot element and partitions the array into 2 sub arrays: one with elements less than the pivot and the other with element greater than the pivot. the process is repeated recursively.
```c
// Function to partition the array
int partition(int arr[], int low, int high) {
    // Choose a pivot element. Let's choose the last element as the pivot.
    int pivot = arr[high];
    int i = low - 1;

    // Start comparing elements from the beginning of the array.
    for (int j = low; j <= high - 1; j++) {
        // If the element is smaller than the pivot, swap it with the element at index 'i + 1'.
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element (arr[high]) with the element at index 'i + 1'.
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Return the index of the pivot element (now in its correct position).
    return i + 1;
}

// Recursive function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot element's correct position using the partition function.
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the left and right sub-arrays (elements less than and greater than the pivot).
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

```
1. Start with an array of unsorted elements.
    
2. Choose a pivot element from the array. The pivot is like a reference point for dividing the array.
    
3. Partition the array into two sub-arrays: one with elements smaller than the pivot and another with elements larger than the pivot.
    
4. Repeat steps 2 and 3 for the sub-arrays. Choose pivots and partition them until you have sub-arrays with only one element (which are already sorted).
    
5. Combine the sorted sub-arrays to get the fully sorted array.
    

**Detailed Steps:**

1. Start with an unsorted array.
    
2. Choose a pivot element. This can be any element from the array. Let's say you choose the last element as the pivot.
    
3. Partition the array:
    
    - Place all elements smaller than the pivot on the left side of the pivot.
    - Place all elements larger than the pivot on the right side of the pivot.
    - The pivot element is now in its correct position in the sorted array.
4. Now, you have two smaller unsorted sub-arrays (left and right of the pivot).
    
5. Repeat the process for the left and right sub-arrays:
    
    - Choose pivots for these sub-arrays.
    - Partition them into smaller sub-arrays.
    - Continue this process until you have sub-arrays with only one element (they are already sorted).
6. Combine the sorted sub-arrays:
    
    - Take the left sub-array (with elements smaller than the pivot), followed by the pivot element, and then the right sub-array (with elements larger than the pivot).
    - You've now combined these into a larger sorted sub-array.
7. Repeat this combination process for all levels of sub-arrays until you have one fully sorted array.
    

By the end of this process, you'll have a completely sorted array. Quick Sort is like a divide-and-conquer method where you keep dividing the problem into smaller parts, sort those smaller parts, and then combine them to get the final sorted result. It's efficient for sorting large datasets and is commonly used in practice.
**Time Complexity**:

- Best Case: O(n * log(n))
- Worst Case: O(n^2)
--------------------------------
Question #1
**What is the time complexity of this function / algorithm?**
```c
int Fibonacci(int number)
{
    if (number <= 1) return number;
    return Fibonacci(number - 2) + Fibonacci(number - 1);
}
```
**Answer:** O(2^n)

This is because the Fibonacci function is a classic example of exponential time complexity. It makes two recursive calls for each input, and the number of recursive calls grows exponentially with the input.

---

Question #2
**What is the time complexity of this function / algorithm?**
```python
def func(n):
    a = 5
    b = 6
    c = 10
    for i in range(n):
        for j in range(n):
            x = i * i
            y = j * j
            z = i * j
    for k in range(n):
        w = a * k + 45
        v = b * b
    d = 33
```
**Answer:** O(n^2)

The function contains two nested loops, making it quadratic. The time complexity is directly proportional to the square of the input size.

---

Question #3
**What is the time complexity of searching for an element in a singly linked list of size n?**
**Answer:** O(n)

In the worst case, when the element is at the end of the list or not present, you may need to traverse the entire list. Therefore, the time complexity is linear, O(n).

---

Question #4
**Assuming you have a pointer to the node to set the value of, what is the time complexity of setting the value of the nth element in a doubly linked list?**
**Answer:** O(1)

With a pointer to the nth element, you can directly access and modify the value of the element in constant time, making it O(1).

---

Question #5
**What is the time complexity of inserting after the nth element of a singly linked list? (Assuming you have a pointer to the node to insert)**
**Answer:** O(1)

If you have a pointer to the node after which you want to insert, you can perform the insertion in constant time, making it O(1).

---

Question #6
**What is the time complexity of removing at index n from an unsorted Python 3 list?**
**Answer:** O(n)

In the worst case, you may need to traverse the entire list to find the element at index n, making it a linear time operation, O(n).

---

Question #7
**What is the time complexity of this function / algorithm?**
```javascript
var factorial = function(n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
```
**Answer:** O(n)

The function calculates the factorial of a number using recursion, and it makes n recursive calls. Therefore, the time complexity is O(n).

---

Question #8
**What is the time complexity of removing at index n in an unsorted array?**
**Answer:** O(n)

In the worst case, you may need to shift all elements after index n to fill the gap created by the removal, resulting in a linear time operation, O(n).

---

Question #9
**What is the time complexity of this function / algorithm?**
```c
void f(int n)
{
    int i;
    int j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
}
```
**Answer:** O(n^2)

The function contains two nested loops, making it quadratic. The time complexity is directly proportional to the square of the input size, O(n^2).

---

Question #10
**What is the time complexity of “pushing” an element into a queue if you are given a pointer to both the head and the tail of the queue?**
**Answer:** O(1)

With pointers to both the head and tail of the queue, you can directly insert an element at the end of the queue in constant time, making it O(1).

---

Question #11
**What is the time complexity accessing the nth element in an unsorted Python 3 list?**
**Answer:** O(1)

Accessing an element by index in an unsorted list can be done in constant time, O(1), as it doesn't depend on the size of the list.

---

Question #12
**What is the time complexity of the “pop” operation onto a stack?**
**Answer:** O(1)

Popping an element from the top of a stack can be done in constant time, O(1), as it directly accesses the top element.

---

Question #13
**What is the time complexity of setting the value of the nth element in a singly linked list? (Assuming you have a pointer to the node to set the value of)**
**Answer:** O(1)

With a pointer to the nth node, you can directly access and modify the value in constant time, making it O(1).

---

Question #14
**What is the time complexity of accessing the nth element of a doubly linked list?**
**Answer:** O(n)

In a worst-case scenario, you may need to traverse the list from the beginning or end to reach the nth element, resulting in linear time complexity, O(n).

---

Question #15
**What is the time complexity of this function / algorithm?**
```c
void f(unsigned int n)
{
    int i;
    for (i = 1; i < n; i = i * 2)
    {
        printf("[%d]\n", i);
    }
}
```
**Answer:** O(log(n))

The function contains a loop where the variable "i" doubles in each iteration. This results in a logarithmic time complexity, O(log(n)), as it depends on how many times "i" can double to reach n.

---

Question #16
**What is the time complexity of this function / algorithm?**
```php
foreach($numbers as $number)
{
    echo $number;
}
```
**Answer:** O(n)

In this loop, you iterate through each element of the array exactly once, resulting in linear time complexity, O(n), as it depends on the size of the array.

---

Question #17
**What is the time complexity of worst case deletion from a hash table with the implementation you used during the previous Hash Table C project (chaining)?**
**Answer:** O(n)

In the worst case, all elements hash to the same bucket, causing the linked list in that bucket to grow to the size of the hash table. Deleting an element in this scenario would require traversing this linked list, resulting in linear time complexity, O(n).

---

Question #18
**What is the time complexity of the “push” operation onto a stack?**
**Answer:** O(1)

Pushing an element onto a stack can be done in constant time, O(1), as it directly adds the element to the top of the stack.

---

Question #19
**What is the time complexity of this function / algorithm?**
```c
void f(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("[%d]\n", i);
    }
}
```
**Answer:** O(n)

The function contains a loop that iterates from 0 to n, making it linear in terms of time complexity, O(n).

---

Question #20
**What is the time complexity of accessing the nth element of a singly linked list?**
**Answer:** O(n)

In a worst-case scenario, you may need to traverse the list from the beginning to reach the nth element, resulting in linear time complexity, O(n).

---

Question #21
**What is the time complexity of this function / algorithm?**
```c
void f(int n)
{
    int i;
    for (i = 0; i < n; i += 98)
    {
        printf("[%d]\n", i);
    }
}
```
**Answer:** O(n)

The function contains a loop that iterates from 0 to n with a step of 98. Despite the step size, the time complexity is still linear, O(n), as it depends on the value of n.

---

Question #22
**What is the time complexity of searching for an element in an unsorted Python 3 list of size n?**
**Answer:** O(n)

In the worst case, you may need to traverse the entire list to find the element, resulting in linear time complexity, O(n).

---

Question #23
**What is the time complexity of setting a value at index n in an unsorted array?**
**Answer:** O(1)

Setting a value at a specific index in an array can be done in constant time, O(1), as it directly accesses the index.

---

Question #24
**What is the time complexity of inserting at index n on an unsorted array?**
**Answer:** O(n)

Inserting an element at a specific index in an unsorted array may require shifting all elements to make space, resulting in linear time complexity, O(n).

---

Question #25
**What is the time complexity of accessing the nth element on an unsorted array?**
**Answer:** O(1)

Accessing an element by index in an unsorted array can be done in constant time, O(1), as it doesn't depend on the size of the array.

---

Question #26
**What is the time complexity of this function / algorithm?**
```c
void f(int n)
{
    printf("n = %d\n", n);
}
```
**Answer:** O(1)

This function doesn't contain any loops or operations that depend on the input size, so it has a constant time complexity, O(1).

---

Question #27
**What is the time complexity of setting value at index n in an unsorted Python 3 list?**
**Answer:** O(1)

Setting a value at a specific index in an unsorted list can be done in constant time, O(1), as it directly accesses the index.

---

Question #28
**What is the best case time complexity searching for an element in a hash table with the implementation you used during the previous Hash Table C project (chaining)?**
**Answer:** O(1)

In the best case, if hash table keys are uniformly distributed, searching in a hash table can be done in constant time, O(1), as you can directly access the bucket with the key.

---

Question #29
**What is the time complexity of removing the nth element of a singly linked list? (Assuming you have a pointer to the node to remove)**
**Answer:** O(1)

With a pointer to the node to remove, you can directly unlink and remove the node in constant time, making it O(1).

---

Question #30
**What is the time complexity of this function / algorithm?**
```c
void f(int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 1; j < n; j = j * 2)
            {
                printf("[%d] [%d]\n", i, j);
            }
        }
        else
        {
            for (j = 0; j < n; j = j + 2)
            {
                printf("[%d] [%d]\n", i, j);
            }
        }
    }
}
```
**Answer:** O(n log n)

This function contains nested loops, one with a linear iteration and another with a logarithmic iteration. The overall time complexity is O(n log n).

---

Question #31
**What is the best case time complexity of insertion in a hash table with the implementation you used during the previous Hash Table C project (chaining)?**
**Answer:** O(1)

In the best case, if hash table keys are uniformly distributed, inserting into a hash table can be done in constant time, O(1), as you can directly append to the appropriate bucket.

---

Question #32
**What is the time complexity of searching for an element in a doubly linked list of size n?**
**Answer:** O(n)

In a worst-case scenario, you may need to traverse the entire doubly linked list to find the element, resulting in linear time complexity, O(n).

---

Question #33
**Assuming you have a pointer to the node to insert, what is the time complexity of inserting after the nth element of a doubly linked list?**
**Answer:** O(1)

With a pointer to the node to insert after, you can directly perform the insertion in constant time, O(1).

---

Question #34
**What is the time complexity of searching for an element in an unsorted array of size n?**
**Answer:** O(n)

In the worst case, you may need to traverse the entire array to find the element, resulting in linear time complexity, O(n).

---

Question #35
**What is the time complexity of this function / algorithm?**
```c
void f(unsigned int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j = j * 2)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
}
```
**Answer:** O(n log n)

This function contains nested loops, one with a linear iteration and another with a logarithmic iteration. The overall time complexity is O(n log n).

---

Question #36
**Assuming you have a pointer to the node to remove, what is the time complexity of removing the nth element of a doubly linked list?**
**Answer:** O(1)

With a pointer to the node to remove, you can directly unlink and remove the node in constant time, making it O(1).

---

Question #37
**What is the time complexity of searching for an element - worst case - in a hash table with the implementation you used during the previous Hash Table C project (chaining)?**
**Answer:** O(n)

In the worst case, if all keys collide in a single bucket, searching in the hash table may require traversing a linked list of n elements, resulting in linear time complexity, O(n).

---

Question #38
**What is the time complexity of “popping” an element in a queue if you are given a pointer to both the head and the tail of the queue?**
**Answer:** O(1)

Popping an element from the head of a queue can be done in constant time, O(1), as it directly removes the element from the head.

---

Question #39
**What is the worst case time complexity of insertion in a hash table with the implementation you used during the previous Hash Table C project (chaining)?**
**Answer:** O(n)

In the worst case, if all keys collide in a single bucket, inserting into the hash table may require traversing a linked list of n elements, resulting in linear time complexity, O(n).

---

Question #40
**What is the time complexity of inserting into an unsorted Python 3 list at index n?**
**Answer:** O(n)

Inserting an element at a specific index in an unsorted list may require shifting all subsequent elements, resulting in linear time complexity, O(n).

---

Question #41
**What is the time complexity of searching for an element in a queue of size n if you are given a pointer to both the head and the tail of the queue?**
**Answer:** O(n)

In the worst case, you may need to traverse the entire queue to find the element, resulting in linear time complexity, O(n).

---

Question #42
**What is the time complexity of searching for an element in a stack of size n?**
**Answer:** O(n)

In the worst case, you may need to pop all elements from the stack to find the desired element, resulting in linear time complexity, O(n).
---------------------------------------

#### Big O notation
- It is the relative representation of the complexity of an algorithm

#### Selection sort
- It repeatedly selects the smallest (or largest element from the unsorted position ) of the list and swaps it with the first element of the unsorted part. This process is repeated for the remaining unsorted portion until the entire list is sorted .

```c
#include stdio.h
void swap(int arr)
{
	for (i = 1; i < sizeof(arr); i++)
	{
		j = 0;
		if (arr[j] > arr[i])
		{
			int temp;
			arr[j] = temp;
			arr[i] = arr[j]
			arr[j] = temp
		}
		j++;
		
	}
}
```
-----------------------
Time Complexity
- __Time Complexity Equation__ ~ Works by inserting the size of the data-set as an integer n, and returning the number of operations that need to be conducted by the computer before the function can finish  
	N - The size of the data set (Amount of element contained within the data structure)
 ##### Types of time complexity 
 1. Constant time O(1) - the algorithmic time is constant and not dependent  on the input size, the most efficient time complexity 
 2. Logarithmic time O(log(n)) - it grows logarithmically with the input size. common in binary search algorithms.
 3. Linear time O(n) - the algorithm time increases linearly with the input size . good perfomance for many algorithm
 4. Linearithmic Time O(n * log(n))  -  the algorithm runtime grows slower than quadratic but faster than linear. example merge sort and quick sort.
 5. Factorial time O(n!) - The algorithm runtime grows factorially with the input size. It is extremely inneficient.
 6. Exponential time O(2^n) - The algorithm runtime grows exponentially with the input size . common in brute force algorithms
 7. Quadratic time O(n^2) - The algorithm runtime grows with the  square of the input size .
- **O(1)** - Excellent/Best
- **O(log n)** - Good
- **O(n)** - Fair
- **O(n log n)** - Bad
- **O(n^2)**, **O(2^n)** and **O(n!)** - Horrible/Worst
- When your calculation is not dependent on the input size, it is a constant time complexity (O(1)).
- When the input size is reduced by half, maybe when iterating, handling [recursion](https://joelolawanle.com/posts/recursion-in-javascript-explained-for-beginners), or whatsoever, it is a logarithmic time complexity (O(log n)).
- When you have a single loop within your algorithm, it is linear time complexity (O(n)).
- When you have nested loops within your algorithm, meaning a loop in a loop, it is quadratic time complexity (O(n^2)).
- When the growth rate doubles with each addition to the input, it is exponential time complexity (O2^n).

------------------------
## Array Sorting Algorithms

|Algorithm|Time Complexity|   |           |Space Complexity|
|---|---|---|---|---|
			|Best|       Average|  Worst|  Worst|
|[Quicksort](http://en.wikipedia.org/wiki/Quicksort)|`Ω(n log(n))`|`Θ(n log(n))`|`O(n^2)`|`O(log(n))`|
|[Mergesort](http://en.wikipedia.org/wiki/Merge_sort)|`Ω(n log(n))`|`Θ(n log(n))`|`O(n log(n))`|`O(n)`|
|[Timsort](http://en.wikipedia.org/wiki/Timsort)|`Ω(n)`|`Θ(n log(n))`|`O(n log(n))`|`O(n)`|
|[Heapsort](http://en.wikipedia.org/wiki/Heapsort)|`Ω(n log(n))`|`Θ(n log(n))`|`O(n log(n))`|`O(1)`|
|[Bubble Sort](http://en.wikipedia.org/wiki/Bubble_sort)|`Ω(n)`|`Θ(n^2)`|`O(n^2)`|`O(1)`|
|[Insertion Sort](http://en.wikipedia.org/wiki/Insertion_sort)|`Ω(n)`|`Θ(n^2)`|`O(n^2)`|`O(1)`|
|[Selection Sort](http://en.wikipedia.org/wiki/Selection_sort)|`Ω(n^2)`|`Θ(n^2)`|`O(n^2)`|`O(1)`|
|[Tree Sort](https://en.wikipedia.org/wiki/Tree_sort)|`Ω(n log(n))`|`Θ(n log(n))`|`O(n^2)`|`O(n)`|
|[Shell Sort](http://en.wikipedia.org/wiki/Shellsort)|`Ω(n log(n))`|`Θ(n(log(n))^2)`|`O(n(log(n))^2)`|`O(1)`|
|[Bucket Sort](http://en.wikipedia.org/wiki/Bucket_sort "Only for integers. k is a number of buckets")|`Ω(n+k)`|`Θ(n+k)`|`O(n^2)`|`O(n)`|
|[Radix Sort](http://en.wikipedia.org/wiki/Radix_sort "Constant number of digits 'k'")|`Ω(nk)`|`Θ(nk)`|`O(nk)`|`O(n+k)`|
|[Counting Sort](https://en.wikipedia.org/wiki/Counting_sort "Difference between maximum and minimum number 'k'")|`Ω(n+k)`|`Θ(n+k)`|`O(n+k)`|`O(k)`|
|[Cubesort](https://en.wikipedia.org/wiki/Cubesort)|`Ω(n)`|`Θ(n log(n))`|`O(n log(n))`|`O(n)`|

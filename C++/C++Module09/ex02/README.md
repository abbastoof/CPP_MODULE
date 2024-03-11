# Element Insertion in Sorted List

This document explains the process of inserting elements from a smaller partition into a sorted larger list, ensuring the larger list remains sorted.

Initially, our larger elements list is `[10, 20, 30, 40]`.

### First Partition: `[5, 15]`

- For the first element `5`:
  - **`currentIndex`**: Starts at `0`.
  - **`totalInserted`**: Initially `1`.
  - **`distance`**: From the beginning of the partition to the current element is `0`.

The `currentIndex` is updated after each insertion by adding the size of the current partition. For the next partition, it would start at `2` (the size of the previous partition).

To determine the insertion point (`insertionPoint`) for each element, we calculate it as `currentIndex + totalInserted - distance`. For the first element `5`, `insertionPoint` is `1`. This suggests that `5` should be inserted before the second element of the larger list.

We use `std::lower_bound` to find the exact position (`targetPosition`) within the larger list where the element should be inserted. For `5`, it's at the beginning, resulting in a larger elements list of `[5, 10, 20, 30, 40]`.

- For the second element `15`:
  - **`currentIndex`** remains `0`.
  - **`totalInserted`** is now `2`.
  - `insertionPoint` is calculated as `1`, indicating `15` should be inserted before the second element of the current larger list (`[5, 10, 20, 30, 40]`).

`std::lower_bound` finds that `15` should be inserted between `10` and `20`, so after insertion, the larger elements list becomes `[5, 10, 15, 20, 30, 40]`.

### Process Continuation

`currentIndex` is then updated based on the size of the partition just processed. This process is repeated for each partition, ensuring that every smaller element finds its correct place in the sorted larger elements list.

Using `targetPosition` ensures that each smaller element is inserted in the right order, maintaining the sorted sequence of the larger elements, which is crucial for the merge operation's correctness in a sorting algorithm.

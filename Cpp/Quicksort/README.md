<h1>Quick Sort Algorithm</h1>


Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays. A large array is partitioned into two arrays one of which holds values smaller than the specified value, say pivot, based on which the partition is made and another array holds values greater than the pivot value.

Quicksort partitions an array and then calls itself recursively twice to sort the two resulting subarrays. This algorithm is quite efficient for large-sized data sets as its average and worst-case complexity are O(n2), respectively.
<br /><br /><br />
![QuickSORT](https://user-images.githubusercontent.com/93043766/195206286-bafbb40d-7fd8-4e7f-a665-af82a4a48bfa.png)


***<h3>Algorithm:</h3>***

```
Quick_SORT(arr, beg, end)  
  
Step 1 − Choose the highest index value has pivot
Step 2 − Take two variables to point left and right of the list excluding pivot
Step 3 − left points to the low index
Step 4 − right points to the high
Step 5 − while value at left is less than pivot move right
Step 6 − while value at right is greater than pivot move left
Step 7 − if both step 5 and step 6 does not match swap left and right
Step 8 − if left ≥ right, the point where they met is new pivot
  
END Quick_SORT  
```
<br /><br />




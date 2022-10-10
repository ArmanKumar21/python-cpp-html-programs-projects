<h1>Merge Sort Algorithm</h1>


Merge Sort is one of the most popular sorting algorithms that is based on the principle of Divide and Conquer Algorithm.

Here, a problem is divided into multiple sub-problems. Each sub-problem is solved individually. Finally, sub-problems are combined to form the final solution.
<br /><br /><br />
![MergeSortTutorial](https://user-images.githubusercontent.com/103835667/194925985-6c8f4b28-c570-4097-844f-4075a4f3ec45.png)


***<h3>Algorithm:</h3>***

```
MERGE_SORT(arr, beg, end)  
  
if beg < end  
set mid = (beg + end)/2  
MERGE_SORT(arr, beg, mid)  
MERGE_SORT(arr, mid + 1, end)  
MERGE (arr, beg, mid, end)  
end of if  
  
END MERGE_SORT  

```
<br /><br />

**<h3>Merge Sort Working Process:</h3>**


Think of it as a recursive algorithm continuously splits the array in half until it cannot be further divided. This means that if the array becomes empty or has only one element left, the dividing will stop, i.e. it is the base case to stop the recursion. If the array has multiple elements, split the array into halves and recursively invoke the merge sort on each of the halves. Finally, when both halves are sorted, the merge operation is applied. Merge operation is the process of taking two smaller sorted arrays and combining them to eventually make a larger one.

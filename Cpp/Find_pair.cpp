
 
 
Input:
 
nums = [5, 2, 6, 8, 1, 9]
target = 12
 
Output: Pair not found
Practice This Problem

There are several methods to solve this problem using brute-force, sorting, and hashing. These are discussed below:

1. Using Brute-Force
A naive solution is to consider every pair in the given array and return if the desired sum is found. This approach is demonstrated below in C, Java, and Python:


class Main
{
    // Naive method to find a pair in an array with a given sum
    public static void findPair(int[] nums, int target)
    {
        // consider each element except the last
        for (int i = 0; i < nums.length - 1; i++)
        {
            // start from the i'th element until the last element
            for (int j = i + 1; j < nums.length; j++)
            {
                // if the desired sum is found, print it
                if (nums[i] + nums[j] == target)
                {
                    System.out.printf("Pair found (%d, %d)", nums[i], nums[j]);
                    return;
                }
            }
        }
 
        // we reach here if the pair is not found
        System.out.println("Pair not found");
    }
 
    public static void main (String[] args)
    {
        int[] nums = { 8, 7, 2, 5, 3, 1 };
        int target = 10;
 
        findPair(nums, target);
    }
}


Output:

Pair found (8, 2)
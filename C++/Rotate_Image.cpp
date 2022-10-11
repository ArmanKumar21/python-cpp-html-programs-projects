/*
To rotate a matrix by 90 degrees we need to follow only 2 simple steps:

    Convert the given matrix into its transpose matrix.
    Take the mirror image of the transpose matrix assuming the mirror is on the right side of the matrix

The resulting matrix is the required matrix.

I suggest you to visualise this yourself by taking a random N*N matrix. And observe the changes after every sttep. This would help in building a better approach for similar questions.

Below is the code for the proposed solution.
*/

void rotate(vector<vector<int>> &matrix)
{
    // The  idea is to take the transpose once and then taking the mirror image
    // The above process will result in rotating the picture by 90 degrees

    // Taking transpose
    int n = matrix.size();
    for (int row = 0; row < n; ++row)
    {
        for (int col = row; col < n; ++col)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    // Taking the mirror image with the mirror being on the right side

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n / 2; ++col)
        {
            swap(matrix[row][col], matrix[row][n - 1 - col]);
        }
    }
}
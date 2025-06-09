// https://leetcode.com/problems/fill-a-special-grid/
class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        vector<vector<int>> grid(size, vector<int>(size));
        solve(grid, 0, size, 0, size);
        return grid;
    }
private:
    int val = 0;
    void solve(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        int size = rowEnd - rowStart;
        if(size == 1){
            grid[rowStart][colStart] =val++;
            return;
        }
        int midRow = rowStart + size/2;
        int midCol = colStart + size/2;

        solve(grid, rowStart, midRow, midCol, colEnd);
        solve(grid, midRow, rowEnd, midCol, colEnd);
        solve(grid, midRow, rowEnd, colStart, midCol);
        solve(grid, rowStart, midRow, colStart, midCol);
    }
};

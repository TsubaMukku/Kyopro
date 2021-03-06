
/*

*/

/* answer1: brute-force approach */

class Solution {
    private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        
        for (int i = 0; i != row; i++){
            for (int j = 0; j < n; j++){
                int rowDistance = row - i;
                int colDistance = abs(j - col);
                if (nQueens[i][j] == 'Q' && rowDistance == colDistance){
                    return false;
                }
            }
        }
        return true;
    }
   
public:
     int solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return (int)res.size();
    }
    
    int totalNQueens(int n) {
        return solveNQueens(n);
    }
};

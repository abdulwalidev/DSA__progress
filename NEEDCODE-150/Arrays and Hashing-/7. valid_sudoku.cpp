class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        

        // 9 sets for rows, 9 for columns, 9 for 3x3 boxes
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        
        // Go through entire board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                
                // Skip empty cells
                if (num == '.') continue;
                
                // Calculate which 3x3 box this cell belongs to
                int boxIndex = (i / 3) * 3 + (j / 3);
                
                // Check if number already seen in row, column, or box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false;  // Duplicate found!
                }
                
                // Add number to respective sets
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        
        return true;  // No duplicates found so valid!
   








    }
};

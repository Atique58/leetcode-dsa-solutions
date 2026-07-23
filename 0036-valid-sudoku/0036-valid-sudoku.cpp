class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
                 unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> boxes[9];

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(board[r][c] == '.')
                {
                    continue;
                }

                char num = board[r][c];

                int boxIndex = (r / 3) * 3 + (c / 3);

                if(rows[r].find(num) != rows[r].end())
                {
                    return false;
                }

                if(columns[c].find(num) != columns[c].end())
                {
                    return false;
                }

                if(boxes[boxIndex].find(num) != boxes[boxIndex].end())
                {
                    return false;
                }

                rows[r].insert(num);
                columns[c].insert(num);
                boxes[boxIndex].insert(num);
            }
        }

        return true;                   
    }
};
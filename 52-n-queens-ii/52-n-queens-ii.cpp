class Solution {
public:
    
    int res;

    bool isCrossed(int row, int col, vector<pair<int,int>> posns){
        for(auto posn: posns){
            if(row == posn.first || abs(row - posn.first) == abs(col - posn.second))
                return true;
        }
        return false;
    }
    
    void allQueensMine(vector<pair<int,int>>posns, int row, int col, int n){
        if(isCrossed(row, col, posns))
            return;
        
        if(col == n)
        {
            res++;
            return;
        }
        
        posns.push_back({row,col});
        for(int i = 1; i <= n; i++){
            allQueensMine(posns, i, col+1, n);
        }
        posns.pop_back();
        return;
    }
    
    int totalNQueens(int n) {
        for(int i = 1; i <= n; i++){
            vector<pair<int,int>>p;
            allQueensMine(p, i, 1, n);
        }
        return res;
    }
};
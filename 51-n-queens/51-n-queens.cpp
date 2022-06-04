class Solution {
public:
    
    bool isCrossing(vector<pair<int,int>>posns, int row, int col){
        for(auto posn: posns){
            int x = posn.first;
            int y = posn.second;
            if(row == x || abs(row - x) == abs(col - y)){
                return true;
            }
        }
        return false;
    }
    vector<vector<string>>res;
    
    void allQueensMine(int n, int row, int col, vector<pair<int,int>> & posn, vector<string> &stemp){
        
        if(isCrossing(posn, row, col)){
            return;
        }
        
        posn.push_back({row, col});
        if(n == col){
            res.push_back(stemp);
            posn.pop_back();
            return;
        }
        for(int i = 1; i <= n; i++){
            stemp[i-1][col] = 'Q';
            allQueensMine(n, i, col + 1, posn, stemp);
            stemp[i-1][col] = '.';
        }
        posn.pop_back();
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        string s;
        for(int i = 0; i < n; i++){
            s+='.';
        }
        vector<string>stemp;
        for(int i = 0; i < n; i++){
            stemp.push_back(s);
        }
        
        for(int i = 1; i <= n; i++){
            vector<pair<int,int>>p;
            stemp[i-1][0] = 'Q';
            allQueensMine(n, i, 1, p, stemp);
            stemp[i-1][0] = '.';
        }
        
        return res;
    }
};
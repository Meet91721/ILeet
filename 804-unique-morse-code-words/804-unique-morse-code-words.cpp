class Solution {
public:
    
    
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string>morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>ss;
        for(int i = 0; i < words.size(); i++){
            string s;
            for(int j = 0; j < words[i].length(); j++){
                s+=morse[words[i][j]-'a'];
            }
        //     cout << s << " ";
            ss.insert(s);
        }
        return ss.size();
    }
};
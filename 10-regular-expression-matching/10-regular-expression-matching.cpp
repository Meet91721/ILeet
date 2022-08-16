class Solution {
public:
    
    bool funcc(int ind1, int ind2, string &s, string &p){
        if(ind1 == s.length() && ind2 == p.length())
            return true;
        if(ind2 >= p.length())
            return false;
        if(ind1 >= s.length()){
            while(true){
                if(ind2 == p.length())
                    return true;
                if(ind2==p.length()-1)
                    return false;
                
                if(p[ind2+1]=='*')
                    ind2+=2;
                else
                    return false;
            }
        }
        
        if(ind2==p.length()-1){
            if(p[ind2] == '.'){
                return funcc(ind1+1,ind2+1,s,p);
            }
            if(s[ind1] == p[ind2]){
                return funcc(ind1+1,ind2+1,s,p);
            }
            return false;
        }
        
        if(p[ind2+1] == '*'){
            if(p[ind2]==s[ind1] || p[ind2] == '.')
                return funcc(ind1,ind2+2,s,p) || funcc(ind1+1,ind2,s,p) || funcc(ind1+1,ind2+2,s,p);
            
            return funcc(ind1, ind2+2, s, p);
        }
        
        if(p[ind2] == '.')
            return funcc(ind1+1,ind2+1,s,p);

        if(p[ind2] == s[ind1])
            return funcc(ind1+1,ind2+1,s,p);
        
        return false;
    }
    
    bool isMatch(string s, string p) {
        string newS;
        for(int i = 0; i < p.length(); i++){
            if(p[i] != '*'){
                newS+=p[i];
            }
            else{
                while(i < p.length() && p[i] == '*')
                    i++;
                newS+='*';
                i--;
            }
        }
        p = newS;
        cout << p << '\n';
        return funcc(0,0,s,p);
    }
};
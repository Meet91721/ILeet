class Solution {
public:
    
    bool strongPasswordCheckerII(string password) {
        if(password.length() < 8)
            return false;
        bool isCapital = false;
        bool isDigit = false;
        bool isSmall = false;
        bool isChar = false;
        
        for(int i = 0; i < password.size(); i++){
            if(password[i]>='A' && password[i] <= 'Z')
                isCapital = true;
            if(password[i]>='a' && password[i] <= 'z'){
                isSmall = true;
            }
            if(password[i]>='0' && password[i] <= '9')
                isDigit = true;
            //!@#$%^&*()-+
            if(password[i]=='!' ||password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='&' || password[i]=='^' || password[i]=='*' || password[i]=='*' || password[i]=='(' || password[i]==')' || password[i]=='-' || password[i]=='+')
                isChar = true;
            if(i>0){
                if(password[i] == password[i-1])
                    return false;
            }
        }
        return isCapital & isDigit & isSmall & isChar;
    }
};
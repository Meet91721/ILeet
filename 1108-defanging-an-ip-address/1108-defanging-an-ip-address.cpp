class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        int found = address.find('.');
        int l = 0;
        while(found != string::npos){
            res+=address.substr(l,found-l)+"[.]";
            l = found+1;
            found = address.find('.', l);
        }
        res+=address.substr(l,address.size()-l);
        return res;
    }
};
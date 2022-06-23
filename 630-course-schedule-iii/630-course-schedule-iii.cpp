class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() == 0)
            return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        
        multiset<int, greater<int>> s;
        int sum = 0;
        for(auto it: courses){
            sum+=it[0];
            s.insert(it[0]);
            if(sum > it[1]){
                sum-=*s.begin();
                s.erase(s.begin());
            }
        }
        return s.size();
    }
};
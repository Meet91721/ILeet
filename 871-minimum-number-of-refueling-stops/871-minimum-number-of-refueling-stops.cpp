class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        multiset<int,greater<int>>fuels;
        int distance = startFuel;
        int stops = 0;
        for(int i = 0; i < stations.size(); i++){
            if(stations[i][0]<=distance){
                fuels.insert(stations[i][1]);
            }
            else{
                while(distance<stations[i][0] && fuels.size()>0){
                    distance+=*fuels.begin();
                    fuels.erase(fuels.begin());
                    stops++;
                }
                if(distance<stations[i][0])
                    return -1;
                fuels.insert(stations[i][1]);
            }
        }
        while(distance<target && fuels.size()>0){
            distance+=*fuels.begin();
            fuels.erase(fuels.begin());
            stops++;
        }
        if(distance<target)
            return -1;
        return stops;
    }
};

/*
    0           10  11  12  15
    14           2   5   2
*/
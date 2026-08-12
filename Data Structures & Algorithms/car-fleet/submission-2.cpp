class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int , double>>time;
        stack<double>s;
        int n = position.size();
        int res = 1;
        for(int i = 0 ; i< n; i++)
        {
            double cal = (double) (target - position[i])/speed[i];
            time.push_back( {position[i] ,cal});
        }
        sort(time.begin() , time.end() , [](auto &a , auto &b){
           return a.first>b.first;
        });
        
        for(auto x: time)
        {
            double pussy = x.second;
            if(s.empty() || pussy>s.top())
            s.push(pussy);
        }
        return s.size();
    }
};

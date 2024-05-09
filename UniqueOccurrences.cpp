class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int>um;
        unordered_set<int>us;
        for(int i=0;i<arr.size();i++)
        {
            um[arr[i]]++;
        }
        for(auto x:um)
        {
            if(us.find(x.second)!=us.end())
            {
                return false;
            }
            us.insert(x.second);
        }
        return true;
    }
};
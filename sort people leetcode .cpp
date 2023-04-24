class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
               for(int i=0;i<names.size()-1;i++)
        {
            for(int j=i+1;j<names.size();j++)
            {
                if(heights[i]<heights[j])
                {
                    swap(names[i],names[j]);
                    swap(heights[i],heights[j]);
                }
            }
        }
        return names;

    }
};

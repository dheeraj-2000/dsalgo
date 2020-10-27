/* Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' */



vector<vector<int> > Solution::anagrams(const vector<string> &A)
{
    vector<string> arr(A.size());
    for(int i =0; i < A.size(); i++)
    {
        string s = A[i];
        sort(s.begin(), s.end()); //sorted anagrams are same strings eg cat, tac become act
        arr[i] = s;
    
    }
    vector<vector<int>> ans;
    unordered_map<string, vector<int>> mp;
    for(int i =0; i < arr.size(); i++)
    {
        if(mp.find(arr[i]) != mp.end())
        {
            mp[arr[i]].push_back(i+1);
            
        }
        else
        mp[arr[i]].push_back(i+1);
        
    }
    for(auto it = mp.begin(); it != mp.end(); it ++)
    {   
        vector<int> v = it->second;    //vector of indices that are anagrams
        
        ans.push_back(v);
    
    
        
    }
    
    return ans;
}

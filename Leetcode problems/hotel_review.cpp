struct trie
{
    int isLeaf;
    trie *child[26];
};

trie *getNode()
{
    trie *node = new trie();
    for(int i=0; i<26; i++)
        node->child[i] = NULL;
    node->isLeaf = 0;
    
    return node;
}

void insert(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            curr->child[idx] = getNode();
        
        curr = curr->child[idx];
    }
    curr->isLeaf = 1; 
}

int search(trie *A, string s)
{
    trie *curr = A;
    
    for(int i=0; i<s.size(); i++)
    {
        int idx = int(s[i] - 'a');
        if(!curr->child[idx])
            return 0;
        
        curr = curr->child[idx];
    }
    return (curr && curr->isLeaf);
}

void convert(string &str)
{
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)	 
    {
	if(str[i] == '_')	
	     str[i] = ' ';
    }
    return;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.first == b.first) 
        return a.second < b.second;
    
    return a.first > b.first;	
}

vector<int> Solution::solve(string A, vector<string> &B)
{
    vector<int > v;
    vector<pair<int, int>> v1;

    trie *root = getNode();
    
    convert(A);
    
    string word;

    stringstream ss;

    ss<<A;

    while(ss>>word)	
        insert(root, word);
	
    int cnt;
    for(int i=0; i<B.size(); i++)
    {
	convert(B[i]);
	ss.clear();

	ss<<B[i];

	cnt = 0;
	while(ss>>word)	
	{
	    if(search(root, word))	
		cnt++;
	}
	v1.push_back({cnt, i});
    }
    
    sort(v1.begin(), v1.end(), cmp);
    
    for(int i=0; i<B.size(); i++)
        v.push_back(v1[i].second);
    
    return v;
    
}


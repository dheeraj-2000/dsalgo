#include<bits/stdc++.h>
using namespace std;
//Time complexity :- linear time i.e O(n)
void Vertical_Order_Traversal(Node *root, int horizontal_distance, map<int,vector<int>>&nodes)
{
    if(root == NULL) //Base Case
    return;
    nodes[horizontal_distance].push_back(root->data);
    //left node is at horizontal distance - 1 from that of its parent
    Vertical_Order_Traversal(root->left, horizontal_distance - 1, nodes);
        //right node is at horizontal distance + 1 from that of its parent
    Vertical_Order_Traversal(root->right, horizontal_distance + 1, nodes);
    
}
int main()
{
    map<int,vector<int>> nodes;
    Vertical_Order_Traversal(root,0,nodes);
    // To print the vertical order traversal
    auto iterator = nodes.begin();
    while(iterator != nodes.end())
    {
        for(int current_index  = 0; current_index < iterator.size(); current_index++)
        {
            cout<<iterator->second[current_index];
        }
        iterator++;
    }
}
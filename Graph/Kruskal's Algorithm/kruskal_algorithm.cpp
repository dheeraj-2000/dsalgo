#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000005
ll id[MAX];

// We use disjoint sets to detect whether adding a edge to the growing tree creates a cycle or not.

/**
    This function set's up the array to implement disjoint sets
*/
void setDisjoint(){
    for(ll i=0; i< MAX; i++)
        id[i] = i;
}

/**
    This function takes the number and returns its root in disjoint set
*/
ll root(ll n){
    while(id[n] != n){
        id[n] = id[id[n]];
        n = id[n];
    }
    return n;
}

/**
        This function takes two number and puts them in same set i.e. performs the union operation
*/
void disjointUnion(ll from, ll to){
    ll p = root(from);
    ll q = root(to);
    id[p] = id[q];
}

/**
    This function implements the kruskal's algorithm
*/
ll kruskal(pair< ll, pair <ll, ll > > p[], ll nodes, ll edges)
{
    ll minCost = 0;
    for(ll i=0; i<edges; i++){
        ll from = p[i].second.first;
        ll to = p[i].second.second;
        ll weight = p[i].first;

        // Checking if adding the edge creates a cycle?
        if(root(from) != root(to)){
            minCost += weight;
            disjointUnion(from,to);
        }
    }
    return minCost;
}

int main()
{
    ll nodes, num_of_edges;
    ll from, to, weight;
    setDisjoint();
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> num_of_edges;

    pair< ll, pair <ll, ll > > edges[num_of_edges];

    cout << "Enter the edges in order of : from to weight\n";
    for(ll i=0; i<num_of_edges; i++){
        cin >> from >> to >> weight;
        edges[i] = make_pair(weight, make_pair(from, to));
    }

    sort(edges, edges + num_of_edges);
    ll MST = kruskal(edges, nodes, num_of_edges);

    cout << "Minimum cost spanning tree is : " << MST << endl;
    return 0;
}

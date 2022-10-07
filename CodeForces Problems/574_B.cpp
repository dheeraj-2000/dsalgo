#include <bits/stdc++.h>
#include <list>

#define f first
#define s second
#define pb push_back

using namespace std;

const int MAX = 4001;
const int inf = 10000000;

int n, m, c, b;
int mini = inf;

int contlig[MAX];

list<int> grafo[MAX];

typedef pair<int, int> liga;

void calcular(int a, int b, int c){
    int aux = 0;

    aux += contlig[a] - 2;
    aux += contlig[b] - 2;
    aux += contlig[c] - 2;

    if(aux < mini)
        mini = aux;
}

void bfs(int no){
    int vis[MAX];
    for(int i = 0; i < MAX; i ++)
        vis[i] = inf;

    queue<liga> q;
    q.push({no, 2});
    vis[no] = 0;

    while(!q.empty()){
        liga l = q.front();
        int a = l.f;
        int rest = l.s;
        q.pop();

        if(rest == 0)
            continue;

        for(int e : grafo[a]){
           if(vis[e] == inf){
                vis[e] = rest;
                q.push({e, rest-1});
           } else if(vis[e] == vis[a]){
                calcular(no, a, e);
           }
        }
    }
}

void prep(){

    for (int i = 0; i < MAX; i++)
		contlig[i] = 0;

}

int main(){

    prep();

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> b >> c;
        grafo[c].pb(b);
        grafo[b].pb(c);
        contlig[c]++;
        contlig[b]++;
    }

    for(int i = 1; i < (n + 1); i ++){
        bfs(i);

    }

    if(mini == inf){
        cout << -1 << endl;
    } else {
        cout << mini << endl;
    }

}
#include <bits/stdc++.h>

#define N 100
#define VISITED true
#define UNVISITED false

using namespace std;

typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

vii graph[N];
bitset <N> dfs_num;

void action(int u) {
    cout << u << " ";
}

void dfs(int u) {
    action(u);
    dfs_num[u] = VISITED;
    int total = graph[u].size();
    for (int j = 0; j < total; j++) {
        ii v = graph[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

int main() {
    int u = 0;
    string line, node;
    while(!cin.eof()) {
        getline(cin, line);
        istringstream input;
        input.str(line);
        while (getline(input, node, ' ')) {
            graph[u].push_back({atoi(node.c_str()), 0});
        }
        u++;
    }
    dfs(0);
    cout << endl;
    return 0;
}

//Pakkawat Kaolim 66070503446
#define MAX_NODE 100000
using namespace std;
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

void dfs(vector<vector <int>> &graph, int v){
    stack<int> st;
    vector<bool> visited(MAX_NODE, false);

    st.push(v);
    visited[v] = true;
    cout << v << " ";

    while(!st.empty()){
        int node = st.top();
        int i = 0;
        while(true){
            if(!visited[graph[node][i]]){
                visited[graph[node][i]] = true;
                node = graph[node][i];
                st.push(node);
                cout << node << " ";
                i = 0;
            }else{
                i++;
            }

            if(i >= graph[node].size())
                break;
        }
        st.pop();
    }
}

void bfs(vector<vector <int>> &graph, int v){
    queue<int> q;
    vector<bool> visited(MAX_NODE, false);

    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i = 0; i < graph[node].size(); i++){
            if(!visited[ graph[node][i] ]){
                q.push(graph[node][i]);
                visited[graph[node][i]] = true ;
            }
        }
    }
}

int main(){
    int n_edges, start ,node, connected_node;
    cin >> n_edges;

    vector<vector<int>> adjLi(MAX_NODE);

    for(int i = 0; i < n_edges; i++){
        cin >> node >> connected_node;
        adjLi[node].push_back(connected_node);
        adjLi[connected_node].push_back(node);
    }

    cin >> start;
    dfs(adjLi, start);
    cout << "\n";
    bfs(adjLi, start);
    cout << "\n";

    return 0;
}
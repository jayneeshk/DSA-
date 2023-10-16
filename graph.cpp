#include <bits/stdc++.h>
using namespace std;
class Graph{
    int v;//No. of Vertices
    vector<list<int>>adj;//Pointer to an array containing adjacency lists
public:
    Graph(int v){
        this->v=v;
        adj.resize(v);
    }
    void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void BFS(int s){
        vector<bool>visited;
        visited.resize(v,false);
        queue<int>q;
        visited[s]=true;
        q.push(s);
        while(!q.empty()){
            s=q.front();
            cout<<s<<" ";
            q.pop();

            for(auto i:adj[s]){
                if(!visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
    }
    void DFS(int s){
        vector<bool>visited;
        visited.resize(v,false);
        stack<int>st;
        visited[s]=true;
        st.push(s);
        while(!st.empty()){
            s=st.top();
            cout<<s<<" ";
            st.pop();
            for(auto i:adj[s]){
                if(!visited[i]){
                    visited[i]=true;
                    st.push(i);
                }
            }
        }

    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    cout<<"Following is Breadth First Traversal"<<"Starting from source s"<<endl;
    g.BFS(0);
    cout<<"Following is Depth First Traversal"<<"Starting from source s"<<endl;
    g.DFS(0);
    return 0;

};
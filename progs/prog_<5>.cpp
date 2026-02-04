#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

class graph{
    private:
    int vertices;
    vector<vector<int>> adjmatrix;

    public:
    graph(int vert): vertices(vert){
        adjmatrix.resize(vertices,vector<int>(vertices,0));
    }

    void addedge(int u, int v){
        if(u>=0 && u< vertices && v>=0 && v<vertices){
            adjmatrix[u][v]=1;
            adjmatrix[v][u]=1;
        }
    }


    void BFS(int start){
        if (start<0|| start>=vertices)return;

        vector<bool> visited(vertices,false);
        queue<int> q;

        cout<< ":BFS starting from vert"<<start<< ":";

        visited[start]=true;
        q.push(start);

        while (!q.empty()){
            int curr=q.front();
            q.pop();
            cout<< curr<<" ";

            for (int i=0;i<vertices;i++){
                if(adjmatrix[curr][i]==1 && !visited[i]){
                    visited[i]=true;
                    q.push(i);
                }
            }
            




        }
        cout <<endl;
        

    }

    void DFS(int start){
        if(start<0||start>=vertices) return;
        vector<bool> visited(vertices,false);
        stack<int> s;


        cout<< "DFS from "<<start<< " ";

        s.push(start);

        while(!s.empty()){
            int curr =s.top();
            s.pop();
            if(!visited[curr]){
                visited[curr]=true;
                cout<<curr<<" ";
                
                for (int i=vertices-1;i>=0;i--){
                    if(adjmatrix[curr][i]==1 && !visited[i]){
                        s.push(i);

                    }
                }
            }
        }
        cout <<endl;

    }

    void display(){
        for (int i=0;i<vertices;i++){
            for (int j=0 ;j<vertices;j++){
                cout <<adjmatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};


int main(){

    graph g(7);

    g.addedge(0,1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(1, 4);
    g.addedge(2, 5);
    g.addedge(2, 6);
    g.addedge(3, 4);
    g.addedge(5, 6);
    
    g.display();

    cout<<"BFS\n";
    g.BFS(0);

    cout <<"DFS\n";
    g.DFS(0);

    return 0;

}


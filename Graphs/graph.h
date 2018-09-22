#include<list>
#include<vector>
#include<iostream>
using namespace std;

class graph{
  int vert;
  list<int>*adjList;
public:
  graph(int v){
    vert = v;
    adjList = new list<int>[vert];
  }
  void addEdge(int u, int v, bool biDir = true){
    adjList[u].push_back(v);
    if(biDir){
      adjList[v].push_back(u);
    }
  }
  void printEdge(){
    for(int i = 0; i < vert; i++){
      cout << i << "-->";
      for(int x:adjList[i]){
        cout << x << ",";
      }
      cout << endl;
    }
  }
};

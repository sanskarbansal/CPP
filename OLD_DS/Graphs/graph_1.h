#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
  int Vert;
public:
  list<int>* adjList;

  Graph(int v){
    Vert = v;
    adjList = new list<int>[v];
  }

  void add(int v, int u, bool bidir = true){
    adjList[v].push_back(u);
    if(bidir){
      adjList[u].push_back(v);
    }
  }

  void print(){
    for(int i = 0; i < Vert; i++){
      cout << i << "==>";
      for(int x:adjList[i]){
        cout << x << ",";
      }
      cout << endl;
    }
  }
};

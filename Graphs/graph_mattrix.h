#include<iostream>
using namespace std;

class graph{
  int vert;
  int** edge;
public:
  graph(int vert){
    this -> vert = vert;
    edge = new int*[vert];
    for(int i = 0; i < vert; i++){
      edge[i] = new int[vert];
      for(int j = 0; j < vert; j++){
        edge[i][j] = 0;
      }
    }
  }
  ~graph(){
    for(int i = 0; i < vert; i++){
      delete [] edge[i];
    }
  }
  void addEdge(int f, int s, int biDir = true){
    edge[f][s] = 1;
    if(biDir){
      edge[s][f] = 1;
    }
  }
  void print(int sv){
    bool *visited = new bool[vert];
    print(sv, visited);
    delete [] visited;
  }

};

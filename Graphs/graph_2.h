#include<map>
#include<list>
using namespace std;

template<typename t>
class Graph{
  int vert;
  map<t, list<t>> adjList;
public:
  void add(t v, t u , bool bidir = true){
    adjList[v].push_back(u);
    if(bidir){
      adjList[u].push_back(v);
    }
  }
  void print(){
    for(auto i: adjList){
      t key = i.first;
      cout << key << "-->";
      for(t el: i.second){
        cout << el << ",";
      }
      cout << endl;
    }
  }
};

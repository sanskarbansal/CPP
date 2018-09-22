#include<iostream>
#include "graph.h"
using namespace std;

int main(){
  graph q(3);
  q.addEdge(0,1);
  q.addEdge(0,2);
  q.addEdge(1,2);
  q.printEdge();
}

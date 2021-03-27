#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
	int source;
	int destination;
	int weight;
};

bool compare(Edge e1, Edge e2){
	return e1.weight < e2.weight;
}

int findParent(int v, int *arr){
	if(arr[v] == v){
		return v;
	}
	return findParent(arr[v], arr);
}
Edge* kruskals(Edge *input, int n, int e){
	sort(input, input + e, compare);
	int *parent = new int[n];
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	int count = 0;
	int i = 0;
	Edge *output = new Edge[n-1];
	while(count < n-1){
		Edge currentE = input[i];
		int p1 = findParent(currentE.source, parent);
		int p2 = findParent(currentE.destination, parent);
		if(p1 != p2){
			output[count] = currentE;
			parent[p1] = currentE.destination;
			count++;
		}
	    i++;
	}
	return output;
}


int main(){
	int N, E;
	cin >> N >> E;
	Edge *Graph = new Edge[E];
	for(int i = 0; i < E; i++){
		int s, d, w;
		cin >> s >> d >> w;
		Graph[i].source = s;
		Graph[i].destination = d;
		Graph[i].weight = w;
	}
	char t[25];
	memset(t, '-', 25);
	cout << t << endl;
	Edge *ans  = kruskals(Graph, N, E);
	for(int i = 0; i < N-1; i++){
		cout << ans[i].source << " " << ans[i].destination << " " << ans[i].weight << endl;
	}
}
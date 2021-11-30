#include<bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> integerPair;
void displayAll(vector<int> distances, int verticesNum);
void display(vector<int> distances, int destination);

class Graph{

	int verticesNum = 0;
	list<integerPair> *adjacencyList;

	public:
		Graph(int verticesNum){
			this->verticesNum = verticesNum;
			adjacencyList = new list<integerPair> [verticesNum];
		}

		void addEdge(int node1, int node2, int edgeWeight){
			adjacencyList[node1].push_back(make_pair(node2, edgeWeight));
			adjacencyList[node2].push_back(make_pair(node1, edgeWeight));
		}

		void shortestPath(int start, char answer, int destination){
            priority_queue< integerPair, vector<integerPair>, greater<integerPair> > preProcessedVert;

			vector<int> distances(verticesNum, INF);

			preProcessedVert.push(make_pair(0, start));
			distances[start] = 0;

			while (!preProcessedVert.empty()){
				int minDistVertex = preProcessedVert.top().second;
				preProcessedVert.pop();

				list<integerPair>::iterator i;
				for (i = adjacencyList[minDistVertex].begin(); i != adjacencyList[minDistVertex].end(); ++i){
					int v = (*i).first;
					int weight = (*i).second;

					if (distances[v] > distances[minDistVertex] + weight){
						distances[v] = distances[minDistVertex] + weight;
						preProcessedVert.push(make_pair(distances[v], v));
					}
				}
			}
			if(answer == 'Y'){display(distances, destination);}
			else if(answer == 'N'){displayAll(distances, verticesNum);}
		}
};

/******************** MAIN ********************/
int main(){
	int verticesNum = 13, source, destination = 11;
	char answer;
	Graph g(verticesNum);

	g.addEdge(0, 1, 71);
	g.addEdge(0, 2, 151);
	g.addEdge(1, 3, 75);
	g.addEdge(2, 3, 140);
	g.addEdge(2, 9, 80);
	g.addEdge(2, 10, 99);
	g.addEdge(3, 4, 118);
	g.addEdge(4, 5, 111);
	g.addEdge(5, 6, 70);
	g.addEdge(6, 7, 75);
	g.addEdge(7, 8, 120);
	g.addEdge(8, 9, 146);
	g.addEdge(8, 12, 138);
	g.addEdge(9, 12, 97);
	g.addEdge(10, 11, 211);
	g.addEdge(11, 12, 101);

    cout << "Please enter the starting point : ";
    cin >> source;

    cout << "Do you want a specific destination ? \n(Please answer in Y or N)\n";
    cin >> answer;
    if(answer == 'Y'){
        cout << "Please enter your destination : ";
        cin >> destination;
        g.shortestPath(source, answer, destination);
    }
    else if(answer == 'N'){
        g.shortestPath(source, answer, destination);
    }

	return 0;
}

/******************** Functions *********************/
void displayAll(vector<int> distances, int verticesNum){
    cout << "Vertex\t\tDistance from Source\n";
    for (int i = 0; i < verticesNum; ++i)
        cout << i << "\t\t" << distances[i] << endl;
}

void display(vector<int> distances, int destination){
    cout << "The shortest distance between the source and " << destination;
    cout << " is : " << distances[destination] << endl;
}

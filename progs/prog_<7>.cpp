#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii; 

unordered_map<int, vector<pii>> graph; 


void dijkstra(int start, unordered_map<int, int>& dist, unordered_map<int, int>& prev) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[start ] = 0;

    pq.push({0,start});

    while (!pq.empty ()) {
        int currentDist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (currentDist> dist[current]) continue;

        for (auto& edge:graph[current]) {
            int neighbor= edge.first;
            int weight= edge.second;
            int newDist = currentDist + weight;

            if (newDist< dist[neighbor]) {
                dist[neighbor]= newDist;
                prev[neighbor]= current; 
                pq.push({newDist, neighbor});
            }
        }
    }
}

int main() {
    
    graph[0]= {{1, 4}, {2, 2}};
    graph[1]= {{0, 4}, {2, 1}, {3, 5}};
    graph[2]={{0, 2}, {1, 1}, {3, 8}, {4, 10}};
    graph[3]= {{1, 5}, {2, 8}, {4, 2}, {5, 6}};
    graph[4]= {{2, 10}, {3, 2}, {5, 3}};
    graph[5]= {{3,6}, {4, 3}}; 

    int start = 0;
    unordered_map<int, int> dist, prev;
    for (auto& node: graph) {
        dist[node.first] = INT_MAX;
        prev[node.first] = -1;
    }

    dijkstra(start, dist, prev);

    cout << "Shortest distances from node " << start << "\n";
    for (auto& d : dist) {
        cout << "  " << d.first << ": " << d.second << "\n";
    }

    return 0;
}
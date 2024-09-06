#include<bits/stdc++.h>
using namespace std;


int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<vector<int>> adjacent_stones(n);
    for( int i = 0; i < n; i++ ) {
        for( int j = i+1; j < n; j++){
            if( stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1] ) {
                adjacent_stones[i].push_back(j);
                adjacent_stones[j].push_back(i);
            }
        }
    }

    int numOfConnectedGraphs = 0;
    vector<bool> isVisited(n, false);

    for( int i=0; i < n; i++ ) {
        if( !isVisited[i] ){
            depthFirstSearch(adjacent_stones, isVisited, i);
            numOfConnectedGraphs++;
        }
    }


    return n - numOfConnectedGraphs;
}

void depthFirstSearch(vector<vector<int>> &adjacent_stones, vector<bool> &isVisited, int stone) {
    isVisited[stone] = true;
    for (int neighbor : adjacent_stones[stone]) {
            if (!isVisited[neighbor]) {
                depthFirstSearch(adjacent_stones, isVisited, neighbor);
            }
        }
}

int main(){
    std::vector<std::vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    cout<<removeStones(stones);
}

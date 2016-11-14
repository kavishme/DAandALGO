/*
https://www.hackerrank.com/challenges/balanced-forest
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Edge{
	int node1;
	int node2;

	Edge(){
		node1 = 0;
		node2 = 0;
	}
}

struct node
{
	std::vector<node*> children;
	int index;
	string coin;
	string allcoins;
};


int main() {
    int trees = 0;
    cin>>trees;

    for (int tree = 0; tree < trees; ++tree)
    {
    	int nodes = 0;
    	cin>nodes;

    	std::vector<string> coinsLst;
    	std::vector<Edge*> edgeLst;

    	for (int node = 0; node < nodes; ++node)
    	{	
    		string coin;
    		cin>>coin;
    		coinsLst.push(coin);
    	}

    	for (int edge = 0; edge < nodes-1; ++edge)
    	{
    		Edge* newEdge = new Edge();
    		cin>>newEdge->node1>>newEdge->node2;
    		edgeLst.push(newEdge)
    	}



    }
    return 0;
}
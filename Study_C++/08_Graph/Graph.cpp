#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{

};

vector<Vertex> vertices; // 정점
vector<vector<int>> adjacent; // 연결된 간선
vector<bool> visited; // 방문한 목록
void CreateGraph()
{
	vertices.resize(6); // 정점 6개
	adjacent = vector<vector<int>>(6);
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
}

//DFS
void Dfs(int here)
{
	// 방문
	visited[here] = true;
	cout << "Visited : " << here << endl;
	// 인접 리스트 version
	// 모든 인접 정점을 순회한다
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}
}

void DfsAll()
{
	visited = vector<bool>(6, false);
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
}

int main()
{
	CreateGraph();
	//visited = vector<bool>(6, false);
	//Dfs(0);
	DfsAll();
}
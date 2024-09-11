#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{

};

vector<Vertex> vertices; // 정점
vector<vector<int>> adjacent; // 연결된 간선
vector<bool> visited; // 방문 여부 목록 (깊이)
vector<bool> discovered; // 발견 여부 목록 (너비)
void CreateGraph()
{
	vertices.resize(6); // 정점 6개
	adjacent = vector<vector<int>>(6);

	// 인접 리스트
	adjacent[0].push_back(1);
	adjacent[0].push_back(3);
	adjacent[1].push_back(0);
	adjacent[1].push_back(2);
	adjacent[1].push_back(3);
	adjacent[3].push_back(4);
	adjacent[5].push_back(4);
	
	/*
	// 인접 행렬
	adjacent = vector<vector<int>>
	{
		{ 0, 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0 },
	    { 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0 }
	};
	*/
}


// DFS (Depth First Search) 깊이 우선 탐색
void Dfs(int here)
{
	// 방문
	visited[here] = true;
	cout << "Visited : " << here << endl;
	// 인접 리스트 version
	// 모든 인접 정점을 순회한다
	/*
	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			Dfs(there);
	}
	*/

	// 인접행렬 version
	// 모든 인접 정점을 순회한다
	for (int there = 0; there < 6; there++)
	{
		if (adjacent[here][there] == 0)
			continue;

		// 아직 방문하지 않은 곳이 있으면 방문
		if (visited[there] == false)
			Dfs(there);
	}
}
// DFS All
void DfsAll()
{
	visited = vector<bool>(6, false);
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
			Dfs(i);
	}
}


// Bfs (Breadth First search) 너비 우선 탐색
void Bfs(int here)
{
	// (1) 발견은 여기서
	queue<int> q;
	q.push(here);
	discovered[here] = true;

	// q[ 0  ]

	while (q.empty() == false)
	{
		here = q.front(); // 다음 방문할 정점
		q.pop();
		// (2) 방문은 여기서
		cout << "Visited : " << here << endl;

		for (int there : adjacent[here])
		{
			if (discovered[there])
			{
				continue;
			}

			q.push(there);
			discovered[there] = true;
		}
	}
}

void BfsAll()
{
	for (int i = 0; i < 6; i++)
	{
		if (discovered[i] == false)
			Bfs(i);
	}
}

int main()
{
	CreateGraph();
	//visited = vector<bool>(6, false);
	//Dfs(0);
	//DfsAll();

	discovered = vector<bool>(6, false);
	//Bfs(0);
	BfsAll();
}
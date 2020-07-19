#include <vector>
#include <map>
#include <iostream>

// for illustrative purposes
// simple, undirected, unweighted, graph
// more accurately this is an 'adjacency matrix' maker, since the graph is already present in the input map

struct Graph
{
	int num_vertices_{ 0 };
	std::map<int, std::vector<int>> vertex_connections_;
	std::vector<std::vector<int>>  adjacency_matrix_;
	Graph(int num_vertices, const std::map<int, std::vector<int>>& connections) :
		num_vertices_{ num_vertices }, vertex_connections_{ connections }
	{
		for (int i = 0; i< num_vertices; i++)
		{
			std::vector<int> row;
			for (int j = 0; j< num_vertices; j++)
			{
				row.emplace_back(0);
			}
			adjacency_matrix_.emplace_back(row);
		}

		for (const auto& pair : connections) {
			for (auto&& it : pair.second) {
				adjacency_matrix_[pair.first][it] = 1;
			}
		}
	};

	void visualize()
	{
		for (auto&& row : this->adjacency_matrix_) 
		{
			for (auto&& it : row)
			{
				std::cout << it << " ";
			}
			std::cout << "\n";
		}
	}
};

// example graph
int main()
{
	std::map<int, std::vector<int>> verts;
	verts[2] = std::vector<int>{ 1,0 };
	verts[0] = std::vector<int>{ 2 };

	Graph g{ 3, verts };
	g.visualize();
}
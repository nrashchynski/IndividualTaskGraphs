#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int n, m;
	// std::cin >> n >> m;
	fin >> n >> m;

	std::vector<std::pair<int, int>> edges(m);
	std::map<int, std::vector<int>> neighbours; 
	bool hasLoop = false; 
	bool hasMultipleEdges = false;

	for (int i = 0; i < m; ++i) {
		int u, v; 
		// std::cin >> u >> v; 
		fin >> u >> v;
		edges[i] = { u, v };
		if (u == v) { 
			hasLoop = true; 
		} 
		if (std::find(neighbours[u].begin(), neighbours[u].end(), v) != neighbours[u].end()) {
			hasMultipleEdges = true;
		}
		neighbours[u].push_back(v); 
		neighbours[v].push_back(u);
	}

	bool isGraph = !hasLoop && !hasMultipleEdges;
	bool isMultigraph = !hasLoop;
	bool isPseudograph = true;

	if (isGraph) { 
		// std::cout << "Yes\n"; 
	    fout << "Yes\n";
	}
	else 
		fout << "No\n";
		//std::cout << "No\n";

	if (isMultigraph) { 
		// std::cout << "Yes\n";
		fout << "Yes\n";
	}
	else 
		fout << "No\n";
		// std::cout << "No\n";

	if (isPseudograph) { 
		// std::cout << "Yes\n"; 
		fout << "Yes\n";
	}
	else 
		fout << "No\n";
		// std::cout << "No\n";

	fin.close();
	fout.close();
	return 0;
}
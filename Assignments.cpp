#include <iostream>

#include <vector>
#include <algorithm>

int maximalNetworkRank(int n, std::vector<std::vector<int>>& cables) {
    std::vector<int> connections(n, 0); // Number of connections for each lab

    for (const auto& cable : cables) {
        int lab1 = cable[0];
        int lab2 = cable[1];

        connections[lab1]++;
        connections[lab2]++;
    }

    int maxRank = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int rank = connections[i] + connections[j];

            if (std::find(cables.begin(), cables.end(), std::vector<int>{i, j}) != cables.end() ||
                std::find(cables.begin(), cables.end(), std::vector<int>{j, i}) != cables.end()) {
                // If the cable between labs i and j exists, subtract 1 from rank
                rank--;
            }

            maxRank = std::max(maxRank, rank);
        }
    }

    return maxRank;
}
int main() {
    int n;
    std::cout << "Enter the number of labs: ";
    std::cin >> n;

    int numCables;
    std::cout << "Enter the number of cables: ";
    std::cin >> numCables;

    std::vector<std::vector<int>> cables(numCables);
    std::cout << "Enter the cable connections in the format [a, b]:\n";
    for (int i = 0; i < numCables; i++) {
        std::cout << "Cable " << i + 1 << ": ";
        int lab1, lab2;
        char comma;
        std::cin >> comma >> lab1 >> comma >> lab2 >> comma;
        cables[i] = { lab1, lab2 };
    }

    int maxRank = maximalNetworkRank(n, cables);
    std::cout << "Maximal network rank: " << maxRank << std::endl;

    return 0;
}
/*
Enter the number of labs : 4
Enter the number of cables : 4
Enter the cable connections in the format[a, b] :
    Cable 1 : [0, 1]
    Cable 2 : [0, 3]
    Cable 3 : [1, 2]
    Cable 4 : [1, 3]
    Maximal network rank : 4
*/
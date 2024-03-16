#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Define a struct to represent an edge between nodes
struct Edge
{
  string source;
  string target;
  string interaction;
};

// Function to create the political network
void createPoliticalNetwork(unordered_map<string, string> &nodeTypes, vector<Edge> &edges)
{
  // Input nodes
  int numPoliticians, numParties, numInterestGroups, numLobbyists;
  cout << "Enter the number of politicians: ";
  cin >> numPoliticians;
  for (int i = 0; i < numPoliticians; ++i)
  {
    string politicianName = "Politician" + to_string(i + 1);
    nodeTypes[politicianName] = "politician";
  }

  cout << "Enter the number of political parties: ";
  cin >> numParties;
  for (int i = 0; i < numParties; ++i)
  {
    string partyName = "Party" + to_string(i + 1);
    nodeTypes[partyName] = "party";
  }

  cout << "Enter the number of interest groups: ";
  cin >> numInterestGroups;
  for (int i = 0; i < numInterestGroups; ++i)
  {
    string groupName = "Group" + to_string(i + 1);
    nodeTypes[groupName] = "interest_group";
  }

  cout << "Enter the number of lobbyists: ";
  cin >> numLobbyists;
  for (int i = 0; i < numLobbyists; ++i)
  {
    string lobbyistName = "Lobbyist" + to_string(i + 1);
    nodeTypes[lobbyistName] = "lobbyist";
  }

  // Input edges
  int numEdges;
  cout << "Enter the number of interactions (edges): ";
  cin >> numEdges;
  for (int i = 0; i < numEdges; ++i)
  {
    Edge edge;
    cout << "Enter source node: ";
    cin >> edge.source;
    cout << "Enter target node: ";
    cin >> edge.target;
    cout << "Enter interaction type (e.g., co-sponsorship, donation, voting): ";
    cin >> edge.interaction;
    edges.push_back(edge);
  }
}

int main()
{
  unordered_map<string, string> nodeTypes; // Map to store node types (e.g., politician, party)
  vector<Edge> edges;                      // Vector to store edges between nodes

  cout << "Welcome to Political Network Analysis Tool!" << endl;
  cout << "------------------------------------------" << endl;

  createPoliticalNetwork(nodeTypes, edges);

  // Outputting the created network
  cout << "Nodes and their types:" << endl;
  for (const auto &node : nodeTypes)
  {
    cout << "Node: " << node.first << ", Type: " << node.second << endl;
  }

  cout << "Edges (Interactions):" << endl;
  for (const auto &edge : edges)
  {
    cout << "Source: " << edge.source << ", Target: " << edge.target << ", Interaction: " << edge.interaction << endl;
  }

  return 0;
}

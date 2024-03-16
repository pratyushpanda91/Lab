#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Define a struct to represent an intersection with its properties
struct Intersection
{
  int id;
  vector<int> outgoingEdges;
};

// Function to optimize traffic signal timings
void optimizeTrafficSignals(const vector<Intersection> &intersections)
{
  // Implement the optimization algorithm here
  // This could involve adjusting signal timings based on traffic data and network properties
  // For simplicity, we'll just print the current state of each intersection
  for (const auto &intersection : intersections)
  {
    cout << "Intersection " << intersection.id << ":" << endl;
    cout << "Outgoing edges: ";
    for (int edge : intersection.outgoingEdges)
    {
      cout << edge << " ";
    }
    cout << endl;
  }
}

int main()
{
  int numIntersections;
  cout << "Enter the number of intersections: ";
  cin >> numIntersections;

  vector<Intersection> intersections(numIntersections);
  unordered_set<int> intersectionIDs;

  // Input intersections and their outgoing edges
  for (int i = 0; i < numIntersections; ++i)
  {
    int id, numEdges;
    cout << "Enter intersection ID: ";
    cin >> id;

    // Check if the intersection ID is unique
    if (intersectionIDs.find(id) != intersectionIDs.end())
    {
      cout << "Intersection ID already exists. Please enter a unique ID." << endl;
      --i; // Decrement i to re-enter the current intersection
      continue;
    }
    intersectionIDs.insert(id);

    intersections[i].id = id;

    cout << "Enter the number of outgoing edges for intersection " << id << ": ";
    cin >> numEdges;

    // Input outgoing edges
    cout << "Enter outgoing edges for intersection " << id << ": ";
    for (int j = 0; j < numEdges; ++j)
    {
      int edge;
      cin >> edge;
      intersections[i].outgoingEdges.push_back(edge);
    }
  }

  // Optimize traffic signals
  optimizeTrafficSignals(intersections);

  return 0;
}

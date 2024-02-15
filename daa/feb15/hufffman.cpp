#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
  char data;
  int frequency;
  Node *left;
  Node *right;

  Node(char c, int freq) : data(c), frequency(freq), left(nullptr), right(nullptr) {}
};

// Function to build Huffman tree
Node *buildHuffmanTree(vector<Node *> &nodes)
{
  while (nodes.size() > 1)
  {
    sort(nodes.begin(), nodes.end(), [](const Node *a, const Node *b)
         { return a->frequency > b->frequency; });

    Node *left = nodes.back();
    nodes.pop_back();
    Node *right = nodes.back();
    nodes.pop_back();

    Node *internalNode = new Node('$', left->frequency + right->frequency);
    internalNode->left = left;
    internalNode->right = right;

    nodes.push_back(internalNode);
  }

  return nodes.front();
}

// Function to generate Huffman codes
void generateCodes(Node *root, string code, unordered_map<char, string> &huffmanCodes)
{
  if (root)
  {
    if (root->data != '$')
    {
      huffmanCodes[root->data] = code;
    }
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
  }
}

int main()
{
  string input;
  cout << "Enter the string to be encoded: ";
  getline(cin, input);

  unordered_map<char, int> frequencyMap;
  for (char c : input)
  {
    frequencyMap[c]++;
  }

  vector<Node *> nodes;
  for (auto &entry : frequencyMap)
  {
    nodes.push_back(new Node(entry.first, entry.second));
  }

  Node *root = buildHuffmanTree(nodes);

  unordered_map<char, string> huffmanCodes;
  generateCodes(root, "", huffmanCodes);

  cout << "\nHuffman Codes:\n";
  for (auto &entry : huffmanCodes)
  {
    cout << entry.first << ": " << entry.second << endl;
  }

  return 0;
}

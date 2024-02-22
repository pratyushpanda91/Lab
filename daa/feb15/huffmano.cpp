#include <bits/stdc++.h>
using namespace std;
struct Huffman_Node
{
  char data;
  unsigned freq;
  Huffman_Node *left, *right;
  Huffman_Node(char data, unsigned freq)
  {

    left = right = NULL;
    this->data = data;
    this->freq = freq;
  }
};

struct Compare
{
  bool operator()(Huffman_Node *l, Huffman_Node *r)
  {
    return (l->freq > r->freq);
  }
};

void print_Tree(struct Huffman_Node *root, string str)
{
  if (!root)
    return;
  if (root->data != '#')
    cout << root->data << "    | " << str << "\n";
  print_Tree(root->left, str + "0");
  print_Tree(root->right, str + "1");
}

void HuffCodes(char data[], int freq[], int size)
{
  struct Huffman_Node *left, *right, *top;
  priority_queue<Huffman_Node *, vector<Huffman_Node *>, Compare> Min_Heap;

  for (int i = 0; i < size; ++i)
    Min_Heap.push(new Huffman_Node(data[i], freq[i]));

  while (Min_Heap.size() != 1)
  {

    left = Min_Heap.top();
    Min_Heap.pop();

    right = Min_Heap.top();
    Min_Heap.pop();
    top = new Huffman_Node('#', left->freq + right->freq);

    top->left = left;
    top->right = right;

    Min_Heap.push(top);
  }

  cout << "Char | Huffman code ";
  cout << "\n----------------------\n";
  print_Tree(Min_Heap.top(), "");
}

// Driver Code
int main()
{
  int choice = 0;
  cout << "_ _ _Enter choice for type of input_ _ _" << endl;
  cout << "Enter 1 to enter string..." << endl;
  cout << "Enter 2 to enter characters and its frequency respectively..." << endl;
  cin >> choice;
  switch (choice)
  {
  case 1:
  {
    string str = "";
    cout << "Enter string: ";
    cin >> str;
    multiset<char> ms;
    for (int i = 0; i < str.length(); i++)
    {
      ms.insert(str[i]);
    }

    set<char> set_char;
    auto it = ms.begin();
    vector<int> set_freq;
    for (int i = 0; i < str.length(); i++)
    {
      set_char.insert(*it);
      it++;
    }
    int size = 0;
    for (auto it : set_char)
    {
      set_freq.push_back(ms.count(it));
      size++;
    }
    auto it_f = set_freq.begin();
    char arr[size];
    int freq[size];
    auto it_char = set_char.begin();
    auto it_freq = set_freq.begin();
    for (int i = 0; i < size; i++)
    {
      arr[i] = *it_char;
      freq[i] = *it_freq;
      it_char++;
      it_freq++;
    }
    HuffCodes(arr, freq, size);
    return 0;
  }
  case 2:
  {
    int size = 0;
    cout << "Enter number of charcters: ";
    cin >> size;
    char arr[size];
    int freq[size];
    for (int i = 1; i <= size; i++)
    {
      cout << "Enter charcater " << i << ": ";
      cin >> arr[i - 1];
      cout << "Enter frequency of " << arr[i - 1] << ": ";
      cin >> freq[i - 1];
    }
    cout << endl;
    HuffCodes(arr, freq, size);
    return 0;
  }
  default:
  {
    cout << "Invalid choice...";
    return 0;
  }
  }
  return 0;
}
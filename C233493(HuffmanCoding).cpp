#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void generateCodes(Node* root, string code,
                   unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (root->ch != '\0')
        huffmanCode[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

int main() {
    string text = "BCCABBDDAECCBBAEDDCC";

    unordered_map<char, int> freq;
    for (char c : text)
        freq[c]++;

    cout << "Frequencies:\n";
    for (auto p : freq)
        cout << p.first << " : " << p.second << endl;

    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto p : huffmanCode)
        cout << p.first << " : " << p.second << endl;

    int originalLength = text.length() * 8;
    cout << "\nOriginal Length : " << originalLength << " bits\n";

    int compressedLength = 0;
    for (char c : text)
        compressedLength += huffmanCode[c].length();

    cout << "Compressed message length : "
         << compressedLength << " bits\n";

    int tableBits = 0;
    for (auto p : huffmanCode)
        tableBits += 8 + p.second.length();

    cout << "Table : " << tableBits << " bits\n";

    int newLength = compressedLength + tableBits;
    cout << "New length : " << newLength << " bits\n";

    return 0;
}

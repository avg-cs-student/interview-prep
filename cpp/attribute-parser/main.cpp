#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_VAL = 20;
const int MAX_LINE = 200;
const string NONE = "Not Found!";

struct Node {
    string tag;
    vector<string> attr;    // list of attributes
    vector<Node*> children; // list of child nodes
                            
    Node(string p_tag) : tag(p_tag), attr(0), children(0) {};
    ~Node() {
        for (auto &child : this->children)
            delete(child);
    }
};


string query_src(string query, vector<Node*> &taglist) {
    // stub
    string rv = NONE;
    
    return query;
}

Node *parse_src_line(string src) {
    Node *rv = nullptr;

    return rv;
}

int main() {

    int n; // number of lines in src program
    int q; // number of queries
    vector<Node*> taglist;
    
    // line 1, get n and q
    cin >> n >> q;
    cin.ignore(); // consume '\n'
    
    char src[n][MAX_LINE];
    int src_index = 0;

    // parse src hrml
    for (int line_index = 0; line_index < n; line_index++) {
        cin.getline(src[line_index], MAX_LINE);
    }
    
    // store queries
    char query[q][MAX_LINE];
    for (int i = 0; i < q; i++) {
        cin.getline(query[i], MAX_LINE);
    }
    
    // evaluate queries
    for (int i = 0; i < q; i++) {
        cout << query_src(query[i], taglist) << endl;
    }
    
    
    return 0;
}


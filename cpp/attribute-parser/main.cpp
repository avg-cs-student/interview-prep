#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Attribute {
    string key;
    string value;

    Attribute(string key, string value) : key(key), value(value) {};
    ~Attribute() {};

    void print_data() {
        cout << this->key << " " << this->value << endl;
    }
};

struct Tag {
    string key;
    vector<Attribute*> attributes;
    Tag *parent;
    vector<Tag*> children;

    Tag(string key) : key(key) {};
    ~Tag() {
        for (auto a : this->attributes) {
            delete(a);
        }
    }

    void print_data() {
        cout << key << endl;
        for (auto &a: attributes)
            a->print_data();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    cin.ignore();

    vector<Tag*> tag_stack;

    /* grab src code */
    string src_buff;
    for (int i = 0; i < n/2; ++i) {
        getline(cin, src_buff);
        // if we find a '/' in the second position, it's a closing tag
        if (src_buff[1] == '/') {
            --i;
            continue;
        }

        size_t cur = src_buff.find(' ');
        if (cur == string::npos)
            cur = src_buff.length() - 2;

        tag_stack.push_back(new Tag(src_buff.substr(1, cur)));

        /* check for attributes */
        bool hasAttr = true;
        do {
            cur = src_buff.find_first_not_of(" ", cur);
            size_t end_of_attr = src_buff.find("=", cur);
            
            /* go to next tag if no '=' is found */
            if (end_of_attr == string::npos) {
                hasAttr = false;         
                break;
            }
            
            string attr = src_buff.substr(cur, end_of_attr - cur);
            cur = src_buff.find("\"", end_of_attr);
            end_of_attr = src_buff.find("\"", cur+1);
            string attr_data = src_buff.substr(cur+1, end_of_attr - cur -1);

            /* add attribute to corresponding tag */
            tag_stack[i]->attributes.push_back(new Attribute(attr, attr_data));
        } while (hasAttr);
        
    }

    string query;
    for (int i = 0; i < q; ++i) {
        size_t cur = 0;
        getline(cin, query);
        size_t tag_end = query.find(".");
        while (tag_end != string::npos) {
            string tag = query.substr(cur, tag_end);
            cout << tag << endl;
            break;
        }
    }

    return 0;
}


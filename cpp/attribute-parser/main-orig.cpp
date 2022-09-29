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
    int n, q;
    cin >> n >> q;
    cin.ignore();

    vector<Tag*> tag_stack;

    /* grab src code */
    string src_buff;
    for (int i = 0, index = 0; i < n; ++i) {
        getline(cin, src_buff);
        // if we find a '/' in the second position, it's a closing tag
        if (src_buff[1] == '/') 
            continue;

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
            tag_stack[index]->attributes.push_back(new Attribute(attr, attr_data));
        } while (hasAttr);
        ++index;
    }

    string query;
    string subquery;
    for (int i = 0; i < q; ++i) {
        size_t cur = 0;
        getline(cin, query);
        cout << "Query " << i + 1 << endl;
        size_t subq_end = query.find(".");
        size_t q_end = query.find("~");
        while (subq_end < q_end) {
            cout << "Subtag:\t";
            cout << query.substr(cur, subq_end) << endl;
            cur = subq_end + 1;
            subq_end = query.find(".", cur);
        } 

        cout << "Last tag:\t";
        cout << query.substr(cur, query.find("~")) << endl;
        cout << "selecting:\t";
        cout << query.substr(q_end + 1, query.find('\n')) << endl;
//        subquery = query.substr(cur, subq_end);
        /* we now have the query, but it must be parsed */
 //       cout << subquery << endl; 
//        while (tag_end != string::npos) {
//            string tag = query.substr(cur, tag_end);
//            cout << tag << endl;
//            break;
//        }
    }

    return 0;
}


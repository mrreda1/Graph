#include <iostream>
#include <vector>
#include <map>

using namespace std;

class node {
public:
    string name;
    node(string name) {
        this -> name = name;
    }
};

class graph {
private:
    vector<vector<int>> edges;
    vector<node*> nodes;
    map<string, int> keys;

public:
    graph() {}

    int insert(string name) {
        if(keys.count(name) < 0) { 
            node* new_node = new node(name);
            nodes.push_back(new_node);
            edges.push_back({});
            keys.insert(pair<string, int>(name, nodes.size() - 1));
            return nodes.size() - 1;
        }
        return -1;
    }
    bool link(string start, string end) {
        if(keys.count(start) < 0 || keys.count(end) < 0)
            return false;
        edges[keys[start]].push_back(keys[end]);
        return true;
    }
    bool link(int start, int end) {
        if(start >= nodes.size() || end >= nodes.size())
            return false;
        edges[start].push_back(end);
        return true;
    }
    void connections(int node) {
        if(node >= nodes.size())
            return;
        for(int node : edges[node])
            cout << node << ' ';
    }
};

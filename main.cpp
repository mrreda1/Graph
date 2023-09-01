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
        if(keys.find(name) == keys.end()) {
            node* new_node = new node(name);
            nodes.push_back(new_node);
            edges.push_back({});
            keys.insert(pair<string, int>(name, nodes.size() - 1));
            return nodes.size() - 1;
        }
        return -1;
    }
    bool link(string start, string end) {
        if(keys.find(start) == keys.end() || keys.find(end) == keys.end() || start == end)
            return false;

        for(int node : edges[keys[start]])
            if(node == keys[end]) return false;

        edges[keys[start]].push_back(keys[end]);
        return true;
    }
    bool link(int start, int end) {
        if(start >= nodes.size() || end >= nodes.size() || start == end)
            return false;

        for(int node : edges[start])
            if(node == end) return false;

        edges[start].push_back(end);
        return true;
    }
    void connections(int node) {
        if(node >= nodes.size())
            return;
        for(int node : edges[node])
            cout << nodes[node] -> name << ' ';
    }
};

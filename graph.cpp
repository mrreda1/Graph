#include <iostream>
#include <vector>
#include <map>

class node {
public:
    std::string name;
    node(std::string name) {
        this -> name = name;
    }
};

class graph {
private:
    std::vector<std::vector<int>> edges;
    std::vector<node*> nodes;
    std::map<std::string, int> keys;

public:
    graph() {}

    int insert(std::string name) {
        if(keys.find(name) == keys.end()) {
            node* new_node = new node(name);
            nodes.push_back(new_node);
            edges.push_back({});
            keys.insert(std::pair<std::string, int>(name, nodes.size() - 1));
            return nodes.size() - 1;
        }
        return -1;
    }
    bool link(std::string start, std::string end) {
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
            std::cout << nodes[node] -> name << ' ';
    }
    void connections(std::string name) {
        if(keys[name] >= nodes.size())
            return;
        for(int node : edges[keys[name]])
            std::cout << nodes[node] -> name << ' ';
    }
};

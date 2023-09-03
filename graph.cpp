#include <iostream>
#include "queue.cpp"
#include <vector>
#include <map>

class Gnode {
public:
    std::string name;
    Gnode(std::string name) {
        this -> name = name;
    }
};

class graph {
private:
    std::vector<std::vector<int>> edges;
    std::vector<Gnode*> nodes;
    std::map<std::string, int> keys;

public:
    graph() {}

    int insert(std::string name) {
        if(keys.find(name) == keys.end()) {
            Gnode* new_node = new Gnode(name);
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
    void connections(std::string name) {
        if(keys.find(name) == keys.end())
            return;
        for(int node : edges[keys[name]])
            std::cout << nodes[node] -> name << ' ';
    }
    int shortest_path(std::string start, std::string end) {
        if(keys.find(start) == keys.end() || keys.find(end) == keys.end() || start == end)
            return -1;

        queue_ds<int> q;
        int visited[nodes.size()] = {0};

        visited[keys[start]] = 1;
        q.push(keys[start]);

        while(!q.empty()) {
            int current = q.pop();
            int steps = visited[current];
            if(current == keys[end])
                return visited[current] - 1;
            for(int neighbor : edges[current]) {
                if(visited[neighbor])
                    continue;
                visited[neighbor] = steps + 1;
                q.push(neighbor);
            }
        }
        return -1;
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
};

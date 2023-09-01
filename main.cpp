#include <iostream>
#include <vector>
#include <map>

using namespace std;

class graph {
private:
    vector<vector<int>> edges;
    vector<string> nodes;
    map<string, int> keys;

public:
    graph() {}

    int insert(string name) {
        if(keys.count(name) < 0) { 
            nodes.push_back(name);
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
};

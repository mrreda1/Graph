#include "graph.hpp"

// Graph node
size_t Gnode::counter = 0;

Gnode::Gnode(const char* name) {
	this->id = Gnode::counter++;
	this->name = (char*) malloc(1024*sizeof(char));
    strcpy(this->name, name);
	this->active = true;
}

size_t Gnode::getID() {
	return this->id;
}
const char* Gnode::getName() {
	return this->name;
}
bool Gnode::isActive() {
	return this->active;
}
void Gnode::activate() {
	this->active = true;
}
void Gnode::disable() {
	this->active = false;
}


// Graph
graph::graph() {
}

void graph::insert(const char* name) {
	if (keys.find(name) != keys.end()) {
		nodes[keys[name]]->activate();
		return;
	}

	Gnode *new_node = new Gnode(name);
	std::map<size_t, size_t> node_edges;

	nodes.push_back(new_node);
	edges.push_back(node_edges);
	keys.insert({name, new_node->getID()});
}

void graph::link(const char* src, const char* dst, size_t weight) {
	if (keys.find(src) == keys.end() || keys.find(dst) == keys.end())
		return;

	graph::link(keys[src], keys[dst], weight);
}

void graph::link(size_t src, size_t dst, size_t weight) {
	if (src >= nodes.size() || dst >= nodes.size() ||
		!(nodes[src]->isActive() && nodes[dst]->isActive()))
		return;

	if (edges[src].find(dst) == edges[src].end()) {
		edges[src].insert({dst, weight});
	}
}
void graph::unlink(const char* src, const char* dst) {
	if (keys.find(src) == keys.end() || keys.find(dst) == keys.end())
		return;

	graph::unlink(keys[src], keys[dst]);
}
void graph::unlink(size_t src, size_t dst) {
	if (src >= nodes.size() || dst >= nodes.size() ||
		!(nodes[src]->isActive() && nodes[dst]->isActive()))
		return;

	edges[src].erase(dst);
}
void graph::removeNode(const char* name) {
	if (keys.find(name) != keys.end()) {
		removeNode(keys[name]);
	}
}
void graph::removeNode(size_t node) {
	if (node >= nodes.size() || !nodes[node]->isActive()) {
		return;
	}

	edges[node].clear();

	for (auto m : edges) {
		m.erase(node);
	}

	nodes[node]->disable();
}

std::vector<std::pair<Gnode *, size_t>> graph::connections(const char* name) {
	if (keys.find(name) != keys.end()) {
		return connections(keys[name]);
	}
	return connections(-1);
}

std::vector<std::pair<Gnode *, size_t>> graph::connections(ssize_t node) {
	std::vector<std::pair<Gnode *, size_t>> result;

	if (node < nodes.size() && node >= 0 && nodes[node]->isActive()) {
		for (auto i : edges[node]) {
			result.push_back({nodes[i.first], i.second});
		}
	}
	return result;
}

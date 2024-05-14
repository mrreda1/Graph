#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <map>
#include <vector>

class Gnode {
  private:
	static size_t counter;
	size_t id;
	std::string name;
	bool active;

  public:
	Gnode(std::string name);
	size_t getID();
	void activate();
	void disable();
	bool isActive();
	std::string getName();
};

class graph {
  private:
	std::vector<std::map<size_t, size_t>> edges;
	std::vector<Gnode *> nodes;
	std::map<std::string, size_t> keys;

  public:
	graph();
	void insert(std::string name);
	void link(std::string start, std::string end, size_t weight);
	void link(size_t start, size_t end, size_t weight);
	std::vector<std::pair<Gnode *, size_t>> connections(std::string name);
	std::vector<std::pair<Gnode *, size_t>> connections(ssize_t node);
};

#endif // !GRAPH_HPP

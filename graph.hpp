#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cstring>
#include <iostream>
#include <map>
#include <vector>

class Gnode {
  private:
	static size_t counter;
	size_t id;
	char *name;
	bool active;

  public:
	Gnode(const char *);
	size_t getID();
	void activate();
	void disable();
	bool isActive();
	const char *getName();
};

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return std::strcmp(a, b) < 0;
   }
};

class graph {
  private:
	std::vector<std::map<size_t, size_t>> edges;
	std::vector<Gnode *> nodes;
	std::map<const char *, size_t, cmp_str> keys;

  public:
	graph();
	void insert(const char *);
	void link(const char *, const char *, size_t);
	void link(size_t, size_t, size_t);
	void unlink(const char *, const char *);
	void unlink(size_t, size_t);
	void removeNode(const char *);
	void removeNode(size_t);
	std::vector<std::pair<Gnode *, size_t>> connections(const char *);
	std::vector<std::pair<Gnode *, size_t>> connections(ssize_t);
};

#endif // !GRAPH_HPP

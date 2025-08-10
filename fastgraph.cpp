#include <iostream>
#include <nanobind/nanobind.h>
#include <nanobind/stl/pair.h>
#include <nanobind/stl/vector.h>
#include <boost/graph/adjacency_list.hpp>
namespace nb = nanobind;


class BoostGraph {
public:
    typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;

    Graph g;

    BoostGraph(int num_vertices) : g(num_vertices) {}

    void add_edge(int src, int target) {
        boost::add_edge(src, target, g);
    }

    std::vector<std::pair<int, int>> get_edges() {
        std::vector<std::pair<int, int>> edges_list;
        for (auto e : boost::make_iterator_range(boost::edges(g))) {
            edges_list.emplace_back(boost::source(e, g), boost::target(e, g));
        }
        return edges_list;
    }
};

bool compare(nb::list py_edges ,std::vector<std::pair<int, int>> edges2){

    auto cmp = [](const std::pair<int,int> &a, const std::pair<int,int> &b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    };
    std::vector<std::pair<int, int>> edges1;
	for(auto item : py_edges){
		auto edge = nb::cast<std::pair<int,int>>(item);
		int src = edge.first;
		int tgt = edge.second; 
        edges1.push_back(std::make_pair(src,tgt));
	}
    std::sort(edges1.begin(), edges1.end(), cmp);
    std::sort(edges2.begin(), edges2.end(), cmp);
  
    if ((int)edges1.size()!=(int)edges2.size()){
        return false;
    }
    for(int i=0;i<(int)edges1.size();i++){
        if (edges1[i].first!=edges2[i].first || edges1[i].second!=edges2[i].second) {
            return false;
        }
    }
	return true;
}

NB_MODULE(fastgraph,m){
    nb::class_<BoostGraph>(m, "BoostGraph")
        .def(nb::init<int>(), "Create a BoostGraph with N vertices")
        .def("add_edge", &BoostGraph::add_edge, "Add an edge (src, target)")
        .def("get_edges", &BoostGraph::get_edges, "Get list of edges as (src, target) pairs");

	m.def("compare",&compare,"compare two graphs");
}


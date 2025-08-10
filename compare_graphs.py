import networkx as nx
import sys

sys.path.append('./build')
import fastgraph


g=nx.DiGraph();

g.add_edge(0,1)
g.add_edge(1,2)
g.add_edge(2,3)

edges=list(g.edges())


G = fastgraph.BoostGraph(4)
G.add_edge(2, 3)
G.add_edge(1, 2)
G.add_edge(0, 1)

Edges = G.get_edges()

print(fastgraph.compare(edges,Edges))


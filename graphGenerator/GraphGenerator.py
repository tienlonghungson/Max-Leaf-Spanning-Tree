from igraph import *

n = 100
m = 2000
g = Graph.Erdos_Renyi(n=n, m=m)

edges = g.get_edgelist()

file = open("input.txt", "w")

file.write(str(n) + " " + str(m) + "\n")

for i in range(0, len(edges)):
    file.write(str(edges[i][0]) + " " + str(edges[i][1]) + "\n")

file.close()
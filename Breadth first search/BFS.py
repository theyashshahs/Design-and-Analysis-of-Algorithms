from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEgde(self, a, b):
        self.graph[a].append(b)

    def breadthFirstSearch(self, s):
        visited = [False]*(len(self.graph))

        queue = []

        queue.append(s)
        visited[s] = True

        while queue:

            s = queue.pop(0)
            print(s, end = " ")

            for i in self.graph[s]:

                if (visited[i]  == False):
                    queue.append(i)
                    visited[i] = True


g = Graph()

g.addEgde(0, 1)
g.addEgde(0, 2)
g.addEgde(1, 2)
g.addEgde(1, 4)
g.addEgde(1, 0)
g.addEgde(2, 3)
g.addEgde(2, 1)
g.addEgde(2, 0)
g.addEgde(3, 4)
g.addEgde(3, 2)
g.addEgde(4, 3)
g.addEgde(4, 1)
g.addEgde(4, 5)
g.addEgde(5, 4)

g.breadthFirstSearch(3)
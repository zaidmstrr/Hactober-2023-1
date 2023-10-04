from collections import defaultdict

# Function to create an adjacency list representation of a graph
def create_graph():
    graph = defaultdict(list)
    num_nodes = int(input("Enter the number of nodes: "))
    num_edges = int(input("Enter the number of edges: "))
    
    print("Enter edges in the format 'node1 node2', e.g., 'A B'")
    for i in range(num_edges):
        while True:
            edge = input(f"Enter edge {i + 1}: ").split()
            if len(edge) == 2:
                u, v = edge
                graph[u].append(v)
                graph[v].append(u)  # Assuming an undirected graph
                break
            else:
                print("Invalid input format")
    return graph


# Function for Depth-First Search (DFS)
def dfs_search(graph, node, target, visited):
    if node == target:
        return True  # Target node found

    visited.add(node)

    for neighbor in graph[node]:
        if neighbor not in visited:
            if dfs_search(graph, neighbor, target, visited):
                return True
    return False  # Target node not found

# Create the graph based on user input
user_graph = create_graph()
print(user_graph)

while True:
    start_node = input("Enter the starting node for DFS search: ").strip()
    if start_node in user_graph:
        break
    else:
        print("Invalid starting node. Please enter a valid node.")

target_node = input("Enter the target node for DFS search: ").strip()

# Perform DFS search
visited_nodes = set()
if dfs_search(user_graph, start_node, target_node, visited_nodes):
    print(f"The target node '{target_node}' is reachable from '{start_node}' using DFS.")
else:
    print(f"The target node '{target_node}' is not reachable from '{start_node}' using DFS.")

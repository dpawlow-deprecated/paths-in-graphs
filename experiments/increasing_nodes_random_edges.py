#!/usr/bin/env python3

import numpy as np
import random
import sys


def create_edge(start, finish, weight):
	return {'start': start, 'finish': finish, 'weight': weight}

def print_edges(edges, output):
	for edge in edges:
		output.write(str(edge['start']) + " " + str(edge['finish']) + " " + str(edge['weight']) + "\n")

#amount of nodes increases per iteration, and each one has a random amount of edges

max_amount_nodes = 1000
max_cost = 1000
repetitions = 50

output = open("case_increasing_nodes_random_edges", "a")

for amount_of_nodes in range(0, max_amount_nodes + 1):
	#for each repetition
	for repetition in range(0, repetitions):
		#write the instance
		random_graph = np.random.randint(2, size=(amount_of_nodes, amount_of_nodes))
		amount_of_edges = 0
		edges = []
		
		for i in range(0, amount_of_nodes):
			for j in range(0, amount_of_nodes):
				if random_graph[i][j] == 1 and i != j:
					if random_graph[j][i] == 1:
						random_graph[j][i] = 0
					edges.append(create_edge(i, j, np.random.randint(max_cost + 1)))
					amount_of_edges += 1
		output.write(str(amount_of_nodes) + " " + str(amount_of_edges) + "\n")
		print_edges(edges, output)
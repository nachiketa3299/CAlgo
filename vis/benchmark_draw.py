import json
import matplotlib.pyplot as plt

path = "../build/targets/CalgoBenchmarks/Release/sort_benchmark_results.json"

with open(path, 'r') as f:
  points = json.load(f)

graphs = dict()

for benchmark in points["benchmarks"]:
  algo_name = benchmark["name"].split('/')[-2]

  n_value = int(benchmark["name"].split('/')[-1])
  time = benchmark["real_time"]

  if algo_name not in graphs:
    graphs[algo_name] = []
  
  graphs[algo_name].append((n_value, time))

for algo in graphs:
  graphs[algo].sort(key=lambda x: x[0])
plt.figure(figsize=(10, 8))

print(graphs)

for algo, points in graphs.items():

  x_values = [point[0] for point in points]
  y_values = [point[1] for point in points]

  plt.plot(x_values, y_values, label=algo, linewidth=0.5)

plt.xlabel('Input size (n)')
plt.ylabel('Time (ns)')

plt.xscale('log')
plt.yscale('log')

plt.title('Sorting Algorithm Benchmarks')
plt.grid(True)
plt.legend()

plt.show()


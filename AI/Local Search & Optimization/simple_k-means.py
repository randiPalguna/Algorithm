import math

# Cheatseets:

# centroids: N number of centroid
# centroid: the centroid data (coordinate vector space)
# centroid_elements: the centroid elements (data-i)

# datas: N number of data
# data: the data element (coordinate vector space)
# data_elements: the data elements (d(data-i, centroid-i), ...)

# Iteration is fixed to 4

def euclidean(centroid, data):
  return math.sqrt(pow(abs(centroid[0] - data[0]), 2) + pow(abs(centroid[1] - data[1]), 2)) 

centroids = int(input())
centroid = []
for i in range(centroids):
  centroid.append(list(map(float, input().split())))

datas = int(input())
data = []
for i in range(datas):
  data.append(list(map(float, input().split())))

iterations = 4
it = 0
while (it < iterations):
  it += 1
  # Calculate d using euclidean
  data_elements = []
  for i in range(datas):
    temp = []
    for j in range(centroids):
      temp.append(euclidean(centroid[j], data[i]))
      print("%.2f" % euclidean(centroid[j], data[i]), end=" ")
    data_elements.append(temp)
    print()

  # Merge centroid
  centroid_elements = [[] for _ in range(centroids)]
  for i in range(datas):
    smallest = float('inf')
    for j in range(centroids):
      if (smallest > data_elements[i][j]):
        smallest = data_elements[i][j]
        centroid_index = j
    centroid_elements[centroid_index].append(i)

  # update centroid
  for i in range(centroids):
    if len(centroid_elements[i]) == 0:
      continue
    new_centroid = [0] * len(centroid[0])
    for index in centroid_elements[i]:
      for j in range(len(new_centroid)):
        new_centroid[j] += data[index][j]
    for j in range(len(new_centroid)):
      new_centroid[j] /= len(centroid_elements[i])
    centroid[i] = new_centroid

  print(centroid)
  for i in range(len(centroid_elements)):
    for j in range(len(centroid_elements[i])):
      centroid_elements[i][j] += 1
  print(centroid_elements)
  print()

# Input
# centroids (number of cluster)
# centroids row of cluster
# datas (number of data)
# datas row of cluster
  
# 3
# 2.0 10.0
# 7.0 5.0
# 1.0 2.0
# 8
# 2.0 10.0
# 2.0 5.0
# 8.0 4.0
# 5.0 8.0
# 7.0 5.0
# 6.0 4.0
# 1.0 2.0
# 4.0 9.0

#!/usr/bin/env python3
# _*_ coding: utf-8 _*_
#import numpy
import sys

if __name__ == "__main__":
  filename = sys.argv[1]
  size = int(sys.argv[2])+1
  f=open(filename+".txt","r")
  
  content=""
  maxValue = 0.0
  links=[]
  
  print("Init datastruct!!")
  for count in range(0,size):
    if count%100000==0: print(count)
    x=[]
    links.append(x)

  print ("Init links!")
  count=0
  for row in f:
    if count%100000==0: print(count)
    count=count+1

    dataset=row.split()
    src=int(dataset[0])
    dst=int(dataset[1])
    if dst not in links[src]:
      links[src].append(dst)
    if src not in links[dst]:
      links[dst].append(src)
  f.close()

  print ("Write final undirected unweighted graph!")
  count=0
  w=open(filename+"Final.txt","w")
  w.write("1000 \n")
  for node in range(0, size):
    for neigh in links[node]:
      src = str(node)
      dst = str(neigh)
      w.write(src+" "+dst+"\n")
      if count%100000==0: print(count)
      count=count+1
  w.close()

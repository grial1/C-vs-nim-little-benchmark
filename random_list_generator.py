#!/usr/bin/env python3
import random
import os

if __name__ == "__main__":
  """
    This file generates a list of random integers stored in 1MB regular text file.
  """
  with open("random_list.txt","w+") as f:
    f.write("{}".format(str(random.randint(0,1000000))))
  while os.stat("random_list.txt").st_size < 1000000 :
    with open("random_list.txt","a+") as f:
      f.write(",{}".format(str(random.randint(0,1000000))))

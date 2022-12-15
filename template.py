import sys
import math
from copy import deepcopy
from collections import defaultdict,deque

file = sys.argv[1] if len(sys.argv) > 1 else "inputPartOne.txt"
data = open(file).read().strip()
lines = [x for x in data.split('\n')]
print(lines)
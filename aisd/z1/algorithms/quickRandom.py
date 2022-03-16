import sys
import random
values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

def quickRandom(lst):
    if len(lst) <= 1:
        return lst
    else:
        p = random.choice(lst)
        low  = [x for x in lst if x <  p]
        med  = [x for x in lst if x == p]
        high = [x for x in lst if x >  p]
        return quickRandom(low) + med + quickRandom(high)

quickRandom(values)
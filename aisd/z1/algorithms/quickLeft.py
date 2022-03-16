import sys
values = []
with open(sys.argv[1]) as file:
    val = file.read()
values = [int(x) for x in val.split()]

def quickLeft(lst):
    if len(lst) <= 1:
        return lst
    else:
        p, *rest = lst
        low  = [x for x in rest if x <= p]
        high = [x for x in rest if x >  p]
        return quickLeft(low) + [p] + quickLeft(high)

quickLeft(values)
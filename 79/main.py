with open('keylog.txt') as fp:
    data = fp.readlines()

left_requirements = {}
for l in data:
    number = l.strip()
    lefts = set()
    for n in number:
        if n not in left_requirements:
            left_requirements[n] = set()
        left_requirements[n] |= lefts
        lefts.add(n)

string = ''
while len(left_requirements) > 0:
    added = False
    for n, requirements in left_requirements.items():
        ready = True
        for r in requirements:
            if r not in string:
                ready = False
                break
        if ready:
            string += n
            del left_requirements[n]
            added = True
            break
    if not added:
        raise ValueError('We should insert one number')
print string

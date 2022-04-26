def capitalize(inp):
    string = ""
    if inp.upper() == "HKU":
        return inp.upper()
    temp = list(map(str, inp.split()))
    for i in range(len(temp)):
        string += temp[i][0].upper()
        for j in range(1, len(temp[i])):
            string += temp[i][j].lower()
        if i+1 != len(temp):
            string += " "
    return string

def addFile():
    line = []
    for i in range(len(temp)):
        string = ""
        for j in range(len(temp[i])):
            string += temp[i][j][0].upper()
            for k in range(1, len(temp[i][j])):
                string += temp[i][j][k].lower()
            if j+1 != len(temp[i]):
                string += " "
        if string.lower() == "hku":
            line.append(string.upper())
        else:
            line.append(string)
    return line

def overlapping(line1, line2):
    lst = []
    for i in range(1,len(line1)):
        for j in range(1,len(line2)):
            if line1[i] in line2:
                lst.append(line1[i])
                break
    return list(sorted(set(lst)))

def find_connection(lapped, start, destination, line1, line2):
    if not lapped:
        print("No connection found!")
    elif start in line1:
        print(f"To get from {start} to {destination}, first take {line1[0]} line\nAnd you may change at:\n", end="")
        for i in lapped:
            print(i)
        print(f"to use the {line2[0]} line for your destination")
    elif start in line2:
        print(f"To get from {start} to {destination}, first take {line2[0]} line\nAnd you may change at:\n", end="")
        for i in lapped:
            print(i)
        print(f"to use the {line1[0]} line for your destination")
file = str(input())
if file[-4::] != '.txt':
    file += '.txt'
f = open(file, "r")
temp = []
line1 = []
line2 = []
for i in f:
    temp.append(i.split())
line1 = addFile()
file = str(input())
if file[-4::] != '.txt':
    file += '.txt'
f = open(file, "r")
temp = []
for i in f:
    temp.append(i.split())
line2 = addFile()
lapped = overlapping(line1, line2)
start = str(input())
start = capitalize(start)
destination = str(input())
destination = capitalize(destination)
if start not in line1 and start not in line2 or destination not in line1 and destination not in line2:
    print("Station not found")
elif start in line1 and destination in line1:
    print(f"To get from {start} to {destination} take the {line1[0]} line")
elif start in line2 and destination in line2:
    print(f"To get from {start} to {destination} take the {line2[0]} line")
else:
    find_connection(lapped, start, destination, line1, line2)

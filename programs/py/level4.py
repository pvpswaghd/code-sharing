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

def return_max_index(line):
    max1 = min(line)
    lst = []
    for i in range(len(line)):
        if line[i] == max1:
            lst.append([line[i], i])
    return lst
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
line1_name = line1[0]
line2_name = line2[0]
line1.pop(0)
line2.pop(0)
if start not in line1 and start not in line2 or destination not in line1 and destination not in line2:
    print("Station not found")
elif start in line1 and destination in line1 and start in line1 and destination in line2:
    d1 = abs(line1.index(start) - line1.index(destination))
    d2 = abs(line2.index(start) - line2.index(destination))
    if d1 <= d2:
        order = int(bool(line1.index(start) > line1.index(destination)))*-1
        if order == 0:
            order = 1
        for i in range(line1.index(start), line1.index(destination), order):
            print(f"{line1[i]} ({line1_name} line)")
        print(f"{line1[line1.index(destination)]} ({line1_name} line)")
    elif d1 >= d2:
        order = int(bool(line2.index(start) > line2.index(destination)))*-1
        if order == 0:
            order = 1
        for i in range(line2.index(start), line2.index(destination), order):
            print(f"{line2[i]} ({line2_name} line)")
        print(f"{line2[line2.index(destination)]} ({line2_name} line)")
elif start in line1 and destination in line1:
    order = int(bool(line1.index(start) > line1.index(destination)))*-1
    if order == 0:
        order = 1
    for i in range(line1.index(start), line1.index(destination), order):
        print(f"{line1[i]} ({line1_name} line)")
    print(f"{line1[line1.index(destination)]} ({line1_name} line)")
elif start in line2 and destination in line2:
    order = int(bool(line2.index(start) > line2.index(destination)))*-1
    if order == 0:
        order = 1
    for i in range(line2.index(start), line2.index(destination), order):
        print(f"{line2[i]} ({line2_name} line)")
    print(f"{line2[line2.index(destination)]} ({line2_name} line)")
else:
    if not lapped:
        print("No connection found!")
    elif start in line1:
        print("hello")
        distance = []
        print(lapped)
        if len(lapped) != 1:
            print("hello again")
            for i in lapped:
                print(start, i, destination)
                d = abs(line1.index(start)-line1.index(i)) + abs(line2.index(i)-line2.index(destination))
                distance.append(int(d))
            print(distance)
            lst = return_max_index(distance) #return [maximum distance, index of that distance]
            print(lst)
            if len(lst) == 1:
                station = lapped[lst[0][1]] # it is the station that are the closest
                ind = [line1.index(station), line2.index(station)]
                order = int(bool(line1.index(start) > ind[0]))*-1
                if order == 0:
                    order = 1
                for i in range(line1.index(start), ind[0], order):
                    print(f"{line1[i]} ({line1_name} line)")
                print(f"{line1[ind[0]]} ({line1_name} line)")
                print(f"Change {line1[ind[0]]} to {line2_name} line")
                order = int(bool(ind[1]+order > line2.index(destination)))
                if order == 0:
                    order = 1
                print(ind[1], line2.index(destination))
                for i in range(ind[1]+order, line2.index(destination), order):
                    print(f"{line2[i]} ({line2_name} line)")
                print("FUCK")
        else:
            ind = [line1.index(lapped[0]), line2.index(lapped[0])]
            order = int(bool(line1.index(start) > ind[0]))*-1
            if order == 0:
                order = 1
            for i in range(line1.index(start), ind[0], order):
                print(f"{line1[i]} ({line1_name} line)")
            print(f"{line1[ind[0]]} ({line1_name} line)")
            print(f"Change {line1[ind[0]]} to {line2_name} line")
            order = int(bool(ind[1] > line2.index(destination))) * -1
            if order == 0:
                order = 1
            for i in range(ind[1]+order, line2.index(destination), order):
                print(f"{line2[i]} ({line2_name} line)")
            print("FUCK")
            

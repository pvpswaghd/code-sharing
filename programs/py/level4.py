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

def addFile(temp):
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

def return_min_index(line, status):
    if status:
        max1 = min(line)
    else:
        max1 = max(line)
    lst = []
    for i in range(len(line)):
        if line[i] == max1:
            lst.append([line[i], i])
    return lst

def print_station_change(line1, line2, line1_name, line2_name, lapped, start, destination, station):
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
    for i in range(ind[1]+order, line2.index(destination), order):
        print(f"{line2[i]} ({line2_name} line)")
    print(f"{destination} ({line2_name} line)")

def print_station(line, line_name, start, destination):
    order = int(bool(line.index(start) > line.index(destination)))*-1
    if order == 0:
        order = 1
    for i in range(line.index(start), line.index(destination), order):
        print(f"{line[i]} ({line_name} line)")
    print(f"{line[line.index(destination)]} ({line_name} line)")

def get_file_input():
    temp = []
    file = str(input())
    if file[-4::] != '.txt':
        file += '.txt'
    f = open(file, "r")
    for i in f:
        temp.append(i.split())
    f.close()
    line_temp = addFile(temp)
    return line_temp

def getInfo():
    line1, line2, temp = [], [], []
    line1 = get_file_input()
    line2 = get_file_input()
    lapped = overlapping(line1, line2)
    start = str(input())
    start = capitalize(start)
    destination = str(input())
    destination = capitalize(destination)
    line1_name, line2_name = line1[0], line2[0]
    line1.pop(0)
    line2.pop(0)
    if start not in line1 and start not in line2 or destination not in line1 and destination not in line2:
        print("Station not found")
    elif start in line1 and destination in line1 and start in line2 and destination in line2:
        d1 = abs(line1.index(start) - line1.index(destination))
        d2 = abs(line2.index(start) - line2.index(destination))
        if d1 <= d2:
            print_station(line1, line1_name, start, destination)
        elif d1 >= d2:
            print_station(line2, line2_name, start, destination)
    elif start in line1 and destination in line1:
        print_station(line1, line1_name, start, destination)
    elif start in line2 and destination in line2:
        print_station(line2, line2_name, start, destination)
    else:
        if not lapped:
            print("No connection found!")
        else:
            if start in line2:
                temp_lst = line1.copy()
                line1 = line2.copy()
                line2 = temp_lst.copy()
                line1_name, line2_name = line2_name, line1_name
            distance = []
            if len(lapped) != 1:
                for i in lapped:
                    d = abs(line1.index(start)-line1.index(i)) + abs(line2.index(i)-line2.index(destination))
                    distance.append(int(d))
                lst = return_min_index(distance, True) #return [maximum distance, index of that distance]
                if len(lst) == 1:
                    station = lapped[lst[0][1]] # it is the statio
                    print_station_change(line1, line2, line1_name, line2_name, lapped, start, destination, station)
                else:
                    station, name = {}
                    for i in range(len(lst)):
                        station.append(abs(line1.index(start)-line1.index(lapped[lst[i][1]]))) # find the index to the origin
                        name.append(lapped[lst[i][1]])
                    time.sleep(1)
                    lst = return_min_index(station, True)
                    if len(lst) == 1:
                        index = name[lst[0][1]]
                        print(index)
                        print(lst)
                        print_station_change(line1, line2, line1_name, line2_name, lapped, start, destination, index)
                    else:
                        name = sorted(name)
                        index = name[0]
                        print_station_change(line1, line2, line1_name, line2_name, lapped, start, destination, index)
            else:
                print_station_change(line1, line2, line1_name, line2_name, lapped, start, destination, lapped[0])
getInfo()

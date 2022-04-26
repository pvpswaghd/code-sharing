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
key = str(input())
key = capitalize(key)
finalList = []
for i in range(len(line1)):
    if key == line1[i]:
        finalList.append(line1[0])
        break
for i in range(len(line2)):
    if key == line2[i]:
        finalList.append(line2[0])
        break
if finalList:
    print(f"{key} Station found\nLine(s): ", end="")
    for i in range(0, len(finalList)-1):
        print(f"{finalList[i]}, ", end="")
    print(f"{finalList[-1]}", end="")
else:
    print("Station not found")





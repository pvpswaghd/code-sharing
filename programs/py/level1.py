curr_input = str(input())
temp = []
while curr_input != "-1":
    temp.append(curr_input.split())
    curr_input = str(input())
line1 = addFile()
file = str(input())
if file[-4::] != '.txt':
    file += '.txt'
f = open(file, "r")
temp = []
for i in f:
    temp.append(i.split())
line2 = addFile()
print(line2)
print(line1[0], "line: ", end='')
for i in range(1, len(line1)-1):
    print(line1[i]+"<->", end='')
print(line1[len(line1)-1])
print(line2[0], "line: ", end='')
for i in range(1, len(line2)-1):
    print(line2[i]+"<->", end='')
print(line2[len(line2)-1])


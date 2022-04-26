# Input a string and return a capitalized word
def capitalize(inputStr):
    tmpList = inputStr.split(" ")
    output = ""
    if inputStr.upper() == "HKU":
        return "HKU"
    else:
        for i in range(len(tmpList)):
            tmpString = ""
            for j in range(len(tmpList[i])):
                if j == 0:
                    tmpString += tmpList[i][j].upper()
                else:
                    tmpString += tmpList[i][j].lower()
            if i != len(tmpList) - 1:
                output += tmpString + " "
            else:
                output += tmpString
        return output

# Returning the correct file name
def getExtension(filename):
    output = ""
    if filename[-4:] == ".txt":
        output = filename
    else:
        output = filename + ".txt"
    return output

# Returning dictionary with information about the line from file name
def getLineDictionary(fileName):
    output = {}
    stationList = []
    with open(fileName) as file:
        line = file.readline()
        counter = 1
        while line != "":
            line = line.strip()
            if counter == 1:
                output["lineName"] = capitalize(line)
            else:
                stationList.append(capitalize(line))
            line = file.readline()
            counter += 1
    output["stationList"] = stationList
    return output

# Returning line name(s) from the station input
def returnLineNameFromStation(targetStation):
    if (targetStation in line1Dict["stationList"]) and (targetStation in line2Dict["stationList"]):
        return [line1Dict["lineName"],line2Dict["lineName"]]
    elif targetStation in line1Dict["stationList"]:
        return [line1Dict["lineName"]]
    elif targetStation in line2Dict["stationList"]:
        return [line2Dict["lineName"]]
    else:
        return []

# Returning intersection from two lists
def findIntersection(list1,list2):
    output = []
    for i in list1:
        if i in list2:
            output.append(i)
    output.sort()
    return output
    
# Reading file names and stations
line1Name = getExtension(input())
line2Name = getExtension(input())
origin = capitalize(input())
destination = capitalize(input())
line1Dict = getLineDictionary(line1Name)
line2Dict = getLineDictionary(line2Name)

# originLine is a list that contains the line(s) that the origin is lying on
# destinationLine is a list that contains the line(s) that the origin is lying on
originLine = returnLineNameFromStation(origin)
destinationLine = returnLineNameFromStation(destination)

# overlappingLines is a list that contains the line(s) that contains both the origin and destination
# intersectingStations is a list that contains the intersections of line 1 and line 2
overlappingLines = findIntersection(originLine,destinationLine)
intersectingStations = findIntersection(line1Dict['stationList'],line2Dict['stationList'])

# Printing out the results
if len(originLine) == 0 or len(destinationLine) == 0:
    # Case A
    print("Station not found")
elif len(overlappingLines) == 0:
    if len(intersectingStations) == 0:
        # Case C
        print("No connection found!")    
    else:
        # Case D
        print(f"To get from {origin} to {destination}, first take the {originLine[0]} line")
        print("And you may change at:")
        for i in intersectingStations:
            print(i)
        print(f"to use the {destinationLine[0]} line for your destination")
elif len(overlappingLines) == 1:
    # Case B1 (1 line passing through both the origin and destination)
    print(f"To get from {origin} to {destination} take the {overlappingLines[0]} line")
elif len(overlappingLines) == 2:
    # Case B2 (2 lines passing through both the origin and destination)
    print(f"To get from {origin} to {destination} take the {overlappingLines[0]} line or the {overlappingLines[1]} line")
import sys
import copy

expand = 0
sys.setrecursionlimit(10000)
"""
class Node:
    #elements needed: the actual board itself, the goal state,  
    def __init__(self, state):
        self.state = state
        self.children = []
        self.direction = ""
    def index(self, num)
        index = self.state.find(num)
        x = index // 3
        y = index - i * 3
        return x,y
    def generate_children(self):
        x,y = self.index("0")
        if x > 0:
            temp = copy.deepcopy(self.state)
            temp[x-1][y], temp[x][y] = temp[x][y], temp[x-1][y]
            up = Node(temp)
            up.direction = "up"
            self.children.append(up)
        elif x < 2:
            temp = copy.deepcopy(self.state)
            temp[x+1][y], temp[x][y] = temp[x][y], temp[x+1][y]
            down = Node(temp)
            down.direction = "down"
            self.children.append(down)
        elif y > 0:
            temp = copy.deepcopy(self.state)
            temp[x][y+1], temp[x][y] = temp[x][y], temp[x][y+1]
            left = Node(temp)
            left.direction = "left"
            self.children.append(left)
        elif y < 2:
            temp = copy.deepcopy(self.state)
            temp[x][y-1], temp[x][y] = temp[x][y], temp[x][y-1]
            right = Node(temp)
            right.direction = "right"
            self.children.append(right)
"""
def find_index(puzzle, num):
        index = puzzle.find(num)
        x = index // 3
        y = index - x * 3
        return x,y

def generate_children(puzzle, goal, g):
        global expand
        x,y = find_index(puzzle, "0")
        coor = x * 3 + y
        children = []
        if x > 0:
            temp = copy.deepcopy(puzzle)
            temp = list(temp)
            temp[(x-1)*3+y], temp[coor] = temp[coor], temp[(x-1)*3+y]
            temp = "".join(temp)
            children.append([temp, "up", h_score(temp, goal)])
            expand+=1
        if x < 2:
            temp = copy.deepcopy(puzzle)
            temp = list(temp)
            temp[(x+1)*3+y], temp[coor] = temp[coor], temp[(x+1)*3+y]
            temp = "".join(temp)
            children.append([temp, "down", h_score(temp, goal)])
            expand+=1
        if y < 2:
            temp = copy.deepcopy(puzzle)
            temp = list(temp)
            temp[coor+1], temp[coor] = temp[coor], temp[coor+1]
            temp = "".join(temp)
            children.append([temp, "right", h_score(temp, goal)])
            expand+=1
        if y > 0:
            temp = copy.deepcopy(puzzle)
            temp = list(temp)
            temp[coor-1], temp[coor] = temp[coor], temp[coor-1]
            temp = "".join(temp)
            children.append([temp, "left", h_score(temp, goal)])
            expand+=1
        return children

def solve(puzzle,goal):
  """ Main progress """

  path = []
  result = []
  check = {puzzle:1}
  gen = 0
  dept = 0
  node = 1

  path.append([[puzzle,"START",h_score(puzzle,goal)]])
  #print(path)
    
  while path:

    # show generation
    #print("Current Path: ", path)
    if gen % 1000 == 0:
        print(gen)
    gen += 1

    # choose route and declare puzzle to work on
    current_route = path.pop(0)
    #print("Current Route:",current_route)
    current_puzzle = current_route[-1][0]
    #print("Current Puzzle:",current_puzzle)
    # check if win
    if current_puzzle == goal:
      route = current_route
      print("Number of expanded nodes: ", node)
      return route
    # declare g score
    g = len(current_route)

    # if the current_puzzle already visited once with different step then abandon this route
    # it will remove the route with that visite the same puzzle but take more move
    if check[current_puzzle] != g:
      print("skipped")
      continue 
    print("test")
    # generate possible move of blank space or "0" in this case
    next_state = generate_children(current_puzzle, goal, 0)

    # consider if the next state should be add to the route or not
    for state in next_state:

      # declare puzzle and g score of the state
      state_puzzle = state[0]
      state_g = g + 1

      # check if this puzzle have been visited before
      if state_puzzle in check:

        # if visited before but g score is less than the recent then
        # change the visted puzzle to the lesser one
        if state_g < check[state_puzzle]:
          check[state_puzzle] = state_g
          to_add_state = copy.deepcopy(current_route)
          state.append(h_score(state_puzzle,goal))
          to_add_state.append(state)
          node += 1
          path.append(to_add_state)

        # if visited before but g score is higher then do nothing

      # if never visited before then add the data to dictionary "check" and add to path
      else:
        check[state_puzzle] = state_g
        to_add_state = copy.deepcopy(current_route)
        state.append(h_score(state_puzzle,goal))
        to_add_state.append(state)
        path.append(to_add_state)
        node += 1

    # sort route according to the step (lengt of the route list) and h score respectively
    path = sorted(path, key= lambda x: (len(x), x[-1][-1]))
def h_score(puzzle, goal):
    h = 0
    final_h = 0
    for num in range(len(puzzle)):
        i,j = find_index(puzzle, str(num))
        x,y = find_index(goal, str(num))
        h = abs(i-x) + abs(j-y)
        final_h += h
    return final_h
start = "724506831"
goal = "012345678"
# start = Node(start)
path = []
expand = 0
print(solve(start, goal))
print("Number of nodes expanded: ", expand)





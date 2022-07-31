i = str(input("Table file:\n"))
fout= open(i,'r')
number_of_tables, date = 0, 0
inte=[]
seatno=[]
seats=[]
detail = []
listt=dict()
for i in fout:
    number_of_tables+=1
    i=i.replace('\n','')
    i=i.split(' ')
    for j in i:
        inte.append(j)
print('Imported',number_of_tables,'table(s).')

def get_table(inte):
    for j in range(1,len(inte)+1):
        if j%2!=0:
            seatno.append(inte[j-1])
        else:
            seats.append(inte[j-1])
    for i in range(number_of_tables):
        x=seatno[i]
        listt[x]=0
    return seatno, seats,listt

seatno, seats,listt = get_table(inte)

def commands(com,count):
    if com =='Exit':
        try:
            create = open("reserve.txt","w")
            create.close()
            create = open("bookinglist.txt","w")
            create.close()
            create = open("tableallocation.txt","w")
            create.close()
        except:
            pass
        print('Bye')
        return
    else:
        com=com.split('|')
        if com[0]=='Book':
            count+=1
            n = book(com,count)
            print(f'Added booking. The ticket code for {com[3]} is {n}.')
            com=str(input())
            x = commands(com,count)
        if com[0] == 'AllocateTable':
            n = allocatetable(com,count)
            com = str(input())
            x = commands(com,count)
        if com[0] == 'ListBookings':
            listbooking()
            create = open("bookinglist.txt","r")
            for i in create:
                print(i) #r is not defined
            com = str(input())
            x = commands(com,count)
        if com[0]=='ListTableAllocation':
            n = open("tableallocation.txt",'r')
            for i in n:
                print(i)
            com = str(input())
            x = commands(com,count)

def book(com,count):
    print("BEGINNING")
    s=count-1
    date=com[3]
    if count==1: #the below section has bugs
        f[date]=1
        print(f)
        return 1
    try:
        f[date]+=1
    except:
        f[date]=1
    print(f)
    x=booking(com,f[date],count) #What is the usage of this?
    return f[date]

def booking(com,y,count):
    print(count)
    s=count-1
    for i in range(1,5):
        x=com[i]
        print("Access") #this line is not operated
        print(detail, x, end="") #not operated as well
        print(detail[s]) #there is nothing inside the list detail
        detail[s].append(x) 
    print(detail[s])
    detail[s].append(y)
    print(detail)
    #save date,ticketno,ppl
    try:
        create= open("reserve.txt","a")
        create.write(f'{detail[s][1]},{y},{detail[s][3]},')
        create.close()
    except:
        create= open("reserve.txt","x")
        create= open("reserve.txt","a")
        create.write(f'{detail[s][1]},{y},{detail[s][3]},')
        create.close()
    return #you returned nothing, then what is the purpose of x

def listbooking():
    s=count-1
    if detail==[]:
        print("No booking.")
        try:
            create = open("bookinglist.txt","a")
            create.write(f'Booking(s):\n')
            create.close()
        except:
            create = open("bookinglist.txt","x")
            create = open("bookinglist.txt","w")
            create.write(f'Booking(s):\n')
            create.close()
        return

    else:
        create= open("bookinglist.txt","a")
        create.write(f'{detail[s][0]}, {detail[s][1]}, {detail[s][2]} (Ticket {detail[s][4]}), {detail[s][3]},')
        if detail[s][5] is none:
            create.write('Pending.')
        else:
            create.write(f'Assigned table(s): ')
            for i in range(5,len(detail[s]-1)):
                create.write(f'{detail[s][i], }')
            create.write(f'detail[s][-1].')
        create.close()
    return

def allocatetable(com):
    retr= open("reserve.txt",'r')
    for i in retr:
        i=i.split(',')
        for j in range(len(i)-1):
            table.append(i[j])
    #saved data : date,ticketno,ppl
    for i in len(1,table):
        ss=table[i-1]
        a=table[i]
        if ss ==com[1]:
            if a==com[2]:
              ppl=table[i+1]
              ppl=int(ppl)
              break
    sit=com[3]
    sit=sit.split(' ')
    sit=sorted(sit)
    summ=0
    for i in sit:
        c=seatno.find(i)
        su=seats[c]
        su=int(su)
        summ=+su
    if summ>=ppl:
        n=ListTable(com,sit)
        if n==True:
            print(f'Allocated table(s). {com[1]} (Ticket {com[2]}):',end='\b')
            for i in range(len(sit)-1):
                detail[s].append(sit[i])
                print(sit[i],end=', ')
            print(sit[-1],end='.')
        else:
            print('Error: One or more tables allocated to another booking.')
    else:
        print('Error: Not enough seats for this booking.')

    return


def ListTable(com,sit):
    date=com[1]
    for i in sit:
        if listt[i]==0:
            listt[i]= (f'Ticket {com[2]}')
            n=allocation(date,com[2])
        else:
            return False
    return True

#if com[2] is needed
def allocation(date):
    for i in range(s):
        if listt[i]==0:
            listt[i]= 'Available'
    try:
        allo= open("tableallocation.txt","a")
        allo.write(f'Table(s) on {date}:\n')
        for i in range(s):
            xx= seatno[i]
            yy=listt[i]
            allo.write(f'{xx}: {yy}\n')
        allo.close()
    except:
        allo= open("tableallocation.txt","x")
        allo= open("tableallocation.txt","w")
        allo.write(f'Table(s) on {date}:\n')
        for i in range(s):
            xx= seatno[i]
            yy=listt[i]
            allo.write(f'{xx}: {yy}\n')
        allo.close()

z=0
count=0
f=dict()
detail=[]
table=[]
com=str(input())
x=commands(com,count)

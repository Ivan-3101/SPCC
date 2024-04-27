import re

def my_check(val):
  operators = ['>', '<', '<=', '>=', '+', '-', '', '/', '%', '', '//', '=', '+=', '-=', '==', '=', '/=', '%=', '//=', '!=', '&=', '|=', '^=', '>>=', '<<=']
  dig = "unknown"
  if((bool(re.match('^[a-zA-Z0-9]*$',val))==False) and ((val in operators) == False) ):
    dig = "special"
  elif((val in operators) == True):
    dig = "operator"
  else:
    dig = "identifier"
  return dig

mult = []
while True:
  print("\nMENU")
  print("\n1.Create table")
  print("\n2.Search Table")
  print("\n3.Enter Symbol")
  print("\n4.Remove Symbol")
  print("\n5.View table")
  print("\n6.Exit")
  ch = int(input("\nEnter your choice: "))

  if ch == 1:
    arr = []
    exp = input("\nEnter the expression: ")
    for element in exp:
      arr.append(element)
    print(*arr, sep = "\n")
    for i in arr:
      ib = 0
      for b in range(len(mult)):
        if (i == mult[b][0]):
          ib = 1
      if ib != 1:
        mult.append([i,id(i),my_check(i)])
      ib = 0
    print("Completed")

  elif ch == 2:
    b = 0
    a = input("\nEnter search element: ")
    for i in range(len(mult)):
      if (a == mult[i][0]):
        b = 1
        break
      else:
        b = 0
    if(b==1):
      print("symbol: ",a,"index: ",i)
    else:
      print("Not Found")

  elif ch == 3:
    nam = input("\nEnter Symbol: ")
    mult.append([nam,id(nam),my_check(nam)])

  elif ch == 4:
    nan = input("\nEnter Symbol: ")
    for bi in range(len(mult)):
        if (nan == mult[bi][0]):
          break
    arr1 = mult[bi]
    print(arr1)
    mult.remove(mult[bi])

  elif ch == 5:
    print(*mult, sep = "\n")
    print("\n")
    print("\nTable:")
    for i in range(len(mult)):
      print("Symbol: ",mult[i][0]," Address: ",mult[i][1]," Type: ",mult[i][2])
      print("\n") 

  elif ch == 6:
    print("exited")
    break
  else:
    print("Invalid")
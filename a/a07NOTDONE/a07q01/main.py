# Name: Carl
# File: main.py

def NFA(alphabet, states, start, accepts, transitions, userString):
  currentState = start
  for char in userString:
    if char not in alphabet and char != " ":
      return False
    for tran in transitions:
      if currentState == tran[0]:
        if char == tran[1]:
          # print(char ,"tran from", currentState, "to", tran[2])
          currentState = tran[2]
          break
  if currentState in accepts:
    # print(currentState, end=" ")
    return True
  else:
    return False
  
text = input("please give me a string containing 1's and 0's: ")

N = NFA(alphabet=["0", "1"],
 states=["q0", "q1", "q2", "q3"],
 start="q0",
 accepts=["q0", "q2", "q3"],
 transitions=[("q0", "0", "q1"),
              ("q0", "1", "q2"),
              ("q1", "0", "q0"),
              ("q1", "1", "q3"),
              ("q2", "0", "q3"),
              ("q2", "1", "q0"),
              ("q3", "0", "q2"),
              ("q3", "1", "q1")],
  userString=text
  )

if N:
  print(text, "is an exept state")
else:
  print(text, "is not an accept state")
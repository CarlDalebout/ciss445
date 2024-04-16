# Name: Carl
# File: main.py

def DFA(alphabet, states, start, accepts, transitions, userString):
  currentState = transitions[0][0]
  count = 1
  for tran in transitions:
    if tran[0] != currentState:
      if count < len(alphabet)-1:
        print(tran, count, currentState, "this is not a valid DFA")
        return False
      else:
        currentState = tran
        count = 1
    elif tran[0] == currentState:
      count += 1

  currentState = start
  for char in userString:
    if char not in alphabet:
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

N = DFA(alphabet=["0", "1"],
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
let rec sum = fun n -> 
  if n < 0 then 0
  else n + sum (n - 1)
  ;;

print_string "Tests\t\tExpected value\n";;

print_string "sum 0\t\t"
let x = sum 0;;
print_int x;;
print_char '\n';;

print_string "sum (-1)\t"
let x = sum (-1);;
print_int x;;
print_char '\n';;

print_string "sum 1\t\t"
let x = sum 1;;
print_int x;;
print_char '\n';;

print_string "sum 2\t\t"
let x = sum 2;;
print_int x;;
print_char '\n';;

print_string "sum 3\t\t"
let x = sum 3;;
print_int x;; 
print_char '\n';;

print_string "sum 4\t\t"
let x = sum 4;;
print_int x;;
print_char '\n';;
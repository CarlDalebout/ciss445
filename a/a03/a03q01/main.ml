
let rec power = fun x -> function
  | 0 -> 1
  | n -> x * power x (n - 1)
;;



print_string "Tests\t\tExpected Value\n";;

print_string "power 2 0\t";;
print_int (power  (2) 0);;
print_char '\n';;

print_string "power 0 5\t";;
print_int (power  (0) 5);;
print_char '\n';;

print_string "power 0 1\t";;
print_int (power  (0) 1);;
print_char '\n';;

print_string "power 2 2\t";;
print_int (power  (2) 2);;
print_char '\n';;

print_string "power (-3) 3\t";;
print_int (power (-3) 3);;
print_char '\n';;
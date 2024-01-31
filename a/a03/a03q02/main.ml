let rec power2 = fun x -> fun n ->
  if n = 0 then 
    1
  else if n mod 2 = 0 then 
    let y = power2 x (n/2) in 
    y * y
  else 
    let y = power2 x ((n-1)/2) in
    x * y * y
;;

print_string "Tests\t\tExpected Value\n";;

print_string "power2 2 0\t";;
print_int (power2  (2) 0);;
print_char '\n';;

print_string "power2 0 5\t";;
print_int (power2  (0) 5);;
print_char '\n';;

print_string "power2 0 1\t";;
print_int (power2  (0) 1);;
print_char '\n';;

print_string "power2 2 2\t";;
print_int (power2  (2) 2);;
print_char '\n';;

print_string "power2 (-3) 3\t";;
print_int (power2 (-3) 3);;
print_char '\n';;
exception Invalid_value of string

let head = fun list -> match list with
    [] -> raise (Invalid_value "[]")
  | x::xs -> x
;;

print_string "Tests\t\tExpected value\n";;

(* 
print_string "head []\t";;
print_int   (head []);;
print_char '\n'; 
*)

print_string "head [1]\t";;
print_int   (head [1]);;
print_char '\n';

print_string "head [2; 1]\t";;
print_int   (head [2; 1]);;
print_char '\n';

print_string "head [3; 2; 1]\t";;
print_int   (head [3; 2; 1]);;
print_char '\n';

print_string "head [1.1, 2.2]\t";;
print_float (head [1.1; 2.2]);;
print_char '\n';
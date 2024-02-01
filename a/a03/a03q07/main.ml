let second list = match list with
| [] -> failwith "[]"
| [x] -> failwith "list not large enough"
| h::t -> match t with
    | [] -> failwith "[[]]"
    | h::t -> h
;;
(* val length : 'a list -> int = <fun> *)

print_string "Tests\t\t\tExpected value\n";;

(* print_string "second []\t";;e
print_int   (second []);;
print_char '\n';  *)

print_string "second [1; 2]\t\t";;
print_int   (second [1; 2]);;
print_char '\n';

print_string "second [3; 1; 2]\t";;
print_int   (second [3; 1; 2]);;
print_char '\n';

print_string "second [4; 3; 2; 1]\t";;
print_int   (second [4; 3; 2; 1]);;
print_char '\n';

print_string "second [3.3; 4.4; 5.5]\t";;
print_float (second [3.3; 4.4; 5.5]);;
print_char '\n';
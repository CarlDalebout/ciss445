exception Invalid_value of string

let head = fun list -> match list with
    [] -> raise (Invalid_value "[]")
  | x::xs -> x
;;

let rec tail list = match list with
  |  [] -> failwith "[]"
  | [x] -> x
  | h::t -> tail t 
;;
(* val length : 'a list -> int = <fun> *)

print_string "Tests\t\tExpected value\n";;

(* print_string "tail []\t";;
print_int   (tail []);;
print_char '\n';  *)

print_string "tail [1]\t";;
print_int   (tail [1]);;
print_char '\n';

print_string "tail [2; 1]\t";;
print_int   (tail [2; 1]);;
print_char '\n';

print_string "tail [3; 2; 1]\t";;
print_int   (tail [3; 2; 1]);;
print_char '\n';

print_string "tail [1.1, 2.2]\t";;
print_float (tail [1.1; 2.2]);;
print_char '\n';
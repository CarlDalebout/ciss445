let rec duplicate = fun x -> fun n ->
  match n with 
  | 0 -> []
  | n -> x::(duplicate x (n-1))
;;

let print_element_int = fun x -> 
  let _ = print_int x in
  print_string "; "
;;

let print_element_float = fun x -> 
  let _ = print_float x in 
  print_string "; "
;;

let print_list_int = fun x -> 
  let _ = print_char '[' in
  let _ = List.iter print_element_int x in
  print_char ']'
;;

let print_list_float = fun x -> 
  let _ = print_char '[' in
  let _ = List.iter print_element_float x in
  print_char ']' 
;;

print_string "Tests\t\t\tExpected value\n";;

print_string "duplicate 1 3\t\t";;
print_char '[';;
List.iter print_element_int (duplicate 1 3);;
print_char ']';;

print_string "\nduplicate 1.23 0\t";;
print_char '[';;
List.iter print_element_float (duplicate 1.23 0);;
print_char ']';;

print_string "\nduplicate 3.1 4\t\t";;
print_char '[';;
List.iter print_element_float (duplicate 3.1 4);;
print_char ']';;

print_string "\nduplicate [1; 2; 3] 3\t";;
List.iter print_list_int (duplicate [1; 2; 3] 2);;
print_char '\n';;
let rec range = fun a -> fun b ->
  if a >= b then 
    []
  else 
    a::(range (a+1) b)
;;

let print_element_int = fun x -> 
  let _ = print_int x in
  print_string "; "
;;

print_string "Tests\t\t\tExpected value\n";;

print_string "range 1 3\t\t";;
print_char '[';;
List.iter print_element_int (range 1 3);;
print_char ']';;

print_string "\nrange 1 1\t\t";;
print_char '[';;
List.iter print_element_int (range 1 1);;
print_char ']';;

print_string "\nrange (-3) 2\t\t";;
print_char '[';;
List.iter print_element_int (range (-3) 2);;
print_char ']';;

print_string "\nrange 6 3\t\t";;
print_char '[';;
List.iter print_element_int (range 6 3);;
print_endline "]";;
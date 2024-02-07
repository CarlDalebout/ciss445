let rec range2 = fun a -> fun b -> fun c ->
  if c >= 0 then

    if a >= b then 
      []
    else 
      a::(range2 (a+c) b c)
  else
    if a <= b then 
      []
    else 
      a::(range2 (a+c) b c)
    ;;

let print_element_int = fun x -> 
  let _ = print_int x in
  print_string "; "
;;

print_string "Tests\t\t\tExpected value\n";;

print_string "range2 1 3 1\t\t";;
print_char '[';;
List.iter print_element_int (range2 1 3 1);;
print_char ']';;

print_string "\nrange2 1 7 2\t\t";;
print_char '[';;
List.iter print_element_int (range2 1 7 2);;
print_char ']';;

print_string "\nrange2 1 6 2\t\t";;
print_char '[';;
List.iter print_element_int (range2 1 6 2);;
print_char ']';;

print_string "\nrange2 1 1 2\t\t";;
print_char '[';;
List.iter print_element_int (range2 1 1 2);;
print_char ']';;

print_string "\nrange2 3 (-2) (-1)\t";;
print_char '[';;
List.iter print_element_int (range2 3 (-2) (-1));;
print_char ']';;

print_string "\nrange2 3 (-2) (-2)\t";;
print_char '[';;
List.iter print_element_int (range2 3 (-2) (-2));;
print_endline "]";;
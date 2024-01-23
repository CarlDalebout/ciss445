(*
    Name: Carl Dalebout
    File: main.ml   
*)

let max x y z = if x > y && x > z then x else if y > z then y else z ;;

print_int (max 1 2 3);;
print_char '\n';;
print_int (max 1 3 2);;
print_char '\n';;
print_int (max 2 1 3);;
print_char '\n';;
print_int (max 2 3 1);;
print_char '\n';;
print_int (max 3 1 2);;
print_char '\n';;
print_int (max (-3) (-2) (-1));;
print_char '\n';;

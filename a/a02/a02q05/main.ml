(*
  Name: Carl Dalebout
  File: main.ml
*)

let f = fun x -> x +. 1.0;;
let g = fun x -> x -. 1.0;;
let h = fun x -> x *. x;;

let div_func = fun f -> fun g -> fun x -> f x /. g x;;

print_float ((div_func f g) 0.0);;
print_char  '\n';;                  
print_float ((div_func g f) 2.0);;
print_char  '\n';;                  
print_float ((div_func g f) 3.0);;
print_char  '\n';;                  
print_float ((div_func f h) 1.0);;
print_char  '\n';;                      
print_float ((div_func h f) 2.0);;
print_char  '\n';;                     
(*
  name: Carl Dalebout
  file: main.ml   
*)

let d = fun f -> fun x -> fun h -> (f (x +. h) -. f x) /. h;;

print_float (d (fun x -> x +. 3.0) 2.0 5.0);;
print_char '\n';
print_float (d (fun x -> x +. x) 0.001 1.0);;
print_char '\n';
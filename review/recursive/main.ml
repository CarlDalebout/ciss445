let rec factorial = fun n ->
    if n = 0 then
      1
    else 
      n * factorial (n - 1)
;;

let rec fib = fun n ->
  if n = 0 then 
    1
  else if n = 1 then 
    1
  else if n > 1 then
    fib (n - 1) + fib (n - 2)
  else 
    0
;; 

let rec betterfib = function   
  | 0 -> 1
  | 1 -> 1
  | n -> (betterfib (n - 1) + betterfib (n - 1))
;;

(* 
print_int (factorial 5);;
print_char '\n';

print_int (fib 5);;
print_char '\n';

print_int (betterfib 5);;
print_char '\n'; 
*)

let rec get_42 = fun () -> 
  let _ = print_string
          "Give me 42 please ... " in
  let x = read_int () in
  if x = 42 then 
    print_string "Thanks!!!\n"
  else
    get_42 ()
;;


let rec guess_42 = fun () -> 
  let _ = print_string
          "Try to guess a number ... " in
  let x = read_int () in
  if x = 42 then
    print_string "You got it !!!\n"
  else if x > 42 then
    let _ = print_string
            "Your number is to high ...\n" in
    guess_42 ()
  else 
    let _ = print_string
            "Your number is to low ...\n" in
    guess_42 ()
;;

guess_42 ();;
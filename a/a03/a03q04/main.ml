(* let rec isPrime = fun n -> fun i ->
  if n < 2 then 
    false
  else if n = 2 then
    true
  else if n mod i = 0 then 
    false
  else if (i * i) > n then
    true
  else 
    isPrime n (i+1)
;; *)

let isPrime = fun n ->
  (* Returns true if n has no divisors between m and sqrt(n) inclusive. *)
  let rec noDivisors m =
    m * m > n || (n mod m != 0 && noDivisors (m + 1))
  in
  n >= 2 && noDivisors 2
;;

print_string "Tests\t\tExpected value\n";;

print_string "isPrime 0\t";;
if isPrime 0 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 1\t";;
if isPrime 1 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 2\t";;
if isPrime 2 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 3\t";;
if isPrime 3 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 4\t";;
if isPrime 4 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 5\t";;
if isPrime 5 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 6\t";;
if isPrime 6 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 7\t";;
if isPrime 7 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 8\t";;
if isPrime 8 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 9\t";;
if isPrime 9 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 10\t";;
if isPrime 10 then 
  print_string "true\n"
else 
  print_string "false\n"
;;

print_string "isPrime 11\t";;
if isPrime 11 then 
  print_string "true\n"
else 
  print_string "false\n"
;;
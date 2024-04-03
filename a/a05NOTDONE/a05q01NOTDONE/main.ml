let rec subseteq = fun list1 -> fun list2 ->
  match list1 with
  | [] -> if list2 = [] then 
      true
    else
      false
  | x::xs -> 
;;
let rec subseteq = fun list1 -> fun list2 -> 
  match list1 with 
  | [] -> true
  | x::xs -> 
    let rec elementof = fun target -> fun list -> 
      match list with
      | [] -> false
      | x::xs ->
          if x = target then
            true
          else
            (elementof target xs)
    in
    if (elementof x list2) then 
      (subseteq xs list2)
    else
      false
;;

(* List.iter f [42; 42; 42];; *)
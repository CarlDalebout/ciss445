let rec seteq = fun list1 -> fun list2 ->
  match list1 with
  | [] -> if list2 = [] then 
      true
    else
      false
  | x::xs -> 
    let rec checklist2 = fun target -> fun list2 ->
      match list2 with
      | [] -> false
      | y::ys -> if y = target then 
            true
          else
            checklist2 target ys 
    in
    
    if checklist2 x list2 then 
      seteq xs list2
    else
      false
;;
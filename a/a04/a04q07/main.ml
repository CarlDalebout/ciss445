let rec elementof = fun target -> fun list -> 
  match list with
  | [] -> false
  | x::xs ->
      if x = target then
        true
      else
        (elementof target xs)
;;
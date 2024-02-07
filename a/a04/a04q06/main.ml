let rec at = fun list -> fun n ->
  match list with 
  | [] -> 99999
  | x::xs -> 
      if n > 0 then
        (at xs (n-1))
      else
        x
;;
let index = fun list -> fun x ->
  let rec find = fun list -> fun target -> fun i ->
    match list with 
    | [] -> -1
    | x::xs -> 
      if x = target then
        i
      else 
        (find xs target (i+1))
  in
  find list x 0
;;
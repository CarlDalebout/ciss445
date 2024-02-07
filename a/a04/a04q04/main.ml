let rec slice = fun list -> fun a -> fun b -> fun c -> 
  let rec to_index = fun list -> fun a -> 
    match  list with
    | [] -> []
    | x::xs -> 
      if a = 0 then 
       list
      else
        (to_index xs (a-1))
      in
      let rec slice_iter = fun list -> fun index -> fun xc ->
      match list with 
      | [] -> []
      | x::xs -> 
        if index > 0 then
          if xc  = 1 then
            x::(slice_iter xs (index-1) xc)
          else
            let sub_list = to_index xs (xc-1)
            in
            x::(slice_iter sub_list (index-xc) xc)
        else
          []
      in
      slice_iter (to_index list a) (b - a) c
;;
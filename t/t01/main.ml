module type Stack = 
  sig
    type 'a stack
    val empty : 'a stack
    val make : unit -> 'a stack
    val is_empty : 'a stack -> bool
    val push : 'a stack -> 'a -> 'a stack
    val peek : 'a stack -> 'a
    val pop : 'a stack -> 'a stack
  end
;;

module ListStack: Stack = 
  struct
    type 'a stack = 'a list
    let empty = []
    let make () = empty
    let is_empty s = (s = [])
    let push s x = x::s
    let peek = fun s -> match s with
      | [] -> raise (Failure "ListStack.peek error")
      | x::_ -> x
      let pop = fun s -> match s with
      | [] -> raise (Failure "ListStack.pop error")
      | _::xs -> xs
  end
;;

let printBoard = 
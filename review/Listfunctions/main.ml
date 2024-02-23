type int_list = Empty
              | Cons of (int * int_list)
;;

let rec inserttail xs v =
  match xs with
  | Empty -> Cons (v, Empty)
  | Cons (y, ys) -> Cons (y, inserttail ys v)
;;

type int_btree = 
                  Empty_btree
                | Node of (int * int_btree * int_btree);;

type 'a tree = 
  | Leaf
  | Node of 'a node

  and 'a node = 
    {
      value: 'a;
      left: 'a tree;
      right: 'a tree
    }
;;

(* let rec find n target =
   match n with
  | Empty_btree -> Empty_btree
  | Node (target, left, right) -> n
  | Node (_, left, right) ->
      let a = find left target in
        match a with
        | Empty_btree -> find right target
        | _ -> a
;; *)

let rec same_int_btree n0 n1 = 
  match (n0, n1) with
  | (Empty_btree, Empty_btree) -> true
  | (Node (key0, left0, right0), Node (key1, left1, right1)) -> 
      (key0 = key1) and 
      (same_int_btree left0 left1) and
      (same_int_btree right0 right1)
  | _ -> false
;;

let n2 = Node (2, Empty_btree, Empty_btree);;
let n3 = Node (3, Empty_btree, Empty_btree);;
let n4 = Node (4, Empty_btree, Empty_btree);;
let n1 = Node (1, n3, n4);;
let n0 = Node (0, n2, n1);;

(*
        0
       / \
      2   1
         / \
        3   4
         *)

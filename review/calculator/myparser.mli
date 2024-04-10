type token =
  | INT of (int)
  | PLUS
  | MINUS
  | MULT
  | DIV
  | LPAREN
  | RPAREN
  | EOL

val myparser :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> int

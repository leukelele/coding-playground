#lang racket

(define pie 3)              ; defines 'pie' to be 3

(define (piece str)         ; defines 'piece' to accept a parameter 'str'
  (substring str 0 pie))    ; the definition, but I don't know what it does

pie

(piece "key lime")
(piece "key")
(piece "key lime pie")
(piece "keylimepie")

; funzione inversa di CAR
; > (ULT '(A B C))
;   C

(defun ult (l)
  (cond
    ( (null l) nil )
    ( (null (cdr l)) (car l))
    ( t (ult (cdr l)) )
  )
)


; funzione inversa di CDR
; > (TUL '(A B C))
;   (A B)

(defun tul (l)
  (cond
    ( (null l) nil )
    ( (null (cdr l)) nil )
    ( t (cons (car l) (tul (cdr l))) )
  )
)

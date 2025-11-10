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

; inverte una lista solo al livello più esterno

(defun inverte (l)
  (cond
    ( (null (ult l)) nil )
    ( t (cons (ult l) (inverte (tul l))) )
  )
)

; inverte una lista e le sue sottoliste

(defun invertes (l)
  (cond
    ( (null (ult l)) nil )
    ( (atom (ult l)) (cons (ult l) (invertes (tul l)))  )
    ( t (cons (invertes (ult l)) (invertes (tul l))) )
  )
)

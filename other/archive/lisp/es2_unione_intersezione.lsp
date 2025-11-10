; esercizio 2


; definizione dei dati
(setq a 0)
(setq b 1)
(setq c 2)
(setq d 3)
(setq e 4)
(setq f 5)
(setq g 6)
(setq h 7)
(setq i 8)
(setq l 9)

(setq la '(a b c d e))
(setq lb '(f g h i l))


; make-set prende una lista in input e valuta in output la stessa lista senza
;          duplicati.
; *funzione non distruttiva*
(defun make-set (l)
  (cond
    ( (null l) nil )
    ( (member (car l) (cdr l)) (make-set (cdr l)) )
    ( t (cons (car l) (make-set (cdr l))) )
  )
)

; un restiuisce in output l'unione di l1 e l2 senza duplicati
; *funzione non distruttiva*
(defun un (l1 l2)
  (make-set (append l1 l2))
)

; inters restiuisce in output l'intersezione delle liste l1 l2
; *funzione non distruttiva*
(defun inters (l1 l2)
  (cond
    ( (null l1) nil )
    ( (member (car l1) l2) (cons (car l1) (inters (cdr l1) l2)) )
    ( t (inters (cdr l1) l2))
  )
)

; data una lista di liste ed elementi... appiattisce il tutto in un'unica lista

(defun spiana (l)
 (cond
  ( (null l) nil )
  ( (atom (car l)) (cons (car l) (spiana (cdr l))) )
  ( t (append (spiana (car l)) (spiana (cdr l))) )
 )
)

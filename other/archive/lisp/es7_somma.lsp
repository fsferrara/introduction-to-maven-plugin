; data una lista di liste ed elementi... appiattisce il tutto in un'unica lista

(defun somma (&rest l)
  (rsomma l)
)

(defun rsomma (l)
 (cond
  ( (null l) 0 )
  ( t (+ (car l) (rsomma (cdr l))) )
 )
)

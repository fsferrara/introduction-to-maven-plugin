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

(setq cpa (cons 'a 'b))
(setq cpc (cons 'c 'd))
(setq cpe (cons 'e 'f))
(setq cpg (cons 'g 'h))
(setq cpi (cons 'i 'l))

(setq lcp '(cpa cpc cpe cpg cpi))



; (ASSOCIA S L) con L lista di coppie puntate. ASSOCIA restituisce il CDR della
; prima coppia puntata nella lista L il cui CAR `e S. (`E un surrogato delle
; property lists).
(defun associa (s l)
  (cond
    ( (null l) nil )
    ( (equal (car (eval (car l))) s) (cdr (eval (car l))) )
    ( t (associa s (cdr l)) )
  )
)

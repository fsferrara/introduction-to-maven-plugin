; Definisco una semplice funzione che incrementa una variabie numerica
(defun my-add-one (x)
  (setq localvariable (+ x 1))
  (format t "~%~%~% Incrementando di 1 abbiamo ~A ~%~%~%" localvariable)
)

; Il comando defvar setta le variabili con scope globale.
; Attenzione a non ridefinire il nome di variabili globali
; all'interno di funzioni
(defvar *x* 0)

; Modifica il contenuto della variabile x in 83
(setq *x* 83)


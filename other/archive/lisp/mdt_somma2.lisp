; Caro giovanni mettiamo i commenti!!!
; l'input alla macchina sara' costituito da una lista con due sottoliste e lo stato in mezzo.
;	es. (() 1 (I I I B I I I))
;	oppure ((I I I B)3(I I I I))
	
;          SCRITTURA:
;		(setf (caaddr ID) s)    ; qui s rappresenta il carattere da scrivere

;          DESTRA:
;		(setf (car id )  (cons (caaddr id) (car id)))
;		(setf (caddr id) (cdaddr id))
;		(cond ( (null (caddr id)) (setf (caddr id)  (list 'B))) )  

;          SINISTRA:
;		(eq action 'L)
;		(setf (caddr id) (cons (caar id) (caddr id)))
;		(setf (car id) (cdar id))
;		(cond ( (null (car id)) (setf (car id)  (list 'B))) )


(defun mdtSum (ID)
     (print id)
     (cond 
	 
      ( (and (= (cadr id) 1) (eq (caaddr id) 'I)) ; STATO 1 - testina su I
						(setf (caaddr id) 'B) ; scrivo B
       						(mdtSum id) ; chiamata ricorsiva
		)						
      ( (and (= (cadr id) 1) (eq (caaddr id) 'B)) ; STATO 1 - testina su B
       						
						(setf (cadr id) 2) ; passo allo stato 2
              					
       						; mi sposto in avanti col nastro
						(setf (car id )  (cons (caaddr id) (car id))) ; aggiorno sx
						(setf (caddr id) (cdaddr id)) ; aggiorno dx
       						
       						; se il nastro e' finito aggiungo un B
						(cond ( (null (caddr id)) (setf (caddr id)  (list 'B))) )
       						
						(mdtSum id) ; chiamata ricorsiva
		)
      ( (and (= (cadr id) 2) (eq (caaddr id) 'I)) ; STATO 2 - testina su I
              					
       						;mi sposto in avanti col nastro
						(setf (car id )  (cons (caaddr id) (car id))) ; aggiorno sx
						(setf (caddr id) (cdaddr id)) ; aggiorno dx
       						
       						; se il nastro e' finito aggiungo un B
						(cond ( (null (caddr id)) (setf (caddr id)  (list 'B))) )
       						
						(mdtSum id) ; chiamata ricorsiva
		)
      ( (and (= (cadr id) 2) (eq (caaddr id) 'B)) ; STATO 2 - testina su B
       						
						(setf (cadr id) 3) ; passo allo stato 3
              					
              					
						(setf (car id )  (cons (caaddr id) (car id)))
						(setf (caddr id) (cdaddr id))
						(cond ( (null (caddr id)) (setf (caddr id)  (list 'B))) )
       						
						(mdtSum id) ; chiamata ricorsiva
		)
      ( (and (= (cadr id) 3) (eq (caaddr id) 'I)) ; STATO 3 - testina su I
						(setf (caaddr id) 'B) ; scrivo B
       						(mdtSum id) ; chiamata ricorsiva
		)
       
      (T id)
      )
)
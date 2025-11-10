l'input alla macchina sarà costituito da una lista con due sottoliste e lo stato in mezzo.
	es. (() 1 (I I I B I I I))
	oppure ((I I I B)3(I I I I))
	
          SCRITTURA: (setf (caaddr ID) s)    ; qui s rappresenta il carattere da scrivere
          DESTRA:    (setf (car id )  (cons (caaddr id) (car id))) (setf (caddr id) (cdaddr id))  (cond ( (null (caddr id)) (setf (caddr id)  (list 'B))) )  
          SINISTRA:  (eq action 'L) setf (caddr id) (cons (caar id) (caddr id)) (setf (car id) (cdar id))  (cond ( (null (car id)) (setf (car id)  (list 'B))) )

(defun area-circle(rad)
    "Calculates area pf a circle with given radius"
    (terpri)
    (format t "Radius: ~4f" rad)
    (format t "~%Area: ~10f" (* 3.141592 rad rad))
)
(area-circle 10)

(loop for x in '(a b c d e)
    for y in '(1 2 3 4 5)
    collect (list x y))

(cond ((> a 20)
      (format t "iosdf") (+ 0 8))
      (t (format t "slidjflsd" a)))

(when (> a 20)
    (format t "sdfksjdf") (+ 0 9))
(format t " jksdhf" a)

(loop 
    (setq a (+ a 1))    
    (terpri)
)

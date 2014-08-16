reset
set terminal epslatex color

set xlabel 'Zeit $t$'
set ylabel 'Dichte $u$'
set key under box

set output 'b0.7u1v1.tex'
set title 'Parameter: $a=0.1 .. 0.9, b=0.7, u_0=v_0=1$ bei einer Schrittweite von $\Delta t=0.001$'
p 'a0.1b0.7u1v1.dat' u 1:4 title 'a=0.1' w l lw 2 ,'a0.2b0.7u1v1.dat' u 1:4 title 'a=0.2' w l lw 2 ,'a0.3b0.7u1v1.dat' u 1:4 title 'a=0.3' w l lw 2 ,'a0.4b0.7u1v1.dat' u 1:4 title 'a=0.4' w l lw 2 ,'a0.5b0.7u1v1.dat' u 1:4 title 'a=0.5' w l lw 2 ,'a0.6b0.7u1v1.dat' u 1:4 title 'a=0.6' w l lw 2 ,'a0.7b0.7u1v1.dat' u 1:4 title 'a=0.7' w l lw 2 , 'a0.8b0.7u1v1.dat' u 1:4 title 'a=0.8' w l lw 2, 'a0.9b0.7u1v1.dat' u 1:4 title 'a=0.9' w l lw 2
set output
!epstopdf b0.7u1v1.eps






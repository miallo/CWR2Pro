reset
set terminal epslatex color
set output 'a001b099uv1R.tex'
set xlabel 'Zeit $t$'
set ylabel 'Dichte $u$'
set key under box
set title 'Parameter: $a=0.01, b=0.99, u_0=v_0=1$ bei einer Schrittweite von $\Delta t=0.1$'
p 'a001b099uv1.dat' u 1:4 title 'Berechnung nach Runge-Kutta 4. Ordnung' w l lt 1 lw 2 
set output
!epstopdf a001b099uv1R.eps

reset
set terminal epslatex color
set output 'a001b099uv1ER.tex'
set xlabel 'Zeit $t$'
set ylabel 'Dichte $u$'
set key under box
set title 'Parameter: $a=0.01, b=0.99, u_0=v_0=1$ bei einer Schrittweite von $\Delta t=0.1$'
p 'a001b099uv1.dat' u 1:2 title 'Berechnung nach Euler-Cauchy' w l lt -1 lc 2 lw 1,'a001b099uv1.dat' u 1:4 title 'Berechnung nach Runge-Kutta 4. Ordnung' w l lt 1 lw 2
set output
!epstopdf a001b099uv1ER.eps

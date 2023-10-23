#set terminal 'png'
#set output "~/work/art_analysis/e559_23jul/figs/output_macro/yb_gr/yb_fit.png"

set lmargin 20
set rmargin 10
set tmargin 5
set bmargin 5
set xrange [-400:400]
set yrange [-1:-0.5]
set xlabel offset 0,0
set ylabel offset -5,0
set xlabel 'x_{fp} (mm)' font "Arial,15"
set ylabel 'slope of Y-B (mm/mrad)' font "Arial,15"
set tics font "Arial,15"

unset key 

f(x)=a*x+b
#fit f(x) "yb.dat" u 1:3 via a,b
fit f(x) "yb_4206.dat" u 1:3 via a,b	


set label 1 left  at graph 0.50,0.3 sprintf("Fit results\n p0= %.3e +/- %.3e \n p1= %.3e +/- %.3e",b,b_err/FIT_STDFIT,a,a_err/FIT_STDFIT) font "Arial,12"

#plot "yb.dat" u 1:3:2:4 with xyerrorbars
plot "yb_4206.dat" u 1:3:2:4 with xyerrorbars	
replot f(x)




set dgrid3d splines
splot "merged.dat" u 3:5:1
f(x,y,z)=a*x+b*y+c*z+d
fit f(x,y) "merged.dat" using 3:5:1 via a,b,c,d
replot f(x,y)
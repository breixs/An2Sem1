for i=1:150 
 x(i)=pi+i*pi/30; 
 y(i)=sin(x(i))/(i^2+1)*cos(i/x(i)); 
end 
% calculul integralei folosind metoda trapezelor 
I=trapz(x,y)
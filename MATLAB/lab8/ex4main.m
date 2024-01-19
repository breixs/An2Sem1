theta=0:pi/60:2*pi; r=sqrt(2);
x=r*cos(theta);
y=r*sin(theta);
plot(x, y, 'r--')
hold on;
x1=-3:0.1:-1; y11=sqrt(x1.^2-1); y12=-y11; 
x2=sort(-x1); y21=sqrt(x2.^2-1); y22=-y21; 
plot(x1,y11,'b',x1,y12,'b',x2,y21,'b',x2,y22,'b') 
axis equal,  grid, hold off 
[xcoord,ycoord]=ginput;
disp('solutiile sistemului') 
for i=1:length(xcoord) 
 sol=fsolve('ex4',[xcoord(i),ycoord(i)])
 if i<length(xcoord) pause, end 
end 

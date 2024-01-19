function g=prob1(x0)
x=x0(1); y=x0(2);
g(1)=sin(x+y)-.1*x-0.2;
g(2)=1.1*x^2+2*y^2-1;
end

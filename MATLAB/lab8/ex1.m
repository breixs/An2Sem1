function g=ex1(x0)
x=x0(1); y=x0(2); z=x0(3);
g(1)=x*y+z+3;
g(2)=x/z-y+2;
g(3)=y*z+x-6;

%sau: g=[x*y+z+3; x/z-y+2; y*z+x-6];
end

function [y]=prob6(x)
if imag(x)==0
    if x<0
        y=sin(3*x)/2*x;
    else
        y=cos(3*x);
    end
else
    disp('x nu e real')
end

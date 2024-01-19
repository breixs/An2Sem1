function [r]=prob6(w)
sol=roots(w); r=[];
disp(length(w))

for i=1:7
    if imag(sol(i))==0 
        r=[r sol(i)];
    end
end

if abs(r)>0
    disp('solutiile sunt: ')
end


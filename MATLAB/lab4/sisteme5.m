function[Sol]=sisteme5(M, n)
disp('prob3')
if det(M)~=0
    Sol=M\n;
else
    disp('sist incompatabil')
end

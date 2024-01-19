c=[1 -3 -1 -3];
sol=roots(c);
disp('solutiile sunt: '); disp(sol);

c1=[4 -13 10]; s=[];
sol1=roots(c1);
for i=1:length(i)
    if imag(sol1(i))==0 & sol1(i)>=0 & 2*sol1(i)-3>=0
        s=[s sol1(i)];
    end
end
disp('solutiile sunt: ');disp(s)

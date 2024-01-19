c=[1 1 -2 4 11 -45 -50 0]; s=[];
sol=roots(c);
for i=1:length(sol)
    if real(sol(i))>0 && imag(sol(i))==0
        s=[s sol(i)];
    end
end
disp(s)

function [s]=prob5(v)
sol=roots(v); s=[];
for i=1:length(sol)
    if real(sol(i))>0 && imag(sol(i))==0
        s=[s sol(i)];
    end
end

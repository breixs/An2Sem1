% a)
c=[8, -10, 3, -3, 2]; s=[];
sol=roots(c);
disp(sol)

for i=1:length(sol)
    if imag(sol(i))==0 && sol(i)>=0
        s=[s sol(i)];
    end
end
disp(s)

% b)

%rad=x2 + 1x + 1

r=[1, 1, 1]; s1=[];
sol1=roots(r);
disp(sol1)


for i=1:length(sol1)
    if imag(sol1(i))==0 && sol1(i)>=0
        s1=[s1 sol1(i)];
    end
end
disp ('s1='); disp(s1)

% a)
v1=[2 3 1 9 2 -1 -3 5];
i=1;
p=1;
while i<length(v1)
    i=i+1;
    if v1(i)>0
        p=p*v1(i);
    end
end
disp(p)

% b)
v2=[2 3 1 9 2 1 3 5];
j=1;
q=1;
while j<length(v2)
    j=j+1;
    q=q*v2(j);
end
disp(q)
syms a b c
eq=[2*b-a-c a+b+c-30 (b-4)^2-(a-5)*c];
var=[a b c];
s=solve(eq,var);
for i=1:length(s.a)
    disp([s.a(i) s.b(i) s.c(i)])
end

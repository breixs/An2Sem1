syms m p n q
eq=[m+p-2*n n*q-p^2 m+q-37 n+p-36];
var=[m p n q];
s=solve(eq, var);
for i=1:length(s.m)
    disp([s.m(i) s.n(i) s.p(i) s.q(i)])
end
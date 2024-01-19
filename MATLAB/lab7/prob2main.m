optiuni=optimset('Tolx', 10^(-6));
[x, fval, exitflag, output]=fzero('prob2', -3);
disp('solutia este:'); disp(x);
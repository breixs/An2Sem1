x0=[1 1];
[x, fval, exitflag, output]=fsolve('prob1', x0);
disp(x);
disp('fval'); disp(fval);
disp('exitflag'); disp(exitflag);
disp('iteratii'); disp(output.iterations);
disp('algoritmul:'); disp(output.algorithm);

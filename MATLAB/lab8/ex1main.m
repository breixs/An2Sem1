x0=[1; 0; -1];
[x, fval, exitflag, output]=fsolve('ex1', x0);
disp('sol este:'); disp(x);
disp('fval'); disp(fval);
disp('exitflag'); disp(exitflag);
disp('iteratii'); disp(output.iterations);
disp('algoritmul:'); disp(output.algorithm);
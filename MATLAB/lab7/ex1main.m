optiuni=optimset('Tolx',10^(-10));
[x,fval,exitflag,output]=fzero('ex1', -0.5, optiuni);
disp('Solutia este: '); disp(x);
disp(fval); 
disp(exitflag);
disp(output);
disp(output.iterations);
disp(output.algorithm);
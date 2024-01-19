disp('prob 1')
E=[4 3 -1; -1 1 1; 1 0 3];
f=[2;0;-1];

if det(E)~=0
    W=inv(E)*f;
    disp(W);
    W1=E\f;
    disp(W1);
else
    disp('sist incompatibil')
end










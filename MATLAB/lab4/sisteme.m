A=[5 4 1; 6 3 2; 1 1 1];
A2=[2 -3 0;-6 8 -1; 0 3 4];
b=[0;5;-7];
b2=[7; -5; 1];

if det(A)~=0
    X=inv(A)*b;
    x1=A\b;
    disp(X);
    disp(x1);
else
    disp('sist necompataibil');
end
if det(A2)~=0
    x2=inv(A2)*b2;
    S=A2\b2;
    disp(x2);
    disp(S);
else
    disp('sist incompatabil');
end

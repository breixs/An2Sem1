disp('prob 2')
G=[4 3 -1; -1 1 1; 1 0 3; 4 4 3];
h=[2; 0; -1; 1];
disp('a)')
rang=rank(G);
disp(rang);

if rank(G)==rank([G h]) %matrice extinsa
    disp('pseudo')
    I=pinv(G)*h;
    disp(I);
    disp('impartire')
    I1=G\h;
    disp(I1);
else
    disp('sist incompatibil')
end

G1=[-6 8 -1; 2 -3 0];
h1=[2;-3];
disp('b)')
rank(G1)

if rank(G1)==rank([G1 h1]) %matrice extinsa
    disp('pseudo')
    I2=pinv(G1)*h1;
    disp(I2);
else
    disp('sist incompataibil')
end




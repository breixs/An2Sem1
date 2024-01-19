Aa=[2 -3 0; -6 8 -1; 0 3 4; -4 8 3];
ba=[7; -5; 1; 3];
if rank(Aa)==rank([A b])
    disp('metoda pseudo inversarii')
    Y=pinv(Aa)*ba;
    disp(Y);
    disp('impartire la stanga')
    Y1=Aa\ba;
    disp(Y1);
else
    disp('sist necompataibil')
end

C=[3 -1 1 -2; -4 4 2 1];
d=[6;0];

if rank(C)==rank([C d]) %matrice extinsa
    disp('pseudo')
    Z=pinv(C)*d;
    disp(Z);
    disp('impartire')
    Z1=C\d;
    disp(Z1);
else
    disp('sist necompatibil');
end

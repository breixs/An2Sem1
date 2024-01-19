K=[-6 8 -1; 2 -3 0];
u=[-5;7];

disp('prob 4')

if rank(K)==rank([K u])
    S=K\u;
    disp(S)
else
    disp('sist incompatibil')
end

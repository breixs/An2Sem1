function[S]=sisteme7(a, b, g)
M1=[a -b 1; -g 1 b; 1 g -a ];
n1=[g; a; b];
disp('prob 5')

if(det(M1))~=0
    S=M1\n1;
    disp(S)
else
    disp('sist necompatibil')
end


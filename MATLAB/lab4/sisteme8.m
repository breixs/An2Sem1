function[Rez]=sisteme8(M2,n2)
disp(size(M2))
if diff(size(M2))==0
    if det(M2)~=0
    disp('sistemul este compatibil determinat')
    Rez=M2\n2;
    else
    disp('sist incompatibil')
    end
else
    if rank(M2)==rank([M2 n2])
    disp('sistemul este compatabil nederminat')
    Rez=M2\n2;
    else
        disp('sist incompatibil')
    end
end


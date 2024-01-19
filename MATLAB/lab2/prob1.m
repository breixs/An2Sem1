%prob 1
for i=1:4
    for j=1:5
        if i==j
            B(i,j)=3;
        elseif i-j==2
            B(i,j)=-3;
        elseif i+j==3
            B(i,j)=1;
        else
            B(i,j)=0;
        end
    end
end
disp(B)
module nuj ( input a,b, output reg w,x,y,z);
  always @ (a or b ) begin
    w=a+b;
    x=a-b;
    y=a*b;
    z=a/b;
  end
endmodule

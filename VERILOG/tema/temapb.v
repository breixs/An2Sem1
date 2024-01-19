module tema_brei_paul input ([15:0]a [7:0]b);
  reg [7:0]a1;
  reg [7:0]a2;
  always 0(a)
  begin 
    b1=a[15:1];
    b2=a[7:0];
  end
  assign b=(a1>a2)?a1:a2;
endmodule

module temapb_tb
  reg[15:0]a;
  reg [7:0]b;
  temapb (.a(x), b(y));
  initial begin
    a=10;
    #1;
    $display (b);
  end
endmodule

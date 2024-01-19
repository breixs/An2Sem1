module ex2(input[7:0] bcd_in, input sign, output reg[7:0]out);
  reg [7:0]max;
  
  always@(*) begin
    aux=bcd_in;
    out=aux[7:4]*10+aux[3:0];
    
    if(sign==1)
      begin
        out=~out;
      end
    end
  endmodule
  

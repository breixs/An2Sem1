module LogicDiagram (input[7:0]a, b, c, x, y, z, w, output [7:0]q);
  always @ (*) begin
    assign x= a & b ;
    assign z=c && x ;
    assign y=~b || ~c;
    assign w=a && y;
    assign q=z || w;
  end
  $display ("%d", q);
endmodule
   
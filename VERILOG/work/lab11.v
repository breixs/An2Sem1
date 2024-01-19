//module adunare
module add (input [7:0] x, y, output [8:0] z);
  assign z= x+y;
endmodule
//modul inmultire
module mult (input [8:0] a, b, output [17:0] c);
  assign c= a*b;
endmodule
//module care le incld pe toate
    module op (input [7:0] a, b, c, output [18:0] y);
      add add_0 (.x(a), .y(b), .z(c)); //conectam x, y, z
      mult mult_0 (.a(z), .b(c), .c(y));
    endmodule
      
      
      
      
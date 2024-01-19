module porti (input x, y, cin, output z, cout)
  assign z=x^y^cin;
  assign cout= (a&b) || (a & cin) || (b & cin);
endmodule 
  
module sum (input [3:0] x, y, output [3:0] z);
  wire w;
 porti porti_0(.x(x[0]), .y(y[0]), .cin(1'b0), .z(z[0]), .cout(1'b0);
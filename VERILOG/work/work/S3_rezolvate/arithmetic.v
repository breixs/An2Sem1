module arithmetic(input a, b,
   		  output reg w, x, y, z);

	always @ (*) begin
		w = a + b;
		x = a - b;
		y = a * b;
		z = a / b;	
	end
endmodule	

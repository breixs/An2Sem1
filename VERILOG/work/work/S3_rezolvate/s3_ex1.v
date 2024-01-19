module arithmetic_tb;

	reg a_tb, b_tb;
	wire w_tb, x_tb, y_tb, z_tb;

	arithmetic uut(.a(a_tb), .b(b_tb), .w(w_tb), .x(x_tb), .y(y_tb), .z(z_tb));

	initial begin
		$display("a\tb\t\tw\tx\ty\tz");  // pregatire sa printam in forma de tabel
		$monitor("%b\t%b\t\t%b\t%b\t%b\t%b", a_tb, b_tb, w_tb, x_tb, y_tb, z_tb);
		a_tb = 0;
		b_tb = 0;
		#1;  // asteptam sa se proceseze rezultatul;
		a_tb = 0;
		b_tb = 1;
		#1;
		a_tb = 1;
		b_tb = 0;
		#1;
		a_tb = 1;
		b_tb = 1;
		#1;
	end
endmodule

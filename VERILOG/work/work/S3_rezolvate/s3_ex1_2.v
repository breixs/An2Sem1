module arithmetic_tb;

	reg[10:0] a_tb; 
	reg[7:0] b_tb;
	wire[10:0] w_tb;
	wire[10:0] x_tb;
        wire[17:0] y_tb;
        wire[10:0] z_tb;

	arithmetic uut(.a(a_tb), .b(b_tb), .w(w_tb), .x(x_tb), .y(y_tb), .z(z_tb));

	initial begin
		$display("a\tb\t\tw\tx\ty\tz");  // pregatire sa printam in forma de tabel
		$monitor("%d\t%d\t\t%d\t%d\t%d\t%d", a_tb, b_tb, w_tb, x_tb, y_tb, z_tb);  // De data asta vom afisa in zecimal pentru a fi mai usor de citit rezultatele
		// Putem testa toate cazurile posibile folosind doua for-uri
		for(a_tb = 0; a_tb < 1025; a_tb = a_tb + 1)
			for(b_tb = 0; b_tb < 226; b_tb = b_tb + 1)
        		#1;  // asteptam sa se proceseze rezultatul
                /* Nu mai trebuie sa facem altceva in aceste for-uri deoarce variabilele se modifica in interiorul lor prin a_tb = a_tb + 1 */
	end
endmodule

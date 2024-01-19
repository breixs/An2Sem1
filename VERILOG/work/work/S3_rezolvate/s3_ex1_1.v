module arithmetic(input[10:0] a,  // 1025 = 1024 + 1 = 2^10 + 2^0 --> avem nevoie de pana la bitul 10 --> avem nevoie de 11 biti
		  input[7:0] b,  // 126(2^7) < 226 < 256(2^8) --> avem nevoie de 8 biti
  		  output reg[10:0] w,  // In cel mai rau caz avem w = a(max) + b(max) = 1025 + 226 = 1251. 1024(2^10) < 1251 < 2048(2^11) --> avem nevoie de 11 biti
		  output reg[10:0] x,  // In cel mai rau caz avem x = a(max) - b(min) = 1025 - 0 = 1025. --> avem nevoie de 11 biti
	          output reg[17:0] y, // In cel mai rau caz avem y = a(max) * b(max) = 1025 * 226 = 231650. 
		  /* Pentru a afla de cati biti avem nevoie pentru numere
		  * foarte mari, carora nu le-am memorat puterile lui 2, putem
		  * face in felul urmator: [log2(X) + 1], unde [y] inseamna
		  * partea intreaga a lui y (ce e inainte de virgula). */
		 // Aplicand acest aspect pentru 231650: [log2(231650) + 1] = [17.821 + 1] = [18.821] = 18 biti.
		 // Nota:  Puteti calcula log in baza 2 folosind google, doar scriind log2(231650) la cautare
		  output reg[10:0] z//In cel mai rau caz avem z = a(max) / 1 = 1025 / 1 = 1025 --> avem nevoie de 11 biti. (Nu avem numere cu virgula, iar impartirea la zero genereaza eroare
	  );

	always @ (*) begin
		w = a + b;
		x = a - b;
		y = a * b;
		z = a / b;	
	end
endmodule	

module triple(input[7:0] a,
                output[9:0] b); // In cel mai rau caz avem b = a(max) * 3 = 255 * 3 = 765. 512(2^9) < 765 < 1024(2^10) --> Avem nevoie de 10 biti

    assign b = a * 3;
endmodule

/* Modulul de mai sus poate fi implementat si ca
module triple(input[7:0] a,
                output reg[9:0] b);
    always @ (*) begin
        b = a * 3;
    end
endmodule
*/

module triple_tb;
    reg[7:0] a;
    wire[9:0] b;

    triple uut(.a(a), .b(b));
    
    initial begin
        $display("a\t\tb");
        $monitor("%d\t\t%d", a, b);
        for(a = 0; a < 255; a = a + 1)  // Gasiti mai multe explicatii in s3_ex3.v
            #1;
    end
endmodule

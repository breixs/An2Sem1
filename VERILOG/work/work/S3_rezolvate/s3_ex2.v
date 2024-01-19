module maximum(input[7:0] a, b,
                output[7:0] max);

    assign max = a > b ? a : b;
endmodule

/* Modulul de sus poate fi implementat si ca mai jos:

module maximum(input[7:0] a, b,
                output reg[7:0] max);  // Atentie ca max sa fie de tip reg

    always @(*) begin
        if(a > b) 
            max = a;
        else
            max = b;
    end
endmodule
*/
module maximum_tb;
    /* Nu trebuie sa punem _tb la variabile. Ele pot avea acelasi nume pentru ca sunt in module separate (functii diferite in C) */
    reg[7:0] a, b;
    wire[7:0] max;
    
    maximum uut(.a(a), .b(b), .max(max));

    initial begin
        $display("a\tb\t\tmax");
        $monitor("%d\t%d\t\t%d", a, b, max);

        for(a=0; a < 255 /* 2^8 - 1 */; a = a + 1)
            for(b = 0; b < 255; b = b + 1)
                #1;
        /* ATENTIE:
        Daca modificam for-ul anterior in for(a=0; a < 256; a = a + 1), programul ar fi mers la infinit
        Motivul este urmatorul:
        Cand ajungem cu a = 255 = 0b1111_1111, adunand 1 la aceasta valoare ==> 255 + 1 = 0b1_0000_0000
        Adica a = 0b1_0000_0000, insa a-ul fiind doar pe 8 biti, va lua cei mai putini semnificativi 8 biti din rezultat, adica 0b0000_0000, rezultand intr-o resetare la 0 a lui a.
        Acest aspect nu s-a aplicat pentru s3_ex1_2.v deoarece nu mergeam pana la valoarea maxima pentru numarul de biti
        Acest aspect este adevarat si in C, insa in C avem mult mai multi biti si de aceasta nu ne punem aceasta problema in majoritatea timpului (int din C este, de obicei, pe 32 de biti, adica de ordinul miliardelor ~4.3 miliarde)
        */
    end
endmodule

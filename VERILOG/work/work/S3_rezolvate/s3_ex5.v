module multiply(input[7:0] a, b,
                output[15:0] c); // In cel mai rau caz avem c = a(max) * b(max) = 255 * 255 = 65025 --> 16 biti (Faceti referire la s3_ex1_1.v pentru explicatii

/* De regula, numarul de biti poate fi determinat mai usor pentru o iesire daca stim numarul de biti ale intrarilor si operatiile ce sunt efectuate pe acestea
Regula este urmatoarea:
Daca facem adunare a doua numere intregi pe N si M biti, respectiv, atunci iesirea are nevoie de max(N, M) + 1 biti
Daca facem inmultirea a doua numere intregi pe N si M biti, respectiv, atunci iesirea are nevoie de N + M biti

Din acest motiv, trebuie avut grija si in C la numarul de biti necesari pentru o variabila care salveaza valoarea unei operatii aritmetice.
In aceeasi idee, chiar si operatiile intermediare pot afecta rezultatul, chiar daca acesta se incadreaza in final in numarul de biti necesari.

Puteti incerca urmatorul cod in C pentru a vedea acest aspect "in actiune": overflow.c
*/

    assign c = a * b;
endmodule

module multiply_tb;
    reg[7:0] a, b;
    wire[15:0] c;

    multiply uut (.a(a), .b(b), .c(c));
    
    initial begin
        $display("a\tb\t\tc");
        $monitor("%d\t%d\t\t%d", a, b, c);
        for(a=0; a < 255; a=a+1)
            for(b=0; b < 255; b=b+1)
                #1;
    end
endmodule

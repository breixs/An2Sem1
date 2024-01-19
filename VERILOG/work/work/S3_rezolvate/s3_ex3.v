module afis(input[15:0] intrare_1,
            input[3:0] intrare_2);
reg[15:0] aux;
    always @(*) begin
        for(aux = 0; aux < intrare_1; aux=aux+1) begin
            if(aux % intrare_2 == 0) begin
                $display("%d", aux);
            end
        end
        /*Varianta optima:
        for(aux = 0; aux < intrare_1; aux = aux + intrare_2) begin
            $display("%d", aux);
        end
        */
    end
endmodule

module afis_tb;
    reg[15:0] intrare_1;
    reg[3:0] intrare_2;
   
    afis uut(.intrare_1(intrare_1), .intrare_2(intrare_2));
    
    initial begin
        intrare_1 = 1000;
        intrare_2 = 20;
        #1;
    end
endmodule

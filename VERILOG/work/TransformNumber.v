module TransformNumber(
  input[7:0] n_in,
  input en,
  input[2:0] format_in,
  input sign_in,
  output[11:0] n_out);
  reg [11:0] aux;
  reg[7:0] bcd;
  reg[3:0] i;
  
  always @(format_in) begin
    case(format_in)
      3'b000: begin //SM
        aux=n_in;
        if(n_in>0)
          sign_in=0;
        else
          sign_in=1;
          
        aux[7]=sign_in;
        n_out=aux;
      end
      3'b001: begin //C1
        aux=n_in;
         if(n_in>0)
          sign_in=0;
        else
          sign_in=1;
        aux[7]=sign_in;
        n_out=~aux;
      end
      3'b010: begin //C2
        aux=n_in;
        if(n_in>0)
          sign_in=0;
        else
          sign_in=1;
        aux[7]=sign_in;
        n_out=~aux+1;
      end
      3'b011: begin //BCD
        bcd=0;
        for(i=0; i<8; i=i+1) begin
          aux = {bcd[10:0],n_in[7-i]};
          
          if(i<7 && bcd[3:0] > 4)
            bcd[3:0] = bcd[3:0]+3;
          if(i<7 && bcd[7:4] > 4)
            bcd[7:4] = bcd[7:4]+3;
          if(i<7 && bcd[11:8] > 4)
            bcd[11:8] = bcd[11:8]+3;
        end
        n_out=aux;
      end 
      3'b100: begin //E3
        bcd=0;
        for(i=0; i<8; i=i+1) begin
          aux = {bcd[10:0],n_in[7-i]};
          
          if(i<7 && bcd[3:0] > 4)
            bcd[3:0] = bcd[3:0]+3;
          if(i<7 && bcd[7:4] > 4)
            bcd[7:4] = bcd[7:4]+3;
          if(i<7 && bcd[11:8] > 4)
            bcd[11:8] = bcd[11:8]+3;
        end
        n_out=aux+3;
      end
       /* 3'b101: begin //2din5 63210
        if(n_in==0)
           aux=5'b01100;
        if(n_in==1)
           aux=5'11000;
        if(n_in==2)
           aux=5'b10100;
        if(n_in==3)
           aux=5'10010;
        if(n_in==4)
           aux=5'b01010;
        if(n_in==5)
           aux=5'00110;
        if(n_in==6)
           aux[i]=5'b10001;
        if(n_in==7)
           aux=5'01001;
        if(n_in==8)
           aux=5'b00101;
        if(n_in==9)
           aux=5'b00011;
        n_out=aux; */
    //end
     /* 3'b110: begin //2din5 74210
        if(n_in==0)
           aux=5'b11000;
        if(n_in==1)
           aux=5'00011;
        if(n_in==2)
           aux=5'b00101;
        if(n_in==3)
           aux=5'b00110;
        if(n_in==4)
           aux=5'b01001;
        if(n_in==5)
           aux=5'b01010;
        if(n_in==6)
           aux=5'b01100;
        if(n_in==7)
           aux=5'b10001;
        if(n_in==8)
           aux=5'b10010;
        if(n_in==9)
           aux=5'b10100;
        n_out=aux;
      end */
      3'b111: begin
        aux=12'bzzzzzzzzzzzz;
        n_out=aux;
      end
    endcase
  end
endmodule
        
        
            
          
        
            
          
        
      
         
          
        
  
  
  

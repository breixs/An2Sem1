module TransformNumber (
  input [7:0] n_in,
  input [3:0] format_in,
  input en,
  input sign_in,
  output reg [8:0] n_out
);
  reg [11:0] bcd;
  integer i;
  always @ (format_in, n_in) begin
    case(format_in)
      3'b000: begin //semn marime
        if (sign_in == 0)
          n_out[7] = 0;
        else
          n_out[7] = 1;
        n_out[6:0] = n_in[6:0];
      end
       3'b001: n_out = ~n_in;  //c1
      3'b010: n_out = ~n_in + 1; //c2
      3'b011: begin //bcd
        bcd = 0;
        for(i=0; i<8; i=i+1)
          bcd = {bcd[10:0], n_in[7-i]};
        n_out[11:0] = bcd[11:4];
      end
      3'b100: n_out = (n_in+3) % 8; //E3
      //3'b101: 2-din-5 74210
      //3'b110: 2-din-5 63210
      3'b111: n_out = 9'bz;
    endcase
  end
endmodule

module exercitiu 2 (input a[7:0], b[7:0], output c[7:0]);
  always @(a or b) begin
    if (a>b)
      c=a;
    if (b>a)
      c=b;
    $display("%d", c);
  end
endmodule
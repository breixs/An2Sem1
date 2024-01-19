library verilog;
use verilog.vl_types.all;
entity order is
    port(
        in_0            : in     vl_logic_vector(3 downto 0);
        in_1            : in     vl_logic_vector(3 downto 0);
        \out\           : out    vl_logic_vector(7 downto 0)
    );
end order;

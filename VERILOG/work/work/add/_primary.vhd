library verilog;
use verilog.vl_types.all;
entity add is
    port(
        x               : in     vl_logic_vector(7 downto 0);
        y               : in     vl_logic_vector(7 downto 0);
        z               : out    vl_logic_vector(8 downto 0)
    );
end add;

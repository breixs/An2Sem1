library verilog;
use verilog.vl_types.all;
entity comp is
    port(
        in_0            : in     vl_logic_vector(7 downto 0);
        in_1            : in     vl_logic_vector(7 downto 0);
        eq              : out    vl_logic;
        max             : out    vl_logic_vector(7 downto 0)
    );
end comp;

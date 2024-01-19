library verilog;
use verilog.vl_types.all;
entity op is
    port(
        a               : in     vl_logic_vector(7 downto 0);
        b               : in     vl_logic_vector(7 downto 0);
        c               : in     vl_logic_vector(7 downto 0);
        y               : out    vl_logic_vector(18 downto 0)
    );
end op;

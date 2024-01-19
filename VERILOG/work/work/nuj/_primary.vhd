library verilog;
use verilog.vl_types.all;
entity nuj is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        w               : out    vl_logic;
        x               : out    vl_logic;
        y               : out    vl_logic;
        z               : out    vl_logic
    );
end nuj;

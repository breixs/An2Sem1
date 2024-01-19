library verilog;
use verilog.vl_types.all;
entity diagram is
    port(
        a               : in     vl_logic;
        b               : in     vl_logic;
        c               : in     vl_logic;
        q               : out    vl_logic
    );
end diagram;

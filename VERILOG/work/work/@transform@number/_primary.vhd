library verilog;
use verilog.vl_types.all;
entity TransformNumber is
    port(
        n_in            : in     vl_logic_vector(7 downto 0);
        format_in       : in     vl_logic_vector(3 downto 0);
        en              : in     vl_logic;
        sign_in         : in     vl_logic;
        n_out           : out    vl_logic_vector(8 downto 0)
    );
end TransformNumber;

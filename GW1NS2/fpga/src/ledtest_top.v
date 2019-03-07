module ledtest_top (
  sys_clk,
  gpio,
  reset_n,
  uart0_txd,
  uart0_rxd,
  scl,
  sda
  
);
input sys_clk ;
inout [15:0] gpio /* synthesis syn_tristate = 1 */ ;
input reset_n;
output uart0_txd;
input uart0_rxd;
inout scl;
inout sda;

Gowin_EMPU Gowin_EMPU_inst(
    .sys_clk(sys_clk),
    .gpio(gpio),
    .reset_n(reset_n),
    .uart0_txd(uart0_txd),
    .uart0_rxd(uart0_rxd),
    .scl(scl),
    .sda(sda)
);
endmodule
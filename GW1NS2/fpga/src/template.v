/****************************************************************
========Oooo=========================================Oooo========
=     Copyright ©2015-2018 Gowin Semiconductor Corporation.     =
=                     All rights reserved.                      =
========Oooo=========================================Oooo========

<File Title>: IP file
<Series, Device, Package, Speed>: GW1NS, GW1NS-2C
<Created Time>: Mon Jun 11 13:51:31 2018
****************************************************************/

`timescale 100 ps/100 ps
module Gowin_EMPU_template (
 sys_clk,
 gpio,
 uart0_rxd,
 uart0_txd,
 reset_n
 );
 
input sys_clk;
inout [15:0] gpio /* synthesis syn_tristate = 1 */ ;
input uart0_rxd;
output uart0_txd;
input reset_n;

Gowin_EMPU empu_tmp (
 .sys_clk(sys_clk),
 .gpio(gpio),
 .uart0_rxd(uart0_rxd),
 .uart0_txd(uart0_txd),
 .reset_n(reset_n)
);

endmodule
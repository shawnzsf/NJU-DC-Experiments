`default_nettype none
module top(clk, cin, rst, q);
    input wire clk, cin, rst;
    output reg [2:0] q;
/* verilator lint_off WIDTHEXPAND */
    always @(posedge clk)
    begin
        if(rst == 1'b1) q <= 3'b0;
        else q <= q - cin;
    end
/* verilator lint_on WIDTHEXPAND */
endmodule

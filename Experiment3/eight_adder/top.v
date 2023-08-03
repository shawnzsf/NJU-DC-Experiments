`default_nettype none
module top(c, a, b, s, d);
    input wire [7:0] a, b;
    input wire c; //carry from previous adder
    output wire [7:0] s;
    output wire d; //carry from current adder

    /* verilator lint_off WIDTHEXPAND */
    assign {d, s} = a + b + c;
    /* verilator lint_on WIDTHEXPAND */
endmodule

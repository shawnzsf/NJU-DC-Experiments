`default_nettype none
module top(a, b, c, s, d);
    input wire a, b, c;
    output wire s, d;

    assign {d, s} = a + b + c;
endmodule

`default_nettype none
module top(load, clk, clr, inp, q);
    input wire load, clr, clk;
    input [3:0] inp;
    output reg [3:0] q;

    always @(posedge clk)
    begin
        if(clr == 1)
            q <= 0;
        else if(load == 1)
            q <= inp;
    end
endmodule

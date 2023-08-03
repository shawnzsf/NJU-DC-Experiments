`default_nettype none
module top(clk, wr_en, data_in, addr, data_out);
    input wire clk, wr_en;
    input wire [3:0] data_in;
    output reg [3:0] addr;     //Since there is no memory address in this stance, this variable does not mean real address but a transfer station.
    output reg [3:0] data_out;

    always @(posedge clk)
    begin
        if(wr_en == 1'b1) addr <= data_in;
        data_out <= addr;
    end
endmodule

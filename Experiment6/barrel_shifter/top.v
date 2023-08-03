`default_nettype none
module top(din, shamt, LorR, AorL, dout);
    input wire [7:0] din;
    input wire [2:0] shamt;
    input wire LorR, AorL;
    output reg [7:0] dout;
    reg [7:0] tmp;

    always @(din or shamt or LorR or AorL)
    begin
        case(AorL)
            1'b0: case(LorR)
                    1'b1:
                    begin
                        tmp <= shamt[0] ? {din[6:0], 1'b0} : tmp;
                        tmp <= shamt[1] ? {din[5:0], 2'b0} : tmp;
                        tmp <= shamt[2] ? {din[3:0], 4'b0} : tmp;
                    end
                    1'b0:
                    begin
                        tmp <= shamt[0] ? {1'b0, din[7:1]} : tmp;
                        tmp <= shamt[1] ? {2'b0, din[7:2]} : tmp;
                        tmp <= shamt[2] ? {4'b0, din[7:4]} : tmp;
                    end
                  endcase
            1'b1: case(LorR)
                  1'b1:
                    begin
                        tmp <= shamt[0] ? {din[6:0], 1'b0} : tmp;
                        tmp <= shamt[1] ? {din[5:0], 2'b0} : tmp;
                        tmp <= shamt[2] ? {din[3:0], 4'b0} : tmp;
                    end
                  1'b0:
                    begin
                        tmp <= shamt[0] ? {din[7], din[7:1]} : tmp;
                        tmp <= shamt[1] ? {{2{din[7]}}, din[7:2]} : tmp;
                        tmp <= shamt[2] ? {{4{din[7]}}, din[7:4]} : tmp;
                    end
            endcase
        endcase
        dout <= tmp;
    end
endmodule

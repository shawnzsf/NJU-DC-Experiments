`default_nettype none
module top(clk, in, reset, out);
    input clk, in, reset;
    output reg out;
    parameter[3:0] 
    S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4,
    S5 = 5, S6 = 6, S7 = 7, S8 = 8;
    reg [3:0] state_din = S0, state_dout = S0;
//output 1 after three continuous 0 or 1 input
/* verilator lint_off BLKSEQ */
    always @(posedge clk)
    begin
        case(in)
            1'b0: 
                case(state_din)
                    S5: state_dout = S1;
                    S6: state_dout = S1;
                    S7: state_dout = S1;
                    S8: state_dout = S1;
                    S0: state_dout = S1;
                    S1: state_dout = S2;
                    S2: state_dout = S3;
                    S3: state_dout = S4;
                    S4: state_dout = S4;
                    default: state_dout = S0;
                endcase
            1'b1:
                case(state_din)
                    S1: state_dout = S5;
                    S2: state_dout = S5;
                    S3: state_dout = S5;
                    S4: state_dout = S5;
                    S0: state_dout = S5;
                    S5: state_dout = S6;
                    S6: state_dout = S7;
                    S7: state_dout = S8;
                    S8: state_dout = S8;
                    default: state_dout = S0;
                endcase 
        endcase
        if(state_dout == S4 | state_dout == S8) out = 1;
        else out = 0;
        if(reset == 1'b1) state_din = S0;
        else state_din = state_dout;
        /* verilator lint_on BLKSEQ */
    end
endmodule

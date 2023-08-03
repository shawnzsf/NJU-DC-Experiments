`default_nettype none
module top(a, b, sel, res, overflow);
    input wire signed [31:0] a, b;
    input wire [3:0] sel;
    output reg overflow;
    output reg signed [31:0] res;
/* verilator lint_off LATCH */
    always @(*)
    begin
        case (sel)
            4'b0001: 
            begin
                overflow = 0;
                res = a + b;
                overflow = (a[31] == b[31]) && (res[31] != a[31]);
            end
            4'b0010: 
            begin
                overflow = 0;
                res = a + (~b + 1);
                overflow = (a[31] != b[31]) && (res[31] != a[31]);
            end
            4'b0011: 
            begin
                overflow = 0;
                res = a ^ b;
            end
            4'b0100: 
            begin
                overflow = 0;
                res = a & b;
            end
            4'b0101: 
            begin
                overflow = 0;
                res = a | b;
            end
            4'b0110: 
            begin
                overflow = 0;
                res = {res[30:0], 1'b0};
            end
            4'b0111: 
            begin
                overflow = 0;
                res = {1'b0, res[31:1]};
            end
            4'b1000: 
            begin
                overflow = 0;
                res = {res[31], res[31:1]};
            end
            4'b1001:
            begin
                overflow = 0;
                res = a + (~b + 1);
                res = res[31] ? 32'b1 : 32'b0;  //less than output 1, else 0
            end
            default:
                res = 32'b0; 
        endcase
    end
/* verilator lint_on LATCH */
endmodule

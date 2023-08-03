`default_nettype none
module top(a, b, cin, pcarry, carry, zero, overflow, result);
    input wire signed [31:0] a, b;
    input wire cin, pcarry;
    output wire carry, zero, overflow;
    output wire signed [31:0] result;
/* verilator lint_off WIDTHEXPAND */
    assign {carry, result} = cin ? a + ({32{cin}}^b) + cin + pcarry : a + b + pcarry;
    assign overflow = cin ? (a[31] == (cin^b[31])) && (result[31] != a[31]) : (a[31] == b[31]) && (result[31] != a[31]);
    assign zero = ~(| result);
/* verilator lint_on WIDTHEXPAND */
endmodule

/*        case(cin)
            1'b0: 
                begin
                  assign {carry, result} = a + b + pcarry;
                  assign overflow = (a[31] == b[31]) && (result[31] != a[31]);
                  assign zero = ~(| result);
                end
            1'b1:
                begin 
                  assign {carry,result} = a + ({32{cin}}^b) + cin + pcarry;
                  assign overflow = (a[31] == (cin^b[31])) && (result[31] != a[31]);
                  assign zero = ~(| result);
                end
        endcase
*/

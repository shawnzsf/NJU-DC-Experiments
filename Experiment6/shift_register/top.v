`default_nettype none
module top(clk, sel, cin, data_in, data_out);
    input wire clk;
    input wire [2:0] sel;
    input wire cin;
    input reg [7:0] data_in;
    reg [6:0] mem;
    reg [2:0] cnt;
    output reg [7:0] data_out;

    always @(posedge clk)
    begin
        case(sel)
            3'b000: data_out <= 8'b0;
            3'b001: data_out <= data_in;
            3'b010: data_out <= {1'b0, data_out[7:1]};
            3'b011: data_out <= {data_out[6:0], 1'b0};
            3'b100: data_out <= {data_out[7], data_out[7:1]};
            3'b101: 
            begin
                if(cnt == 3'b111)
                begin
                    data_out[7-cnt] <= cin;
                    data_out[7:1] <= mem[6:0];
                    cnt <= 0;
                end
                else
                begin
                    mem[7-cnt] <= cin;
                    cnt <= cnt + 1;
                end
            end
            3'b110: data_out <= {data_out[0], data_out[7:1]};
            3'b111: data_out <= {data_out[6:0], data_out[7]};
            default: data_out <= 8'b0;
        endcase
    end
endmodule

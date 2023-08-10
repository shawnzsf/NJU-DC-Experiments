module top(clk,resetn,ps2_clk,ps2_data,seg0,seg1,seg2,seg3,seg4,seg5);
    /* verilator lint_off WIDTHTRUNC */
	input clk, resetn, ps2_clk, ps2_data;

    reg [9:0] buffer;                          // ps2_data bits
    reg [3:0] count;                           // count ps2_data bits
    reg [2:0] ps2_clk_sync;
	reg [7:0] cnt = 0;

    parameter[3:0] 
    S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4,
    S5 = 5, S6 = 6, S7 = 7, S8 = 8, S9 = 9,
	S10 = 10, S11 = 11, S12 = 12, S13 = 13, S14 = 14,
    S15 = 15, S16 = 16, S17 = 17, S18 = 18, S19 = 19,
	S20 = 20, S21 = 21, S22 = 22, S23 = 23, S24 = 24,
    S25 = 25, S26 = 26, S27 = 27, S28 = 28, S29 = 29,
	S30 = 30, S31 = 31, S32 = 32, S33 = 33, S34 = 34;
	reg [3:0] state_din = S0, state_dout = S0;

    output reg [7:0] seg0;
    output reg [7:0] seg1;
	output reg [7:0] seg2;
	output reg [7:0] seg3;
	output reg [7:0] seg4;
	output reg [7:0] seg5;
    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end
    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
		// seg3[7:0] = 8'b11111111;
		// seg2[7:0] = 8'b11111111;
		// seg1[7:0] = 8'b11111111;
		// seg0[7:0] = 8'b11111111;
        if (resetn == 0) begin                 // reset
            count <= 0;
        end
        else begin
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&        // start bit
                    (ps2_data)       &&        // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    $display("receive %x", buffer[8:1]);
                    case(buffer[8:1])
                    	8'h1c: 
						begin
						$display("ASCII %d", 65);
						seg3[7:0] = 8'b01000001;
						seg2[7:0] = 8'b01001001;
						cnt = cnt + 1;
						state_dout = S1;
						if(state_din == S1) cnt = cnt - 1;
						end
						8'h32: 
						begin
						$display("ASCII %d", 66);
						seg3[7:0] = 8'b01000001;
						seg2[7:0] = 8'b01000001;
						cnt = cnt + 1;
						state_dout = S2;
						if(state_din == S2) cnt = cnt - 1;
						end
						8'h21: 
						begin
						$display("ASCII %d", 67);
						seg3[7:0] = 8'b01000001;
						seg2[7:0] = 8'b00011111;
						cnt = cnt + 1;
						state_dout = S3;
						if(state_din == S3) cnt = cnt - 1;
						end
						8'h23: 
						begin
						$display("ASCII %d", 68); 
						seg3[7:0] = 8'b01000001;
						seg2[7:0] = 8'b00000001;
						cnt = cnt + 1;
						state_dout = S4;
						if(state_din == S4) cnt = cnt - 1;
						end
						8'h24: 
						begin
						$display("ASCII %d", 69);
						seg3[7:0] = 8'b01000001;
						seg2[7:0] = 8'b00001001;
						cnt = cnt + 1;
						state_dout = S5;
						if(state_din == S5) cnt = cnt - 1;
						end
						8'h2b:
						begin
						$display("ASCII %d", 70);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b00000011;
						cnt = cnt + 1;
						state_dout = S6;
						if(state_din == S6) cnt = cnt - 1;
						end
						8'h34: 
						begin
						$display("ASCII %d", 71);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b10011111;
						cnt = cnt + 1;
						state_dout = S7;
						if(state_din == S7) cnt = cnt - 1;
						end
						8'h33: 
						begin
						$display("ASCII %d", 72); 
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b00100101;
						cnt = cnt + 1;
						state_dout = S8;
						if(state_din == S8) cnt = cnt - 1;
						end
						8'h43: 
						begin
						$display("ASCII %d", 73);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b00001101;
						cnt = cnt + 1;
						state_dout = S9;
						if(state_din == S9) cnt = cnt - 1;
						end
						8'h3b:
						begin
						$display("ASCII %d", 74);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b10011001;
						cnt = cnt + 1;
						state_dout = S10;
						if(state_din == S10) cnt = cnt - 1;
						end
						8'h42: 
						begin
						$display("ASCII %d", 75);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b01001001;
						cnt = cnt + 1;
						state_dout = S11;
						if(state_din == S11) cnt = cnt - 1;
						end
						8'h4b: 
						begin
						$display("ASCII %d", 76); 
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b01000001;
						cnt = cnt + 1;
						state_dout = S12;
						if(state_din == S12) cnt = cnt - 1;
						end
						8'h3a: 
						begin
						$display("ASCII %d", 77);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b00011111;
						cnt = cnt + 1;
						state_dout = S13;
						if(state_din == S13) cnt = cnt - 1;
						end
						8'h31: 
						begin
						$display("ASCII %d", 78);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b00000001;
						cnt = cnt + 1;
						state_dout = S14;
						if(state_din == S14) cnt = cnt - 1;
						end
						8'h44: 
						begin
						$display("ASCII %d", 79);
						seg3[7:0] = 8'b00011111;
						seg2[7:0] = 8'b00001001;
						cnt = cnt + 1;
						state_dout = S15;
						if(state_din == S15) cnt = cnt - 1;
						end
						8'h4d: 
						begin
						$display("ASCII %d", 80);
						seg3[7:0] = 8'b00000001; 
						seg2[7:0] = 8'b00000011;
						cnt = cnt + 1;
						state_dout = S16;
						if(state_din == S16) cnt = cnt - 1;
						end
						8'h15: 
						begin
						$display("ASCII %d", 81);
						seg3[7:0] = 8'b00000001; 
						seg2[7:0] = 8'b10011111;
						cnt = cnt + 1;
						state_dout = S17;
						if(state_din == S17) cnt = cnt - 1;
						end
						8'h2d: 
						begin
						$display("ASCII %d", 82);
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b00100101;
						cnt = cnt + 1;
						state_dout = S18;
						if(state_din == S18) cnt = cnt - 1;
						end
						8'h1b:
						begin
						$display("ASCII %d", 83);
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b00001101;
						cnt = cnt + 1;
						state_dout = S19;
						if(state_din == S19) cnt = cnt - 1;
						end
						8'h2c: 
						begin
						$display("ASCII %d", 84); 
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b10011001;
						cnt = cnt + 1;
						state_dout = S20;
						if(state_din == S20) cnt = cnt - 1;
						end
						8'h3c: 
						begin
						$display("ASCII %d", 85);
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b01001001;
						cnt = cnt + 1;
						state_dout = S21;
						if(state_din == S21) cnt = cnt - 1;
						end
						8'h2a: 
						begin
						$display("ASCII %d", 86);
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b01000001;
						cnt = cnt + 1;
						state_dout = S22;
						if(state_din == S22) cnt = cnt - 1;
						end
						8'h1d:
						begin
						$display("ASCII %d", 87);
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b00011111;
						cnt = cnt + 1;
						state_dout = S22;
						if(state_din == S22) cnt = cnt - 1;
						end
						8'h22: 
						begin
						$display("ASCII %d", 88); 
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b00000001;
						cnt = cnt + 1;
						state_dout = S22;
						if(state_din == S22) cnt = cnt - 1;
						end
						8'h35: 
						begin
						$display("ASCII %d", 89);
						seg3[7:0] = 8'b00000001;
						seg2[7:0] = 8'b00001001;
						cnt = cnt + 1;
						state_dout = S22;
						if(state_din == S22) cnt = cnt - 1;
						end
						8'h1a: 
						begin
						$display("ASCII %d", 90);
						seg3[7:0] = 8'b00001001;
						seg2[7:0] = 8'b00000011;
						cnt = cnt + 1;
						state_dout = S23;
						if(state_din == S23) cnt = cnt - 1;
						end
						8'h16: 
						begin
						$display("ASCII %d", 49);
						seg3[7:0] = 8'b10011001;
						seg2[7:0] = 8'b00001001;
						cnt = cnt + 1;
						state_dout = S24;
						if(state_din == S24) cnt = cnt - 1;
						end
						8'h1e: 
						begin
						$display("ASCII %d", 50);
						seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b00000011;
						cnt = cnt + 1;
						state_dout = S25;
						if(state_din == S25) cnt = cnt - 1;
						end
						8'h26: 
						begin
						$display("ASCII %d", 51); 
						seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b10011111;
						cnt = cnt + 1;
						state_dout = S26;
						if(state_din == S26) cnt = cnt - 1;
						end
						8'h25: 
						begin
						$display("ASCII %d", 52);
                    	seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b00100101;
						cnt = cnt + 1;
						state_dout = S27;
						if(state_din == S28) cnt = cnt - 1;
						end
						8'h2e: 
						begin
						$display("ASCII %d", 53);
                    	seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b00001101;
						cnt = cnt + 1;
						state_dout = S29;
						if(state_din == S29) cnt = cnt - 1;
						end
						8'h36: 
						begin
						$display("ASCII %d", 54);
                    	seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b10011001;
						cnt = cnt + 1;
						state_dout = S30;
						if(state_din == S30) cnt = cnt - 1;
						end
						8'h3d: 
						begin
						$display("ASCII %d", 55);
						seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b01001001;
						cnt = cnt + 1;
						state_dout = S31;
						if(state_din == S31) cnt = cnt - 1;
						end
						8'h3e: 
						begin
						$display("ASCII %d", 56);
						seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b01000001;
						cnt = cnt + 1;
						state_dout = S32;
						if(state_din == S32) cnt = cnt - 1;
						end
						8'h46: 
						begin
						$display("ASCII %d", 57);
						seg3[7:0] = 8'b01001001;
						seg2[7:0] = 8'b00011111;
						cnt = cnt + 1;
						state_dout = S33;
						if(state_din == S33) cnt = cnt - 1;
						end
                    	8'h45: 
						begin
						$display("ASCII %d", 48); 
						seg3[7:0] = 8'b10011001;
						seg2[7:0] = 8'b00000001;
						cnt = cnt + 1;
						state_dout = S34;
						if(state_din == S34) cnt = cnt - 1;
						end
						default: 
						begin
						$display("ASCII 0");
						seg3[7:0] = 8'b11111111;
						seg2[7:0] = 8'b11111111;
						seg1[7:0] = 8'b11111111;
						seg0[7:0] = 8'b11111111;
						end
					endcase
                    
					case(buffer[4:1])
						4'h0: seg0[7:0] = 8'b00000011;
						4'h1: seg0[7:0] = 8'b10011111;
						4'h2: seg0[7:0] = 8'b00100101;
						4'h3: seg0[7:0] = 8'b00001101;
						4'h4: seg0[7:0] = 8'b10011001;
						4'h5: seg0[7:0] = 8'b01001001;
						4'h6: seg0[7:0] = 8'b01000001;
						4'h7: seg0[7:0] = 8'b00011111;
						4'h8: seg0[7:0] = 8'b00000001;
						4'h9: seg0[7:0] = 8'b00001001;
						4'ha: seg0[7:0] = 8'b00010001;
						4'hb: seg0[7:0] = 8'b11000001;
						4'hc: seg0[7:0] = 8'b01100011;
						4'hd: seg0[7:0] = 8'b10000101;
						4'he: seg0[7:0] = 8'b01100001;
						4'hf: seg0[7:0] = 8'b01110001;
		        	endcase

					case(buffer[8:5])
						4'h0: seg1[7:0] = 8'b00000011;
						4'h1: seg1[7:0] = 8'b10011111;
						4'h2: seg1[7:0] = 8'b00100101;
						4'h3: seg1[7:0] = 8'b00001101;
						4'h4: seg1[7:0] = 8'b10011001;
						4'h5: seg1[7:0] = 8'b01001001;
						4'h6: seg1[7:0] = 8'b01000001;
						4'h7: seg1[7:0] = 8'b00011111;
						4'h8: seg1[7:0] = 8'b00000001;
						4'h9: seg1[7:0] = 8'b00001001;
						4'ha: seg1[7:0] = 8'b00010001;
						4'hb: seg1[7:0] = 8'b11000001;
						4'hc: seg1[7:0] = 8'b01100011;
						4'hd: seg1[7:0] = 8'b10000101;
						4'he: seg1[7:0] = 8'b01100001;
						4'hf: seg1[7:0] = 8'b01110001;
		        	endcase

					case(cnt[3:0])
						4'h0: seg4[7:0] = 8'b00000011;
						4'h1: seg4[7:0] = 8'b10011111;
						4'h2: seg4[7:0] = 8'b00100101;
						4'h3: seg4[7:0] = 8'b00001101;
						4'h4: seg4[7:0] = 8'b10011001;
						4'h5: seg4[7:0] = 8'b01001001;
						4'h6: seg4[7:0] = 8'b01000001;
						4'h7: seg4[7:0] = 8'b00011111;
						4'h8: seg4[7:0] = 8'b00000001;
						4'h9: seg4[7:0] = 8'b00001001;
						4'ha: seg4[7:0] = 8'b00010001;
						4'hb: seg4[7:0] = 8'b11000001;
						4'hc: seg4[7:0] = 8'b01100011;
						4'hd: seg4[7:0] = 8'b10000101;
						4'he: seg4[7:0] = 8'b01100001;
						4'hf: seg4[7:0] = 8'b01110001;
						default: seg4[7:0] = 8'b00000011;
		        	endcase

					case(cnt[7:4])
						4'h0: seg5[7:0] = 8'b00000011;
						4'h1: seg5[7:0] = 8'b10011111;
						4'h2: seg5[7:0] = 8'b00100101;
						4'h3: seg5[7:0] = 8'b00001101;
						4'h4: seg5[7:0] = 8'b10011001;
						4'h5: seg5[7:0] = 8'b01001001;
						4'h6: seg5[7:0] = 8'b01000001;
						4'h7: seg5[7:0] = 8'b00011111;
						4'h8: seg5[7:0] = 8'b00000001;
						4'h9: seg5[7:0] = 8'b00001001;
						4'ha: seg5[7:0] = 8'b00010001;
						4'hb: seg5[7:0] = 8'b11000001;
						4'hc: seg5[7:0] = 8'b01100011;
						4'hd: seg5[7:0] = 8'b10000101;
						4'he: seg5[7:0] = 8'b01100001;
						4'hf: seg5[7:0] = 8'b01110001;
						default: seg5[7:0] = 8'b00000011;
		        	endcase
                end
                count <= 0;                    // for next
              end else begin
                buffer[count] <= ps2_data;     // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
		state_din = state_dout;
    end
	/* verilator lint_on WIDTHTRUNC */

endmodule

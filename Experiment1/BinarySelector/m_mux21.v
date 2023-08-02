`default_nettype none
module m_mux21(a,b,s,y);
  input wire a,b,s;    
  output wire y;       

  assign  y = (~s&a)|(s&b);  

endmodule

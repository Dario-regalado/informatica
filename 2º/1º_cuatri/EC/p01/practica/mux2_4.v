// multiplexor 2-1 de 4 bits

module mux2_4(output wire [3:0] Out, input wire [3:0] A, input wire [3:0] B, input wire s);

assign Out = s == 1'b0? A : B;

endmodule
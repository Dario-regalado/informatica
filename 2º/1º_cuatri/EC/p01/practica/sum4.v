//sumador completo usando full adders
module sum4(output wire[3:0] S, output wire c_out, input wire[3:0] A, input wire[3:0] B, input wire c_in);
// declaraciones de variables
wire c1, c2, c3;

// implementacion estructural
fa full1(c1, S[0], A[0], B[0], c_in);
fa full2(c2, S[1], A[1], B[1], c1);
fa full3(c3, S[2], A[2], B[2], c2);
fa full4(c_out, S[3], A[3], B[3], c3);

endmodule
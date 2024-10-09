// celda logica de 2 entradas a 1

module cl(output wire out, input wire a, b, input wire [1:0] S);

wire w1;
wire w2;
wire w3;
wire w4;

and and1(w1, a, b);
or or1(w2, a, b);
xor xor1(w3, a, b);
not not1(w4, a);

mux4_1 mux1(out, w1, w2, w3, w4, S);

endmodule
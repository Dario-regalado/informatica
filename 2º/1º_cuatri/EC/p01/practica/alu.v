// implementacion de la alu
module alu(output wire [3:0] R, 
           output wire zero, carry, sign, 
           input wire [3:0] A, B, 
           input wire c_in, 
           input wire [2:0] Op);

//declaracion de conexiones internas
wire[3:0] OP1, OP2, Muxin1, Muxin2;

//implementacion del modulo
preprocess preprocesador1(OP1, OP2, A, B, Op);
sum4_v2 sumador1(Muxin1, carry, OP1, OP2, c_in);
ul4 ul(Muxin2, OP1, OP2, {Op[1], Op[0]});
mux2_4 mux1(R, Muxin1, Muxin2, Op[2]);

// Flag Zero: será 1 si R es igual a 0
assign zero = (R == 4'b0000) ? 1'b1 : 1'b0;
// Flag Sign: toma el valor del bit más significativo (MSB) de R
assign sign = R[3];
endmodule
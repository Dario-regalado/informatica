//preprocesador
module preprocess(output wire [3:0] AMod, 
                  output wire [3:0] BMod, 
                  input wire [3:0] A, 
                  input wire [3:0] B, 
                  input wire [2:0] Op);

//declaraciones de variables
wire add1, op1_A, op2_B, cpl;
wire [3:0] A1, B1;

wire a, b, c;
assign a = Op[2];
assign b = Op[1];
assign c = Op[0];

  assign add1 = c | a;
  assign op1_A = ((a) | (b & ~c));
  assign op2_B = ((a) | (b & ~c));
  assign cpl = (~a & ~b & c);

//implementacion del modulo
mux2_4 mux1(A1, 4'b0000, 4'b0001, add1); 
mux2_4 mux2(AMod, A1, A, op1_A);
mux2_4 mux3(B1, A, B, op2_B);
compl1 compl(BMod, B1, cpl);

endmodule
//Sumador completo (full-adder) de tres entradas de 1 bit realizado a partir de puertas l�gicas 
module fa_v1(output wire sum, output wire c_out, input wire a, input wire b, input wire c_in);

//Declaraci�n de conexiones internas:
wire sum1;
wire carry1;
wire carry2;
//Estructura interna: Instancias de puertas y sus conexiones

ha_v1 ha1(sum1, carry1, a, b);
ha_v1 ha2(sum, carry2, c_in, sum1);
or or1(c_out, carry1, carry2);

endmodule

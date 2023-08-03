#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vtop.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vtop* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vtop;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("dump.vcd");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();

  top->clk = 0; top->sel = 0b001; top->cin = 0; top->data_in = 0b10101110; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b001; top->cin = 0; top->data_in = 0b10101110; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b010; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b010; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b100; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b100; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);  
  top->clk = 0; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 1; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);  
  top->clk = 0; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b101; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b110; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b110; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b111; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b111; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 0; top->sel = 0b000; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);
  top->clk = 1; top->sel = 0b000; top->cin = 0; top->data_in = 0b0; step_and_dump_wave();
  printf("clk = %d, sel = %d, cin = %d, data_in = %d, data_out = %d\n", top->clk, top->sel, top->cin, top->data_in, top->data_out);

  sim_exit();
}
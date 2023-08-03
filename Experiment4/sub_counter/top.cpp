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

  top->clk = 0; top->cin = 1; top->rst = 0; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 1; top->cin = 1; top->rst = 0; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 0; top->cin = 1; top->rst = 0; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 1; top->cin = 1; top->rst = 0; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 0; top->cin = 1; top->rst = 0; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 1; top->cin = 1; top->rst = 0; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 0; top->cin = 1; top->rst = 1; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  top->clk = 1; top->cin = 1; top->rst = 1; step_and_dump_wave();
  printf("clk = %d, cin = %d, rst = %d, q = %d\n", top->clk, top->cin, top->rst, top->q);
  
  sim_exit();
}
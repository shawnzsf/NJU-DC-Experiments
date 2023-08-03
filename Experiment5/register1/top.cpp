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

  top->clk = 0; top->load = 0; top->clr = 0; top->inp = 0; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 1; top->load = 0; top->clr = 0; top->inp = 0; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 0; top->load = 1; top->clr = 0; top->inp = 1; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 1; top->load = 1; top->clr = 0; top->inp = 1; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 0; top->load = 1; top->clr = 0; top->inp = 0; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 1; top->load = 1; top->clr = 0; top->inp = 0; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 0; top->load = 0; top->clr = 1; top->inp = 1; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  top->clk = 1; top->load = 0; top->clr = 1; top->inp = 1; step_and_dump_wave();
  printf("clk = %d, load = %d, clr = %d, inp = %d, q = %d\n", top->clk, top->load, top->clr, top->inp, top->q);
  
  sim_exit();
}
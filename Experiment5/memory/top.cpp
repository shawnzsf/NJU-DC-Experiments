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

  top->clk = 0; top->wr_en = 0; top->data_in = 0; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 1; top->wr_en = 0; top->data_in = 0; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 0; top->wr_en = 1; top->data_in = 1; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 1; top->wr_en = 1; top->data_in = 1; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 0; top->wr_en = 1; top->data_in = 2; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 1; top->wr_en = 1; top->data_in = 2; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 0; top->wr_en = 0; top->data_in = 1; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  top->clk = 1; top->wr_en = 0; top->data_in = 1; step_and_dump_wave();
  printf("clk = %d, wr_en = %d, data_in = %d, addr = %d, data_out = %d\n", top->clk, top->wr_en, top->data_in, top->addr, top->data_out);
  sim_exit();
}
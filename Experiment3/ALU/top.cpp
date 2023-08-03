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

  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0001; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0010; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0011; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0100; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0101; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0110; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b0111; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b1000; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->sel = 0b1001; step_and_dump_wave();
  printf("a = %d, b = %d, sel = %d, res = %d, overflow = %d\n", top->a, top->b, top->sel, top->res, top->overflow);

  sim_exit();
}
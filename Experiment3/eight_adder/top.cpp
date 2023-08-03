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

  top->c = 0; top->a = 0b00000001; top->b = 0b00000001; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 0; top->a = 0b00000011; top->b = 0b00000011; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 0; top->a = 0b00000111; top->b = 0b00000111; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 0; top->a = 0b11111111; top->b = 0b00000001; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 1; top->a = 0b00000001; top->b = 0b00000001; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 1; top->a = 0b00000011; top->b = 0b00000011; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 1; top->a = 0b00000111; top->b = 0b00000111; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  top->c = 1; top->a = 0b11111111; top->b = 0b00000000; step_and_dump_wave();
  printf("c = %d, a = %d, b = %d, s = %d, d = %d\n", top->c, top->a, top->b, top->s, top->d);
  
  sim_exit();
}
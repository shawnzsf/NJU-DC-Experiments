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
  top->s=0;  top->a=14;  step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
             top->a=1;   step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
  top->s=1;  top->a=14;  step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
             top->a=2;   step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
  top->s=2;  top->a=10;  step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
             top->a=4;   step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
  top->s=3;  top->a=7;   step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);
             top->a=9;   step_and_dump_wave();
  printf("s = %d, a = %d, y = %d\n", top->s, top->a, top->y);          
  sim_exit();
}
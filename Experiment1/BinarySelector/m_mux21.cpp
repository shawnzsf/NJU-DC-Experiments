#include "verilated.h"
#include "verilated_vcd_c.h"
#include "obj_dir/Vm_mux21.h"

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vm_mux21* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  top = new Vm_mux21;
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

  top->s=0; top->a=0; top->b=0;  step_and_dump_wave();
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
                      top->b=1;  step_and_dump_wave();
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
            top->a=1; top->b=0;  step_and_dump_wave(); 
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
                      top->b=1;  step_and_dump_wave(); 
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
  top->s=1; top->a=0; top->b=0;  step_and_dump_wave(); 
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
                      top->b=1;  step_and_dump_wave();
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
            top->a=1; top->b=0;  step_and_dump_wave();
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);
                      top->b=1;  step_and_dump_wave();
  printf("s = %d, a = %d, b = %d, y = %d\n", top->s, top->a, top->b, top->y);

  sim_exit();
}


#include<stdio.h>
#include<stdlib.h>
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

int main(){
  sim_init();
  int i = 5;
  while(i >= 0){
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    step_and_dump_wave();
    printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    i--;
  };
  sim_exit();
  return 0;
}

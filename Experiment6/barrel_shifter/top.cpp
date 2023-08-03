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

  top->din = 0b10101110; top->shamt = 1; top->LorR = 0; top->AorL = 0; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 1; top->LorR = 1; top->AorL = 0; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 1; top->LorR = 0; top->AorL = 1; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 1; top->LorR = 1; top->AorL = 1; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
  top->din = 0b10101110; top->shamt = 2; top->LorR = 0; top->AorL = 0; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 2; top->LorR = 1; top->AorL = 0; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 2; top->LorR = 0; top->AorL = 1; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 2; top->LorR = 1; top->AorL = 1; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
  top->din = 0b10101110; top->shamt = 4; top->LorR = 0; top->AorL = 0; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 4; top->LorR = 1; top->AorL = 0; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 4; top->LorR = 0; top->AorL = 1; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);
                         top->shamt = 4; top->LorR = 1; top->AorL = 1; step_and_dump_wave();
  printf("din = %d, shamt = %d, LorR = %d, AorL = %d, dout = %d\n", top->din, top->shamt, top->LorR, top->AorL, top->dout);

  sim_exit();
}
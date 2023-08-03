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

  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->cin = 0b0; top->pcarry = 0b0; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->cin = 0b1; top->pcarry = 0b0; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->cin = 0b1; top->pcarry = 0b1; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b00000000000000000000000000000001; top->cin = 0b0; top->pcarry = 0b1; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b10000000000000000000000000000001; top->cin = 0b0; top->pcarry = 0b0; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b10000000000000000000000000000001; top->cin = 0b1; top->pcarry = 0b0; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b10000000000000000000000000000001; top->cin = 0b1; top->pcarry = 0b1; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000001; top->b = 0b10000000000000000000000000000001; top->cin = 0b0; top->pcarry = 0b1; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b00000000000000000000000000000000; top->b = 0b00000000000000000000000000000000; top->cin = 0b0; top->pcarry = 0b0; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b01111111111111111111111111111111; top->b = 0b01111111111111111111111111111111; top->cin = 0b0; top->pcarry = 0b1; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b01111111111111111111111111111111; top->b = 0b01111111111111111111111111111111; top->cin = 0b0; top->pcarry = 0b0; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  top->a = 0b01111111111111111111111111111111; top->b = 0b01111111111111111111111111111111; top->cin = 0b1; top->pcarry = 0b1; step_and_dump_wave();
  printf("cin = %d, a = %d, b = %d, pcarry = %d, carry = %d, overflow = %d, zero = %d, result = %d\n", top->cin, top->a, top->b, top->pcarry, top->carry, top->overflow, top->zero, top->result);
  sim_exit();
}
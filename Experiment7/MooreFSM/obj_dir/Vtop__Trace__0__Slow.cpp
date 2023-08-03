// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"in", false,-1);
    tracep->declBit(c+3,"reset", false,-1);
    tracep->declBit(c+4,"out", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+1,"clk", false,-1);
    tracep->declBit(c+2,"in", false,-1);
    tracep->declBit(c+3,"reset", false,-1);
    tracep->declBit(c+4,"out", false,-1);
    tracep->declBus(c+7,"S0", false,-1, 3,0);
    tracep->declBus(c+8,"S1", false,-1, 3,0);
    tracep->declBus(c+9,"S2", false,-1, 3,0);
    tracep->declBus(c+10,"S3", false,-1, 3,0);
    tracep->declBus(c+11,"S4", false,-1, 3,0);
    tracep->declBus(c+12,"S5", false,-1, 3,0);
    tracep->declBus(c+13,"S6", false,-1, 3,0);
    tracep->declBus(c+14,"S7", false,-1, 3,0);
    tracep->declBus(c+15,"S8", false,-1, 3,0);
    tracep->declBus(c+5,"state_din", false,-1, 3,0);
    tracep->declBus(c+6,"state_dout", false,-1, 3,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->clk));
    bufp->fullBit(oldp+2,(vlSelf->in));
    bufp->fullBit(oldp+3,(vlSelf->reset));
    bufp->fullBit(oldp+4,(vlSelf->out));
    bufp->fullCData(oldp+5,(vlSelf->top__DOT__state_din),4);
    bufp->fullCData(oldp+6,(vlSelf->top__DOT__state_dout),4);
    bufp->fullCData(oldp+7,(0U),4);
    bufp->fullCData(oldp+8,(1U),4);
    bufp->fullCData(oldp+9,(2U),4);
    bufp->fullCData(oldp+10,(3U),4);
    bufp->fullCData(oldp+11,(4U),4);
    bufp->fullCData(oldp+12,(5U),4);
    bufp->fullCData(oldp+13,(6U),4);
    bufp->fullCData(oldp+14,(7U),4);
    bufp->fullCData(oldp+15,(8U),4);
}

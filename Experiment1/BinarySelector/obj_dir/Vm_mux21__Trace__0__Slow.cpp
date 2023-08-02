// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vm_mux21__Syms.h"


VL_ATTR_COLD void Vm_mux21___024root__trace_init_sub__TOP__0(Vm_mux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_mux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_mux21___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"a", false,-1);
    tracep->declBit(c+2,"b", false,-1);
    tracep->declBit(c+3,"s", false,-1);
    tracep->declBit(c+4,"y", false,-1);
    tracep->pushNamePrefix("m_mux21 ");
    tracep->declBit(c+1,"a", false,-1);
    tracep->declBit(c+2,"b", false,-1);
    tracep->declBit(c+3,"s", false,-1);
    tracep->declBit(c+4,"y", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vm_mux21___024root__trace_init_top(Vm_mux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_mux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_mux21___024root__trace_init_top\n"); );
    // Body
    Vm_mux21___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vm_mux21___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vm_mux21___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vm_mux21___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vm_mux21___024root__trace_register(Vm_mux21___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_mux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_mux21___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vm_mux21___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vm_mux21___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vm_mux21___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vm_mux21___024root__trace_full_sub_0(Vm_mux21___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vm_mux21___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_mux21___024root__trace_full_top_0\n"); );
    // Init
    Vm_mux21___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vm_mux21___024root*>(voidSelf);
    Vm_mux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vm_mux21___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vm_mux21___024root__trace_full_sub_0(Vm_mux21___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vm_mux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vm_mux21___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->a));
    bufp->fullBit(oldp+2,(vlSelf->b));
    bufp->fullBit(oldp+3,(vlSelf->s));
    bufp->fullBit(oldp+4,(vlSelf->y));
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((((IData)(vlSelf->AorL) 
                                         != (IData)(vlSelf->__Vtrigrprev__TOP__AorL)) 
                                        | ((IData)(vlSelf->LorR) 
                                           != (IData)(vlSelf->__Vtrigrprev__TOP__LorR))) 
                                       | ((IData)(vlSelf->din) 
                                          != (IData)(vlSelf->__Vtrigrprev__TOP__din))) 
                                      | ((IData)(vlSelf->shamt) 
                                         != (IData)(vlSelf->__Vtrigrprev__TOP__shamt)));
    vlSelf->__Vtrigrprev__TOP__AorL = vlSelf->AorL;
    vlSelf->__Vtrigrprev__TOP__LorR = vlSelf->LorR;
    vlSelf->__Vtrigrprev__TOP__din = vlSelf->din;
    vlSelf->__Vtrigrprev__TOP__shamt = vlSelf->shamt;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.at(0U) = 1U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

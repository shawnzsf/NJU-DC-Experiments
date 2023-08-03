// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ __Vdly__data_out;
    __Vdly__data_out = 0;
    CData/*2:0*/ __Vdly__top__DOT__cnt;
    __Vdly__top__DOT__cnt = 0;
    // Body
    __Vdly__top__DOT__cnt = vlSelf->top__DOT__cnt;
    __Vdly__data_out = vlSelf->data_out;
    if ((4U & (IData)(vlSelf->sel))) {
        if ((2U & (IData)(vlSelf->sel))) {
            __Vdly__data_out = ((1U & (IData)(vlSelf->sel))
                                 ? ((0xfeU & ((IData)(vlSelf->data_out) 
                                              << 1U)) 
                                    | (1U & ((IData)(vlSelf->data_out) 
                                             >> 7U)))
                                 : ((0x80U & ((IData)(vlSelf->data_out) 
                                              << 7U)) 
                                    | (0x7fU & ((IData)(vlSelf->data_out) 
                                                >> 1U))));
        } else if ((1U & (IData)(vlSelf->sel))) {
            if ((7U == (IData)(vlSelf->top__DOT__cnt))) {
                __Vdly__data_out = (((~ ((IData)(1U) 
                                         << (7U & ((IData)(7U) 
                                                   - (IData)(vlSelf->top__DOT__cnt))))) 
                                     & (IData)(__Vdly__data_out)) 
                                    | (0xffU & ((IData)(vlSelf->cin) 
                                                << 
                                                (7U 
                                                 & ((IData)(7U) 
                                                    - (IData)(vlSelf->top__DOT__cnt))))));
                __Vdly__data_out = ((1U & (IData)(__Vdly__data_out)) 
                                    | ((IData)(vlSelf->top__DOT__mem) 
                                       << 1U));
                __Vdly__top__DOT__cnt = 0U;
            } else {
                vlSelf->top__DOT____Vlvbound_h71d00fd5__0 
                    = vlSelf->cin;
                if ((6U >= (7U & ((IData)(7U) - (IData)(vlSelf->top__DOT__cnt))))) {
                    vlSelf->top__DOT__mem = (((~ ((IData)(1U) 
                                                  << 
                                                  (7U 
                                                   & ((IData)(7U) 
                                                      - (IData)(vlSelf->top__DOT__cnt))))) 
                                              & (IData)(vlSelf->top__DOT__mem)) 
                                             | (0x7fU 
                                                & ((IData)(vlSelf->top__DOT____Vlvbound_h71d00fd5__0) 
                                                   << 
                                                   (7U 
                                                    & ((IData)(7U) 
                                                       - (IData)(vlSelf->top__DOT__cnt))))));
                }
                __Vdly__top__DOT__cnt = (7U & ((IData)(1U) 
                                               + (IData)(vlSelf->top__DOT__cnt)));
            }
        } else {
            __Vdly__data_out = ((0x80U & (IData)(vlSelf->data_out)) 
                                | (0x7fU & ((IData)(vlSelf->data_out) 
                                            >> 1U)));
        }
    } else {
        __Vdly__data_out = ((2U & (IData)(vlSelf->sel))
                             ? ((1U & (IData)(vlSelf->sel))
                                 ? (0xfeU & ((IData)(vlSelf->data_out) 
                                             << 1U))
                                 : (0x7fU & ((IData)(vlSelf->data_out) 
                                             >> 1U)))
                             : ((1U & (IData)(vlSelf->sel))
                                 ? (IData)(vlSelf->data_in)
                                 : 0U));
    }
    vlSelf->data_out = __Vdly__data_out;
    vlSelf->top__DOT__cnt = __Vdly__top__DOT__cnt;
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top.v", 2, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top.v", 2, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->sel & 0xf8U))) {
        Verilated::overWidthError("sel");}
    if (VL_UNLIKELY((vlSelf->cin & 0xfeU))) {
        Verilated::overWidthError("cin");}
}
#endif  // VL_DEBUG

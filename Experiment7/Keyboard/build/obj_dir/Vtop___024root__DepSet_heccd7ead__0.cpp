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
    CData/*2:0*/ __Vdly__top__DOT__ps2_clk_sync;
    __Vdly__top__DOT__ps2_clk_sync = 0;
    CData/*3:0*/ __Vdly__top__DOT__count;
    __Vdly__top__DOT__count = 0;
    // Body
    __Vdly__top__DOT__ps2_clk_sync = vlSelf->top__DOT__ps2_clk_sync;
    __Vdly__top__DOT__count = vlSelf->top__DOT__count;
    __Vdly__top__DOT__ps2_clk_sync = ((6U & ((IData)(vlSelf->top__DOT__ps2_clk_sync) 
                                             << 1U)) 
                                      | (IData)(vlSelf->ps2_clk));
    if (vlSelf->resetn) {
        if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->top__DOT__count))) {
                if (VL_UNLIKELY((((~ (IData)(vlSelf->top__DOT__buffer)) 
                                  & (IData)(vlSelf->ps2_data)) 
                                 & VL_REDXOR_32((0x1ffU 
                                                 & ((IData)(vlSelf->top__DOT__buffer) 
                                                    >> 1U)))))) {
                    VL_WRITEF("receive %x\n",8,(0xffU 
                                                & ((IData)(vlSelf->top__DOT__buffer) 
                                                   >> 1U)));
                    if (VL_UNLIKELY((0x100U & (IData)(vlSelf->top__DOT__buffer)))) {
                        VL_WRITEF("ASCII 0\n");
                        vlSelf->seg3 = 0xffU;
                        vlSelf->seg2 = 0xffU;
                        vlSelf->seg1 = 0xffU;
                        vlSelf->seg0 = 0xffU;
                    } else if ((0x80U & (IData)(vlSelf->top__DOT__buffer))) {
                        if (VL_UNLIKELY((0x40U & (IData)(vlSelf->top__DOT__buffer)))) {
                            VL_WRITEF("ASCII 0\n");
                            vlSelf->seg3 = 0xffU;
                            vlSelf->seg2 = 0xffU;
                            vlSelf->seg1 = 0xffU;
                            vlSelf->seg0 = 0xffU;
                        } else if (VL_UNLIKELY((0x20U 
                                                & (IData)(vlSelf->top__DOT__buffer)))) {
                            VL_WRITEF("ASCII 0\n");
                            vlSelf->seg3 = 0xffU;
                            vlSelf->seg2 = 0xffU;
                            vlSelf->seg1 = 0xffU;
                            vlSelf->seg0 = 0xffU;
                        } else if ((0x10U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                                if (VL_UNLIKELY((4U 
                                                 & (IData)(vlSelf->top__DOT__buffer)))) {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          80\n");
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 3U;
                                    vlSelf->top__DOT__state_dout = 0U;
                                    if ((0U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                }
                            } else if (VL_LIKELY((4U 
                                                  & (IData)(vlSelf->top__DOT__buffer)))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          76\n");
                                    vlSelf->seg3 = 0x1fU;
                                    vlSelf->seg2 = 0x41U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 0xcU;
                                    if ((0xcU == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                }
                            } else {
                                VL_WRITEF("ASCII 0\n");
                                vlSelf->seg3 = 0xffU;
                                vlSelf->seg2 = 0xffU;
                                vlSelf->seg1 = 0xffU;
                                vlSelf->seg0 = 0xffU;
                            }
                        } else if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                } else {
                                    VL_WRITEF("ASCII          57\n");
                                    vlSelf->seg3 = 0x49U;
                                    vlSelf->seg2 = 0x1fU;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 1U;
                                    if ((1U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                VL_WRITEF("ASCII          48\n");
                                vlSelf->seg3 = 0x99U;
                                vlSelf->seg2 = 1U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 2U;
                                if ((2U == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            } else {
                                VL_WRITEF("ASCII          79\n");
                                vlSelf->seg3 = 0x1fU;
                                vlSelf->seg2 = 9U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 0xfU;
                                if ((0xfU == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            }
                        } else if (VL_LIKELY((4U & (IData)(vlSelf->top__DOT__buffer)))) {
                            if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                VL_WRITEF("ASCII          73\n");
                                vlSelf->seg3 = 0x1fU;
                                vlSelf->seg2 = 0xdU;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 9U;
                                if ((9U == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            } else {
                                VL_WRITEF("ASCII          75\n");
                                vlSelf->seg3 = 0x1fU;
                                vlSelf->seg2 = 0x49U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 0xbU;
                                if ((0xbU == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            }
                        } else {
                            VL_WRITEF("ASCII 0\n");
                            vlSelf->seg3 = 0xffU;
                            vlSelf->seg2 = 0xffU;
                            vlSelf->seg1 = 0xffU;
                            vlSelf->seg0 = 0xffU;
                        }
                    } else if ((0x40U & (IData)(vlSelf->top__DOT__buffer))) {
                        if ((0x20U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((0x10U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                                    if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                        if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                            VL_WRITEF("ASCII 0\n");
                                            vlSelf->seg3 = 0xffU;
                                            vlSelf->seg2 = 0xffU;
                                            vlSelf->seg1 = 0xffU;
                                            vlSelf->seg0 = 0xffU;
                                        } else {
                                            VL_WRITEF("ASCII          56\n");
                                            vlSelf->seg3 = 0x49U;
                                            vlSelf->seg2 = 0x41U;
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->top__DOT__cnt)));
                                            vlSelf->top__DOT__state_dout = 0U;
                                            if ((0U 
                                                 == (IData)(vlSelf->top__DOT__state_din))) {
                                                vlSelf->top__DOT__cnt 
                                                    = 
                                                    (0xffU 
                                                     & ((IData)(vlSelf->top__DOT__cnt) 
                                                        - (IData)(1U)));
                                            }
                                        }
                                    } else if ((2U 
                                                & (IData)(vlSelf->top__DOT__buffer))) {
                                        VL_WRITEF("ASCII          55\n");
                                        vlSelf->seg3 = 0x49U;
                                        vlSelf->seg2 = 0x49U;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 0xfU;
                                        if ((0xfU == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    } else {
                                        VL_WRITEF("ASCII          85\n");
                                        vlSelf->seg3 = 1U;
                                        vlSelf->seg2 = 0x49U;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 5U;
                                        if ((5U == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    }
                                } else if (VL_LIKELY(
                                                     (4U 
                                                      & (IData)(vlSelf->top__DOT__buffer)))) {
                                    if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                        VL_WRITEF("ASCII          74\n");
                                        vlSelf->seg3 = 0x1fU;
                                        vlSelf->seg2 = 0x99U;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 0xaU;
                                        if ((0xaU == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    } else {
                                        VL_WRITEF("ASCII          77\n");
                                        vlSelf->seg3 = 0x1fU;
                                        vlSelf->seg2 = 0x1fU;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 0xdU;
                                        if ((0xdU == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    }
                                } else {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                }
                            } else if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                    if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                        VL_WRITEF("ASCII 0\n");
                                        vlSelf->seg3 = 0xffU;
                                        vlSelf->seg2 = 0xffU;
                                        vlSelf->seg1 = 0xffU;
                                        vlSelf->seg0 = 0xffU;
                                    } else {
                                        VL_WRITEF("ASCII          54\n");
                                        vlSelf->seg3 = 0x49U;
                                        vlSelf->seg2 = 0x99U;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 0xeU;
                                        if ((0xeU == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          89\n");
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 9U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 6U;
                                    if ((6U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII          71\n");
                                    vlSelf->seg3 = 0x1fU;
                                    vlSelf->seg2 = 0x9fU;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 7U;
                                    if ((7U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          72\n");
                                    vlSelf->seg3 = 0x1fU;
                                    vlSelf->seg2 = 0x25U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 8U;
                                    if ((8U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII          66\n");
                                    vlSelf->seg3 = 0x41U;
                                    vlSelf->seg2 = 0x41U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 2U;
                                    if ((2U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                VL_WRITEF("ASCII          78\n");
                                vlSelf->seg3 = 0x1fU;
                                vlSelf->seg2 = 1U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 0xeU;
                                if ((0xeU == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            } else {
                                VL_WRITEF("ASCII 0\n");
                                vlSelf->seg3 = 0xffU;
                                vlSelf->seg2 = 0xffU;
                                vlSelf->seg1 = 0xffU;
                                vlSelf->seg0 = 0xffU;
                            }
                        } else if ((0x10U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                    if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                        VL_WRITEF("ASCII 0\n");
                                        vlSelf->seg3 = 0xffU;
                                        vlSelf->seg2 = 0xffU;
                                        vlSelf->seg1 = 0xffU;
                                        vlSelf->seg0 = 0xffU;
                                    } else {
                                        VL_WRITEF("ASCII          53\n");
                                        vlSelf->seg3 = 0x49U;
                                        vlSelf->seg2 = 0xdU;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 0xdU;
                                        if ((0xdU == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          82\n");
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 0x25U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 2U;
                                    if ((2U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII          84\n");
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 0x99U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 4U;
                                    if ((4U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if (VL_LIKELY((4U 
                                                  & (IData)(vlSelf->top__DOT__buffer)))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          70\n");
                                    vlSelf->seg3 = 0x1fU;
                                    vlSelf->seg2 = 3U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 6U;
                                    if ((6U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII          86\n");
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 0x41U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 6U;
                                    if ((6U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else {
                                VL_WRITEF("ASCII 0\n");
                                vlSelf->seg3 = 0xffU;
                                vlSelf->seg2 = 0xffU;
                                vlSelf->seg1 = 0xffU;
                                vlSelf->seg0 = 0xffU;
                            }
                        } else if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                } else {
                                    VL_WRITEF("ASCII          51\n");
                                    vlSelf->seg3 = 0x49U;
                                    vlSelf->seg2 = 0x9fU;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 0xaU;
                                    if ((0xaU == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                VL_WRITEF("ASCII          52\n");
                                vlSelf->seg3 = 0x49U;
                                vlSelf->seg2 = 0x25U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 0xbU;
                                if ((0xcU == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            } else {
                                VL_WRITEF("ASCII          69\n");
                                vlSelf->seg3 = 0x41U;
                                vlSelf->seg2 = 9U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 5U;
                                if ((5U == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            }
                        } else if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                VL_WRITEF("ASCII          68\n");
                                vlSelf->seg3 = 0x41U;
                                vlSelf->seg2 = 1U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 4U;
                                if ((4U == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            } else {
                                VL_WRITEF("ASCII          88\n");
                                vlSelf->seg3 = 1U;
                                vlSelf->seg2 = 1U;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 6U;
                                if ((6U == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            }
                        } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                            VL_WRITEF("ASCII          67\n");
                            vlSelf->seg3 = 0x41U;
                            vlSelf->seg2 = 0x1fU;
                            vlSelf->top__DOT__cnt = 
                                (0xffU & ((IData)(1U) 
                                          + (IData)(vlSelf->top__DOT__cnt)));
                            vlSelf->top__DOT__state_dout = 3U;
                            if ((3U == (IData)(vlSelf->top__DOT__state_din))) {
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(vlSelf->top__DOT__cnt) 
                                                - (IData)(1U)));
                            }
                        } else {
                            VL_WRITEF("ASCII 0\n");
                            vlSelf->seg3 = 0xffU;
                            vlSelf->seg2 = 0xffU;
                            vlSelf->seg1 = 0xffU;
                            vlSelf->seg0 = 0xffU;
                        }
                    } else if (VL_LIKELY((0x20U & (IData)(vlSelf->top__DOT__buffer)))) {
                        if ((0x10U & (IData)(vlSelf->top__DOT__buffer))) {
                            if ((8U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                    if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                        VL_WRITEF("ASCII 0\n");
                                        vlSelf->seg3 = 0xffU;
                                        vlSelf->seg2 = 0xffU;
                                        vlSelf->seg1 = 0xffU;
                                        vlSelf->seg0 = 0xffU;
                                    } else {
                                        VL_WRITEF("ASCII          50\n");
                                        vlSelf->seg3 = 0x49U;
                                        vlSelf->seg2 = 3U;
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlSelf->top__DOT__cnt)));
                                        vlSelf->top__DOT__state_dout = 9U;
                                        if ((9U == (IData)(vlSelf->top__DOT__state_din))) {
                                            vlSelf->top__DOT__cnt 
                                                = (0xffU 
                                                   & ((IData)(vlSelf->top__DOT__cnt) 
                                                      - (IData)(1U)));
                                        }
                                    }
                                } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          87\n");
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 0x1fU;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 6U;
                                    if ((6U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII          65\n");
                                    vlSelf->seg3 = 0x41U;
                                    vlSelf->seg2 = 0x49U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 1U;
                                    if ((1U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if (VL_LIKELY((4U 
                                                  & (IData)(vlSelf->top__DOT__buffer)))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII          83\n");
                                    vlSelf->seg3 = 1U;
                                    vlSelf->seg2 = 0xdU;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 3U;
                                    if ((3U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    VL_WRITEF("ASCII          90\n");
                                    vlSelf->seg3 = 9U;
                                    vlSelf->seg2 = 3U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 7U;
                                    if ((7U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else {
                                VL_WRITEF("ASCII 0\n");
                                vlSelf->seg3 = 0xffU;
                                vlSelf->seg2 = 0xffU;
                                vlSelf->seg1 = 0xffU;
                                vlSelf->seg0 = 0xffU;
                            }
                        } else if (VL_LIKELY((8U & (IData)(vlSelf->top__DOT__buffer)))) {
                            if ((4U & (IData)(vlSelf->top__DOT__buffer))) {
                                if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                    VL_WRITEF("ASCII 0\n");
                                    vlSelf->seg3 = 0xffU;
                                    vlSelf->seg2 = 0xffU;
                                    vlSelf->seg1 = 0xffU;
                                    vlSelf->seg0 = 0xffU;
                                } else {
                                    VL_WRITEF("ASCII          49\n");
                                    vlSelf->seg3 = 0x99U;
                                    vlSelf->seg2 = 9U;
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->top__DOT__cnt)));
                                    vlSelf->top__DOT__state_dout = 8U;
                                    if ((8U == (IData)(vlSelf->top__DOT__state_din))) {
                                        vlSelf->top__DOT__cnt 
                                            = (0xffU 
                                               & ((IData)(vlSelf->top__DOT__cnt) 
                                                  - (IData)(1U)));
                                    }
                                }
                            } else if ((2U & (IData)(vlSelf->top__DOT__buffer))) {
                                VL_WRITEF("ASCII          81\n");
                                vlSelf->seg3 = 1U;
                                vlSelf->seg2 = 0x9fU;
                                vlSelf->top__DOT__cnt 
                                    = (0xffU & ((IData)(1U) 
                                                + (IData)(vlSelf->top__DOT__cnt)));
                                vlSelf->top__DOT__state_dout = 1U;
                                if ((1U == (IData)(vlSelf->top__DOT__state_din))) {
                                    vlSelf->top__DOT__cnt 
                                        = (0xffU & 
                                           ((IData)(vlSelf->top__DOT__cnt) 
                                            - (IData)(1U)));
                                }
                            } else {
                                VL_WRITEF("ASCII 0\n");
                                vlSelf->seg3 = 0xffU;
                                vlSelf->seg2 = 0xffU;
                                vlSelf->seg1 = 0xffU;
                                vlSelf->seg0 = 0xffU;
                            }
                        } else {
                            VL_WRITEF("ASCII 0\n");
                            vlSelf->seg3 = 0xffU;
                            vlSelf->seg2 = 0xffU;
                            vlSelf->seg1 = 0xffU;
                            vlSelf->seg0 = 0xffU;
                        }
                    } else {
                        VL_WRITEF("ASCII 0\n");
                        vlSelf->seg3 = 0xffU;
                        vlSelf->seg2 = 0xffU;
                        vlSelf->seg1 = 0xffU;
                        vlSelf->seg0 = 0xffU;
                    }
                    vlSelf->seg1 = ((0x100U & (IData)(vlSelf->top__DOT__buffer))
                                     ? ((0x80U & (IData)(vlSelf->top__DOT__buffer))
                                         ? ((0x40U 
                                             & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x71U
                                                 : 0x61U)
                                             : ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x85U
                                                 : 0x63U))
                                         : ((0x40U 
                                             & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0xc1U
                                                 : 0x11U)
                                             : ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 9U
                                                 : 1U)))
                                     : ((0x80U & (IData)(vlSelf->top__DOT__buffer))
                                         ? ((0x40U 
                                             & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x1fU
                                                 : 0x41U)
                                             : ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x49U
                                                 : 0x99U))
                                         : ((0x40U 
                                             & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0xdU
                                                 : 0x25U)
                                             : ((0x20U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x9fU
                                                 : 3U))));
                    vlSelf->seg0 = ((0x10U & (IData)(vlSelf->top__DOT__buffer))
                                     ? ((8U & (IData)(vlSelf->top__DOT__buffer))
                                         ? ((4U & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x71U
                                                 : 0x61U)
                                             : ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x85U
                                                 : 0x63U))
                                         : ((4U & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0xc1U
                                                 : 0x11U)
                                             : ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 9U
                                                 : 1U)))
                                     : ((8U & (IData)(vlSelf->top__DOT__buffer))
                                         ? ((4U & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x1fU
                                                 : 0x41U)
                                             : ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x49U
                                                 : 0x99U))
                                         : ((4U & (IData)(vlSelf->top__DOT__buffer))
                                             ? ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0xdU
                                                 : 0x25U)
                                             : ((2U 
                                                 & (IData)(vlSelf->top__DOT__buffer))
                                                 ? 0x9fU
                                                 : 3U))));
                    vlSelf->seg4 = ((8U & (IData)(vlSelf->top__DOT__cnt))
                                     ? ((4U & (IData)(vlSelf->top__DOT__cnt))
                                         ? ((2U & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x71U
                                                 : 0x61U)
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x85U
                                                 : 0x63U))
                                         : ((2U & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0xc1U
                                                 : 0x11U)
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 9U
                                                 : 1U)))
                                     : ((4U & (IData)(vlSelf->top__DOT__cnt))
                                         ? ((2U & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x1fU
                                                 : 0x41U)
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x49U
                                                 : 0x99U))
                                         : ((2U & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0xdU
                                                 : 0x25U)
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x9fU
                                                 : 3U))));
                    vlSelf->seg5 = ((0x80U & (IData)(vlSelf->top__DOT__cnt))
                                     ? ((0x40U & (IData)(vlSelf->top__DOT__cnt))
                                         ? ((0x20U 
                                             & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x71U
                                                 : 0x61U)
                                             : ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x85U
                                                 : 0x63U))
                                         : ((0x20U 
                                             & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0xc1U
                                                 : 0x11U)
                                             : ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 9U
                                                 : 1U)))
                                     : ((0x40U & (IData)(vlSelf->top__DOT__cnt))
                                         ? ((0x20U 
                                             & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x1fU
                                                 : 0x41U)
                                             : ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x49U
                                                 : 0x99U))
                                         : ((0x20U 
                                             & (IData)(vlSelf->top__DOT__cnt))
                                             ? ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0xdU
                                                 : 0x25U)
                                             : ((0x10U 
                                                 & (IData)(vlSelf->top__DOT__cnt))
                                                 ? 0x9fU
                                                 : 3U))));
                }
                __Vdly__top__DOT__count = 0U;
            } else {
                vlSelf->top__DOT____Vlvbound_h1a91ade8__0 
                    = vlSelf->ps2_data;
                if (VL_LIKELY((9U >= (IData)(vlSelf->top__DOT__count)))) {
                    vlSelf->top__DOT__buffer = (((~ 
                                                  ((IData)(1U) 
                                                   << (IData)(vlSelf->top__DOT__count))) 
                                                 & (IData)(vlSelf->top__DOT__buffer)) 
                                                | (0x3ffU 
                                                   & ((IData)(vlSelf->top__DOT____Vlvbound_h1a91ade8__0) 
                                                      << (IData)(vlSelf->top__DOT__count))));
                }
                __Vdly__top__DOT__count = (0xfU & ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__count)));
            }
        }
    } else {
        __Vdly__top__DOT__count = 0U;
    }
    vlSelf->top__DOT__state_din = vlSelf->top__DOT__state_dout;
    vlSelf->top__DOT__ps2_clk_sync = __Vdly__top__DOT__ps2_clk_sync;
    vlSelf->top__DOT__count = __Vdly__top__DOT__count;
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
                    VL_FATAL_MT("/home/shawnzhang/ysyx-workbench/nvboard/Keyboard/vsrc/top.v", 1, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/shawnzhang/ysyx-workbench/nvboard/Keyboard/vsrc/top.v", 1, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->resetn & 0xfeU))) {
        Verilated::overWidthError("resetn");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vm_mux21.h"
#include "Vm_mux21__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vm_mux21::Vm_mux21(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vm_mux21__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , s{vlSymsp->TOP.s}
    , y{vlSymsp->TOP.y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vm_mux21::Vm_mux21(const char* _vcname__)
    : Vm_mux21(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vm_mux21::~Vm_mux21() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vm_mux21___024root___eval_debug_assertions(Vm_mux21___024root* vlSelf);
#endif  // VL_DEBUG
void Vm_mux21___024root___eval_static(Vm_mux21___024root* vlSelf);
void Vm_mux21___024root___eval_initial(Vm_mux21___024root* vlSelf);
void Vm_mux21___024root___eval_settle(Vm_mux21___024root* vlSelf);
void Vm_mux21___024root___eval(Vm_mux21___024root* vlSelf);

void Vm_mux21::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vm_mux21::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vm_mux21___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vm_mux21___024root___eval_static(&(vlSymsp->TOP));
        Vm_mux21___024root___eval_initial(&(vlSymsp->TOP));
        Vm_mux21___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vm_mux21___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vm_mux21::eventsPending() { return false; }

uint64_t Vm_mux21::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vm_mux21::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vm_mux21___024root___eval_final(Vm_mux21___024root* vlSelf);

VL_ATTR_COLD void Vm_mux21::final() {
    Vm_mux21___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vm_mux21::hierName() const { return vlSymsp->name(); }
const char* Vm_mux21::modelName() const { return "Vm_mux21"; }
unsigned Vm_mux21::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vm_mux21::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vm_mux21___024root__trace_init_top(Vm_mux21___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vm_mux21___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vm_mux21___024root*>(voidSelf);
    Vm_mux21__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vm_mux21___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vm_mux21___024root__trace_register(Vm_mux21___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vm_mux21::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vm_mux21::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vm_mux21___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}

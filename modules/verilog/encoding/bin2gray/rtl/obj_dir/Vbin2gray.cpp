// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vbin2gray__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vbin2gray::Vbin2gray(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vbin2gray__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vbin2gray::Vbin2gray(const char* _vcname__)
    : Vbin2gray(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vbin2gray::~Vbin2gray() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vbin2gray___024root___eval_debug_assertions(Vbin2gray___024root* vlSelf);
#endif  // VL_DEBUG
void Vbin2gray___024root___eval_static(Vbin2gray___024root* vlSelf);
void Vbin2gray___024root___eval_initial(Vbin2gray___024root* vlSelf);
void Vbin2gray___024root___eval_settle(Vbin2gray___024root* vlSelf);
void Vbin2gray___024root___eval(Vbin2gray___024root* vlSelf);

void Vbin2gray::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbin2gray::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vbin2gray___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vbin2gray___024root___eval_static(&(vlSymsp->TOP));
        Vbin2gray___024root___eval_initial(&(vlSymsp->TOP));
        Vbin2gray___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vbin2gray___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vbin2gray::eval_end_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+eval_end_step Vbin2gray::eval_end_step\n"); );
#ifdef VM_TRACE
    // Tracing
    if (VL_UNLIKELY(vlSymsp->__Vm_dumping)) vlSymsp->_traceDump();
#endif  // VM_TRACE
}

//============================================================
// Events and timing
bool Vbin2gray::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vbin2gray::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vbin2gray::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vbin2gray___024root___eval_final(Vbin2gray___024root* vlSelf);

VL_ATTR_COLD void Vbin2gray::final() {
    Vbin2gray___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vbin2gray::hierName() const { return vlSymsp->name(); }
const char* Vbin2gray::modelName() const { return "Vbin2gray"; }
unsigned Vbin2gray::threads() const { return 1; }
void Vbin2gray::prepareClone() const { contextp()->prepareClone(); }
void Vbin2gray::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vbin2gray::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vbin2gray___024root__trace_decl_types(VerilatedVcd* tracep);

void Vbin2gray___024root__trace_init_top(Vbin2gray___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbin2gray___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vbin2gray___024root*>(voidSelf);
    Vbin2gray__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vbin2gray___024root__trace_decl_types(tracep);
    Vbin2gray___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vbin2gray___024root__trace_register(Vbin2gray___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vbin2gray::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vbin2gray::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vbin2gray___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}

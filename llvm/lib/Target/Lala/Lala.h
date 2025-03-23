#ifndef LLVM_LIB_TARGET_LALA_LALA_H
#define LLVM_LIB_TARGET_LALA_LALA_H

#include "llvm/Support/raw_ostream.h"

#define SIM_DUMP(Color)                                 \
{                                                       \
    llvm::errs().changeColor(Color) << "lala: "         \
    << __func__ << "\n\t\t" << __FILE__                 \
    << ":" << __LINE__ << "\n";                         \
    llvm::errs().changeColor(llvm::raw_ostream::BLACK); \
}

#define SIM_DUMP_RED SIM_DUMP(llvm::raw_ostream::RED)
#define SIM_DUMP_GREEN SIM_DUMP(llvm::raw_ostream::GREEN)
#define SIM_DUMP_YELLOW SIM_DUMP(llvm::raw_ostream::YELLOW)
#define SIM_DUMP_CYAN SIM_DUMP(llvm::raw_ostream::CYAN)
#define SIM_DUMP_MAGENTA SIM_DUMP(llvm::raw_ostream::MAGENTA)

#endif // LLVM_LIB_TARGET_LALA_LALA_H
#ifndef LLVM_LIB_TARGET_LALA_LALA_H
#define LLVM_LIB_TARGET_LALA_LALA_H

#include "MCTargetDesc/LalaMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"

#define SIM_DUMP(Color)                                 \
{                                                       \
    llvm::errs().changeColor(Color) << "lala: "         \
    << __func__ << "\n\t\t" << __FILE__                 \
    << ":" << __LINE__ << "\n";                         \
    llvm::errs().changeColor(llvm::raw_ostream::BLACK); \
}

#define Lala_DUMP_RED SIM_DUMP(llvm::raw_ostream::RED)
#define Lala_DUMP_GREEN SIM_DUMP(llvm::raw_ostream::GREEN)
#define Lala_DUMP_YELLOW SIM_DUMP(llvm::raw_ostream::YELLOW)
#define Lala_DUMP_CYAN SIM_DUMP(llvm::raw_ostream::CYAN)
#define Lala_DUMP_MAGENTA SIM_DUMP(llvm::raw_ostream::MAGENTA)
#define Lala_DUMP_WHITE SIM_DUMP(llvm::raw_ostream::WHITE)

#endif // LLVM_LIB_TARGET_LALA_LALA_H
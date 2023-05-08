#ifndef OPFUNCS_6502_H
#define OPFUNCS_6502_H

#ifdef __cplusplus
extern "C" {
#endif

#include <cpu6502.h>

void XXX(struct cpu6502* cpu, struct instruction* ins);
void ADC(struct cpu6502* cpu, struct instruction* ins);
void AND(struct cpu6502* cpu, struct instruction* ins);
void ASL(struct cpu6502* cpu, struct instruction* ins);
void BCC(struct cpu6502* cpu, struct instruction* ins);
void BCS(struct cpu6502* cpu, struct instruction* ins);
void BEQ(struct cpu6502* cpu, struct instruction* ins);
void BMI(struct cpu6502* cpu, struct instruction* ins);
void BNE(struct cpu6502* cpu, struct instruction* ins);
void BPL(struct cpu6502* cpu, struct instruction* ins);
void BVC(struct cpu6502* cpu, struct instruction* ins);
void BVS(struct cpu6502* cpu, struct instruction* ins);
void BIT(struct cpu6502* cpu, struct instruction* ins);
void BRK(struct cpu6502* cpu, struct instruction* ins);
void CLC(struct cpu6502* cpu, struct instruction* ins);
void CLD(struct cpu6502* cpu, struct instruction* ins);
void CLI(struct cpu6502* cpu, struct instruction* ins);
void CLV(struct cpu6502* cpu, struct instruction* ins);
void NOP(struct cpu6502* cpu, struct instruction* ins);
void PHA(struct cpu6502* cpu, struct instruction* ins);
void PLA(struct cpu6502* cpu, struct instruction* ins);
void PHP(struct cpu6502* cpu, struct instruction* ins);
void PLP(struct cpu6502* cpu, struct instruction* ins);
void RTI(struct cpu6502* cpu, struct instruction* ins);
void RTS(struct cpu6502* cpu, struct instruction* ins);
void SEC(struct cpu6502* cpu, struct instruction* ins);
void SED(struct cpu6502* cpu, struct instruction* ins);
void SEI(struct cpu6502* cpu, struct instruction* ins);
void TAX(struct cpu6502* cpu, struct instruction* ins);
void TXA(struct cpu6502* cpu, struct instruction* ins);
void TAY(struct cpu6502* cpu, struct instruction* ins);
void TYA(struct cpu6502* cpu, struct instruction* ins);
void TSX(struct cpu6502* cpu, struct instruction* ins);
void TXS(struct cpu6502* cpu, struct instruction* ins);
void CMP(struct cpu6502* cpu, struct instruction* ins);
void CPX(struct cpu6502* cpu, struct instruction* ins);
void CPY(struct cpu6502* cpu, struct instruction* ins);
void DEC(struct cpu6502* cpu, struct instruction* ins);
void DEX(struct cpu6502* cpu, struct instruction* ins);
void DEY(struct cpu6502* cpu, struct instruction* ins);
void INX(struct cpu6502* cpu, struct instruction* ins);
void INY(struct cpu6502* cpu, struct instruction* ins);
void EOR(struct cpu6502* cpu, struct instruction* ins);
void INC(struct cpu6502* cpu, struct instruction* ins);
void JMP(struct cpu6502* cpu, struct instruction* ins);
void JSR(struct cpu6502* cpu, struct instruction* ins);
void LDA(struct cpu6502* cpu, struct instruction* ins);
void LDX(struct cpu6502* cpu, struct instruction* ins);
void LDY(struct cpu6502* cpu, struct instruction* ins);
void LSR(struct cpu6502* cpu, struct instruction* ins);
void ORA(struct cpu6502* cpu, struct instruction* ins);
void ROL(struct cpu6502* cpu, struct instruction* ins);
void ROR(struct cpu6502* cpu, struct instruction* ins);
void SBC(struct cpu6502* cpu, struct instruction* ins);
void STA(struct cpu6502* cpu, struct instruction* ins);
void STX(struct cpu6502* cpu, struct instruction* ins);
void STY(struct cpu6502* cpu, struct instruction* ins);

#ifdef __cplusplus
}
#endif

#endif

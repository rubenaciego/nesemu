#include <stdio.h>
#include <stdlib.h>
#include <opfuncs6502.h>
#include <nesmachine.h>

void XXX(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->running = 0;
	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void ADC(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val1 = cpu->a;
	uint8_t val2 = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    uint16_t result = (uint16_t)val1 + (uint16_t)get_state_carry(cpu) + (uint16_t)val2;
    cpu->a = result & 0xff;

    set_state_overf(cpu, (((~((uint16_t)val1 ^ (uint16_t)val2) & ((uint16_t)val1 ^ (uint16_t)result)) & 0x0080) != 0));
    set_state_carry(cpu, (result > 0xff));
    set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void AND(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->a &= get_addrmode_val(cpu, ins);
	set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void ASL(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val;
	uint8_t res;

	if (ins->mode == ACC)
	{
		val = cpu->a;
		res = val << 1;
		cpu->a = res;
	}
	else
	{
		uint16_t address = get_addrmode_val(cpu, ins);
		val = get_mem(cpu->nes, address);
		res = val << 1;
		set_mem(cpu->nes, address, res);
	}

	set_state_carry(cpu, (val >> 7));
	set_state_zero(cpu, (res == 0));
	set_state_neg(cpu, ((res >> 7) & 1));

	cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void BCC(struct cpu6502* cpu, struct instruction* ins)
{
	if (get_state_carry(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BCS(struct cpu6502* cpu, struct instruction* ins)
{
	if (!get_state_carry(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BEQ(struct cpu6502* cpu, struct instruction* ins)
{
	if (!get_state_zero(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BMI(struct cpu6502* cpu, struct instruction* ins)
{
	if (!get_state_neg(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BNE(struct cpu6502* cpu, struct instruction* ins)
{
    if (get_state_zero(cpu))
    {
        cpu->wait_cycles = ins->cycles;
    	cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BPL(struct cpu6502* cpu, struct instruction* ins)
{
	if (get_state_neg(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BVC(struct cpu6502* cpu, struct instruction* ins)
{
	if (get_state_overf(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BVS(struct cpu6502* cpu, struct instruction* ins)
{
	if (!get_state_overf(cpu))
    {
        cpu->wait_cycles = ins->cycles;
		cpu->pc += ins->bytes;
    }
    else
    {
        cpu->pc = get_addrmode_val(cpu, ins);
        cpu->wait_cycles = ins->cond_cycles;
    }
}

void BIT(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val = get_mem(cpu->nes, get_addrmode_val(cpu, ins));

	set_state_zero(cpu, ((val & cpu->a) == 0));
	set_state_overf(cpu, ((val >> 6) & 1));
	set_state_neg(cpu, ((val >> 7) & 1));

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void BRK(struct cpu6502* cpu, struct instruction* ins)
{
    push_st_val(cpu, cpu->pc & 0xff);
    push_st_val(cpu, (cpu->pc >> 8) & 0xff);
    push_st_val(cpu, cpu->s);
	
	set_state_brk(cpu, 1);

	cpu->pc = IRQ_VEC;
	cpu->wait_cycles = ins->cycles;
}

void CLC(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_carry(cpu, 0);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void CLD(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_dec(cpu, 0);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void CLI(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_int(cpu, 0);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void CLV(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_overf(cpu, 0);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void NOP(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void PHA(struct cpu6502* cpu, struct instruction* ins)
{
	push_st_val(cpu, cpu->a);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void PLA(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->a = pop_st(cpu);

	set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void PHP(struct cpu6502* cpu, struct instruction* ins)
{
	push_st_val(cpu, cpu->s | (1 << 4));
	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void PLP(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->s = pop_st(cpu);
	set_state_brk(cpu, 0);
	set_state_five(cpu, 1);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void RTI(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->s = pop_st(cpu);
	uint8_t val1 = pop_st(cpu);
    uint8_t val2 = pop_st(cpu);

    cpu->pc = ((val2 << 8) | val1) + 4;
	cpu->wait_cycles = ins->cycles;
}

void RTS(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val1 = pop_st(cpu);
    uint8_t val2 = pop_st(cpu);

    cpu->pc = ((val2 << 8) | val1) + 1;
    cpu->wait_cycles = ins->cycles;
}

void SEC(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_carry(cpu, 1);

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void SED(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_dec(cpu, 1);
	
	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void SEI(struct cpu6502* cpu, struct instruction* ins)
{
	set_state_int(cpu, 1);
	
	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;;
}

void TAX(struct cpu6502* cpu, struct instruction* ins)
{
    cpu->x = cpu->a;
    
    set_state_zero(cpu, (cpu->x == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void TXA(struct cpu6502* cpu, struct instruction* ins)
{
    cpu->a = cpu->x;
    
    set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void TAY(struct cpu6502* cpu, struct instruction* ins)
{
    cpu->y = cpu->a;
    
    set_state_zero(cpu, (cpu->y == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void TYA(struct cpu6502* cpu, struct instruction* ins)
{
    cpu->a = cpu->y;

    set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void TSX(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->x = cpu->sp;

    set_state_zero(cpu, (cpu->x == 0));
    set_state_neg(cpu, ((cpu->x >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void TXS(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->sp = cpu->x;

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void CMP(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    uint8_t res = cpu->a - val;

    set_state_carry(cpu, (cpu->a >= val));
    set_state_zero(cpu, (res == 0));
    set_state_neg(cpu, ((res >> 7) & 1));
	
    cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void CPX(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    uint8_t res = cpu->x - val;

    set_state_carry(cpu, (cpu->x >= val));
    set_state_zero(cpu, (res == 0));
    set_state_neg(cpu, ((res >> 7) & 1));
	
    cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void CPY(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    uint8_t res = cpu->y - val;

    set_state_carry(cpu, (cpu->y >= val));
    set_state_zero(cpu, (res == 0));
    set_state_neg(cpu, ((res >> 7) & 1));
	
    cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void DEC(struct cpu6502* cpu, struct instruction* ins)
{
	uint16_t address = get_addrmode_val(cpu, ins);
	uint8_t res = get_mem(cpu->nes, address) - 1;
	set_mem(cpu->nes, address, res);

	set_state_zero(cpu, (res == 0));
	set_state_neg(cpu, ((res >> 7) & 1));

	cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void DEX(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->x--;
    
    set_state_zero(cpu, (cpu->x == 0));
    set_state_neg(cpu, ((cpu->x >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void DEY(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->y--;
    
    set_state_zero(cpu, (cpu->y == 0));
    set_state_neg(cpu, ((cpu->y >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void INX(struct cpu6502* cpu, struct instruction* ins)
{
    cpu->x++;

    set_state_zero(cpu, (cpu->x == 0));
    set_state_neg(cpu, ((cpu->x >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void INY(struct cpu6502* cpu, struct instruction* ins)
{
    cpu->y++;
    
    set_state_zero(cpu, (cpu->y == 0));
    set_state_neg(cpu, ((cpu->y >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void EOR(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));

	cpu->a ^= val;

	set_state_zero(cpu, (cpu->a == 0));
	set_state_neg(cpu, ((cpu->a >> 7) & 1));

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void INC(struct cpu6502* cpu, struct instruction* ins)
{
	uint16_t address = get_addrmode_val(cpu, ins);
	uint8_t res = get_mem(cpu->nes, address) + 1;
	set_mem(cpu->nes, address, res);

	set_state_zero(cpu, (res == 0));
	set_state_neg(cpu, ((res >> 7) & 1));

	cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void JMP(struct cpu6502* cpu, struct instruction* ins)
{
	cpu->pc = get_addrmode_val(cpu, ins);
	cpu->wait_cycles = ins->cycles;
}

void JSR(struct cpu6502* cpu, struct instruction* ins)
{
    uint16_t address = get_addrmode_val(cpu, ins);
	uint16_t ret_address = cpu->pc + ins->bytes - 1;
	
    push_st_val(cpu, (ret_address >> 8) & 0xff);
    push_st_val(cpu, ret_address & 0xff);

    cpu->pc = address;
    cpu->wait_cycles = ins->cycles;
}

void LDA(struct cpu6502* cpu, struct instruction* ins)
{
    uint8_t value = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    cpu->a = value;
    
    set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void LDX(struct cpu6502* cpu, struct instruction* ins)
{
    uint8_t value = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    cpu->x = value;
    
    set_state_zero(cpu, (cpu->x == 0));
    set_state_neg(cpu, ((cpu->x >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void LDY(struct cpu6502* cpu, struct instruction* ins)
{
    uint8_t value = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    cpu->y = value;
    
    set_state_zero(cpu, (cpu->y == 0));
    set_state_neg(cpu, ((cpu->y >> 7) & 1));

    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void LSR(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val;
	uint8_t res;

	if (ins->mode == ACC)
	{
		val = cpu->a;
		res = val >> 1;
		cpu->a = res;
	}
	else
	{
		uint16_t address = get_addrmode_val(cpu, ins);
		val = get_mem(cpu->nes, address);
		res = val >> 1;
		set_mem(cpu->nes, address, res);
	}

	set_state_carry(cpu, (val & 1));
	set_state_zero(cpu, (res == 0));
	set_state_neg(cpu, ((res >> 7) & 1));

	cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void ORA(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));

	cpu->a |= val;

	set_state_zero(cpu, (cpu->a == 0));
	set_state_neg(cpu, ((cpu->a >> 7) & 1));

	cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void ROL(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val;
	uint8_t res;

	if (ins->mode == ACC)
	{
		val = cpu->a;
		res = val << 1;
		cpu->a = res | get_state_carry(cpu);
	}
	else
	{
		uint16_t address = get_addrmode_val(cpu, ins);
		val = get_mem(cpu->nes, address);
		res = val << 1;
		set_mem(cpu->nes, address, res | get_state_carry(cpu));
	}

	set_state_carry(cpu, (val >> 7));
	set_state_zero(cpu, (res == 0));
	set_state_neg(cpu, ((res >> 7) & 1));

	cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void ROR(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val;
	uint8_t res;

	if (ins->mode == ACC)
	{
		val = cpu->a;
		res = val >> 1;
		cpu->a = res | (get_state_carry(cpu) << 7);
	}
	else
	{
		uint16_t address = get_addrmode_val(cpu, ins);
		val = get_mem(cpu->nes, address);
		res = val >> 1;
		set_mem(cpu->nes, address, res | (get_state_carry(cpu) << 7));
	}

	set_state_carry(cpu, (val & 1));
	set_state_zero(cpu, (res == 0));
	set_state_neg(cpu, ((res >> 7) & 1));

	cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void SBC(struct cpu6502* cpu, struct instruction* ins)
{
	uint8_t val1 = cpu->a;
	uint16_t val2 = ins->mode == IMM ? get_addrmode_val(cpu, ins) : get_mem(cpu->nes, get_addrmode_val(cpu, ins));
    val2 ^= 0x00ff;
	
	uint16_t result = (uint16_t)val1 + (uint16_t)get_state_carry(cpu) + val2;
    cpu->a = result & 0xff;

    set_state_overf(cpu, (((~((uint16_t)val1 ^ (uint16_t)val2) & ((uint16_t)val1 ^ (uint16_t)result)) & 0x0080) != 0));
    set_state_carry(cpu, (result > 0xff));
    set_state_zero(cpu, (cpu->a == 0));
    set_state_neg(cpu, ((cpu->a >> 7) & 1));

    cpu->pc += ins->bytes;
    cpu->wait_cycles = ins->cycles;
}

void STA(struct cpu6502* cpu, struct instruction* ins)
{
    uint16_t address = get_addrmode_val(cpu, ins);
    set_mem(cpu->nes, address, cpu->a);
    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void STX(struct cpu6502* cpu, struct instruction* ins)
{
    uint16_t address = get_addrmode_val(cpu, ins);
    set_mem(cpu->nes, address, cpu->x);
    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

void STY(struct cpu6502* cpu, struct instruction* ins)
{
    uint16_t address = get_addrmode_val(cpu, ins);
    set_mem(cpu->nes, address, cpu->y);
    cpu->pc += ins->bytes;
	cpu->wait_cycles = ins->cycles;
}

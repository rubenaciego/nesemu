
class Instruction:
    
    def __init__(self, opcode, nemonic, addrmode, size, cycles, condcycles, flags):
        self.opcode = opcode
        self.nemonic = nemonic
        self.addrmode = addrmode
        self.size = size
        self.cycles = cycles
        self.condcycles = condcycles
        self.flags = flags

    def print_c(self):
        
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')
        print('opcode = ' + hex(self.opcode) + ';')
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')
        print('bytes = ' + str(self.size) + ';')
        print('strcpy(cpu->instructions[' + hex(self.opcode) + '].nemonic, "' + self.nemonic + '");')
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')
        print('cycles = ' + str(self.cycles) + ';')
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')
        print('cond_cycles = ' + str(self.condcycles) + ';')
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')
        print('mode = ' + self.addrmode + ';')
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')
        print('func = ' + self.nemonic + hex(self.opcode) + ';')
        print('cpu->instructions[' + hex(self.opcode) + '].', end='')

        flag = 0
        for i in range(len(self.flags)):
            if self.flags[i].isupper():
                flag |= 1 << i

        print('flags = ' + bin(flag) + ';')

        print()


def main():
    file = open('6502opcodes.csv', 'r')

    for line in file.readlines():
        line = line.replace('\r\n', '')
        if line[0] != '0':
            continue

        data = line.split(',')
        
        cycles = 0
        condcycles = 0
        st = data[4].split('/')

        if len(st) > 1:
            condcycles = int(st[1])

        cycles = int(st[0])

        ins = Instruction(int(data[0], 16), data[1], data[2], int(data[3]), cycles, condcycles, data[5])
        ins.print_c()
    
    file.close()


if __name__ == '__main__':
    main()

TARTGET = test

AS = nasm
CXX = g++

ASM_FILE = $(wildcard *.asm)
CXX_FILE = $(wildcard *.cpp)

ALL_OBJ += $(ASM_FILE:%.asm=%.o)
ALL_OBJ += $(CXX_FILE:%.cpp=%.o)

run:
	@rm -rf *.o
	@nasm -f elf32 $(ASM_FILE)
	@g++ -m32 -g -c $(CXX_FILE)
	@g++ -m32 -o $(TARTGET) $(ALL_OBJ)
	@./$(TARTGET)
clean:
	@rm -rf *.o
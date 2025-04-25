CC = gcc
CFLAGS = -Wall -std=c11 -O2
LDFLAGS = -lraylib -lm -lpthread -ldl -lX11 -lGL -lGLU
SRCDIR = src
OBJDIR = obj
BINDIR = bin
TARGET = $(BINDIR)/meu_programa

# Encontre todos os arquivos .c no diretório src
SRCS = $(wildcard $(SRCDIR)/*.c)
# Gere os arquivos .o correspondentes
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Regra para garantir que o diretório bin exista
$(shell mkdir -p $(BINDIR))

# Regra para compilar o programa
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Regra para compilar os arquivos .c em .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)

# Regra opcional para instalar o programa
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

.PHONY: clean run install
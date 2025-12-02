NAME = Solution

DAY ?= 2

CXX = g++

CXXFLAGS = -Wall -Werror -Wextra

FIND_DIR = $(shell find . -maxdepth 1 -type d -name "Day $(DAY)*" | sed 's|^\./||')

CURRENT_DAY_DIR = $(FIND_DIR)

all: $(NAME)

$(NAME):
	@if [ ! -f "$(CURRENT_DAY_DIR)/$(NAME)" ] || [ "$(CURRENT_DAY_DIR)/main.cpp" -nt "$(CURRENT_DAY_DIR)/$(NAME)" ]; then \
		echo "📦 Compilando Day $(DAY)"; \
		cd "$(CURRENT_DAY_DIR)" && $(CXX) $(CXXFLAGS) -o $(NAME) main.cpp; \
		echo "✅ Compilación completada: $(CURRENT_DAY_DIR)/$(NAME)"; \
	fi

run: all
	@echo "🚀 Ejecutando Day $(DAY)"
	@cd "$(CURRENT_DAY_DIR)" && ./$(NAME) > result.txt

clean:
	@cd "$(CURRENT_DAY_DIR)" && $(RM) $(NAME)
	@echo "🧹 Limpieza completada"

re: clean all

.PHONY: all run clean re
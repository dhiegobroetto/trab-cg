CC = g++ -std=c++11
DOMAIN_FILES = main.cpp circulo.cpp linha.cpp jogador.cpp arena.cpp
TINYXML_FOLDER = tinyxml
TINYXML_FILES = $(TINYXML_FOLDER)/tinyxml.cpp 		\
				$(TINYXML_FOLDER)/tinyxmlparser.cpp \
				$(TINYXML_FOLDER)/tinyxmlerror.cpp 	\
				$(TINYXML_FOLDER)/tinystr.cpp
OUTPUT_FILE = trabalhocg
FLAGS = -lGL -lGLU -lglut -lm

all: g++
	@echo "Compilado. Agora execute o código com ./trabalhocg <caminho do config.xml>"

g++:
	@$(CC) $(DOMAIN_FILES) $(TINYXML_FILES) -o $(OUTPUT_FILE) $(FLAGS)

run:
	@./$(OUTPUT_FILE)

clean:
	@rm -f $(OUTPUT_FILE)
